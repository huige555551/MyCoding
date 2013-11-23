package sftp_test;

import com.jcraft.jsch.*;
import com.jcraft.jsch.ChannelSftp.LsEntry;
import java.sql.*;
import java.util.Vector;
import java.util.logging.Level;

public class SFTPFileLoader
{
    static Connection conn = null;

    static String username=null;
    static String password=null;
    static String host=null;
    static int port=22;

    static String localDirectory=null;
    static String serverDirectory=null;
    static String processedDirectory = null;
    static ChannelSftp sftpChannel=null;
    static Session session=null;

    static int totalFileCount=0;
    static int downloadedFileCount=0;

    static String logMessage="";
    static String errorMessage="";

    static Vector IVRSTrialList;

    static void setProperties(String serverDirectory,String localDirectory,String username,String password, String host,int port)
    {
        SFTPFileLoader.username=username;
        SFTPFileLoader.password=password;
        SFTPFileLoader.host=host;
        SFTPFileLoader.port=port;
        SFTPFileLoader.localDirectory=localDirectory;
        SFTPFileLoader.serverDirectory=serverDirectory;
        SFTPFileLoader.processedDirectory = "processed";
        sftpChannel=null;
        session=null;

        totalFileCount=0;
        downloadedFileCount=0;

        logMessage="";
        errorMessage="";

        IVRSTrialList = new Vector();

        try
        {
            conn=DriverManager.getConnection("jdbc:default:connection:");
        }
        catch(Exception e)
        {
            System.out.println("Database Connection Error in setProperties() -> " + e.toString());
            errorMessage += "Database Connection Error in setProperties() -> " + e.toString() + "\n";
        }
    }

    static boolean getConnection(String username,String password, String host,int port)
    {
        try
        {
            JSch jsch=new JSch();

            session=jsch.getSession(username,host,port);

            UserInfo ui=new MyUserInfo();
            session.setUserInfo(ui);
            MyUserInfo temp=(MyUserInfo)ui;

            temp.setPassword(password);

            session.connect();

            Channel channel=session.openChannel("sftp");
            channel.connect();
            SFTPFileLoader.sftpChannel=(ChannelSftp)channel;

            return true;

        }
        catch(Exception e)
        {
            System.out.println(e);
            errorMessage += e.toString();
        }

        return false;
    }

    static void downloadAllFiles(String fileType)
    {
        try
        {
            java.util.Vector fileList=sftpChannel.ls(".");
            if(fileList!=null)
            {
                for(int ii=0; ii<fileList.size(); ii++)
                {
                    Object obj=fileList.elementAt(ii);
                    LsEntry lsentry = (com.jcraft.jsch.ChannelSftp.LsEntry)obj;

                    if(obj instanceof com.jcraft.jsch.ChannelSftp.LsEntry)
                    {
                        String fileName=((com.jcraft.jsch.ChannelSftp.LsEntry)obj).getFilename();
                        if(fileType.equals(".*"))
                        {
                            if( !(lsentry.getAttrs().isDir()) )
                            {
                                boolean valid = checkFileName(fileName);
                                if(valid)
                                {
                                    totalFileCount++;
                                    downloadFileByName(fileName);
                                }
                            }
                        }
                        else if(fileName.toLowerCase().endsWith(fileType))
                        {
                            boolean valid = checkFileName(fileName);
                            if(valid)
                            {
                                totalFileCount++;
                                downloadFileByName(fileName);
                            }
                        }
                    }
                }
            }
        }
        catch(Exception e)
        {
            System.out.println("Exception in downloadAllFiles(): " + e.toString());
            errorMessage += "Exception in downloadAllFiles(): " + e.toString() + "\n";
        }
    }

    static boolean checkFileName(String fileName)
    {
        int index = 0;
        String trial = null;

        try
        {
            index = fileName.indexOf('_', 0);

            if(index>0)
            {
                trial = fileName.substring(0,index);
            }

            if(IVRSTrialList.contains(trial))
                return true;
        }
        catch(Exception e)
        {
            System.out.println("Exception in checkFileName(" + fileName + "): " + e.toString());
            errorMessage += "Exception in checkFileName(" + fileName + "): " + e.toString() + "\n";
        }

        return false;
    }

    static void downloadFileByName(String filename)
    {
        try
        {
            System.out.println("Downloading file : " + filename);
            int mode=ChannelSftp.OVERWRITE;
            sftpChannel.get(filename, localDirectory, null, mode);
            downloadedFileCount++;
            System.out.println("Download Completed.");

            //file moving to processed folder
            moveFileToProcessedFolder(filename);
        }
        catch(SftpException e)
        {
            System.out.println("Exception in downloadFileByName("+ filename +"): " + e.toString());
            errorMessage += "Exception in downloadFileByName("+ filename +"): " + e.toString() + "\n";
        }
        catch(Exception e)
        {
            System.out.println("Exception in downloadFileByName("+ filename +"): " + e.toString());
            errorMessage += "Exception in downloadFileByName("+ filename +"): " + e.toString() + "\n";
        }
    }

    private static void moveFileToProcessedFolder(String fileName)
    {
        try
        {           
            String newPath = processedDirectory + "/" +fileName;
            sftpChannel.rename(fileName, newPath);
            System.out.println("File moved to processed folder");
        }
        catch (Exception e)
        {
            System.out.println("Exception in moveFile("+ fileName +"): " + e.toString());
            errorMessage += "Exception in moveFile("+ fileName +"): " + e.toString() + "\n";
        }
    }

    private static boolean isDirecotryExist(String processedDirectory) 
    {
        try
        {
            java.util.Vector fileList=sftpChannel.ls(".");
            if(fileList!=null)
            {
                for(int ii=0; ii<fileList.size(); ii++)
                {
                    Object obj=fileList.elementAt(ii);
                    LsEntry lsentry = (com.jcraft.jsch.ChannelSftp.LsEntry)obj;

                    if(obj instanceof com.jcraft.jsch.ChannelSftp.LsEntry)
                    {
                        String fileName=((com.jcraft.jsch.ChannelSftp.LsEntry)obj).getFilename();
                        if(fileName.equals(processedDirectory))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        catch(Exception e)
        {
            System.out.println("Exception in isDirecotryExist(): " + e.toString());
            errorMessage += "Exception in isDirecotryExist(): " + e.toString() + "\n";
        }
        return false;
    }

    private static boolean goToServerDirectory()
    {
        try
        {
            System.out.println("Accessing ServerDirectory : " + serverDirectory);
            sftpChannel.cd(serverDirectory);
            System.out.println("Accessing ServerDirectory Completed.");
            return true;
        }
        catch(Exception e)
        {
            System.out.println("Exception in goToServerDirectory("+ serverDirectory +"): " + e.toString());
            errorMessage += "Exception in goToServerDirectory("+ serverDirectory +"): " + e.toString() + "\n";
        }

        return false;
    }

    static void disconnectFromSFTP()
    {
        try
        {
            session.disconnect();
        }
        catch (Exception e)
        {
            errorMessage += "Exception in loadFilesFromSFTP(exception during disconnecting): " + e.toString() + "\n";
        }
    }

    static void errorMessageFurnishing()
    {
        if (errorMessage.length() < 1900)
        {
            errorMessage = errorMessage.substring(0, errorMessage.length());
        }
        else
        {
            errorMessage = errorMessage.substring(0, 1900);
        }
    }

    private static String[] splitHostNameAndDirectory(String serverPath)
    {
        String[] str=new String[2];

        try
        {
           int index = serverPath.indexOf("/", 0);

           if(index > 0)
           {
               str[0] = serverPath.substring(0, index);
               str[1] = serverPath.substring(index+1, serverPath.length());

               if(str[1].equals(""))
                   str[1]=".";
           }
           else
           {
                str[0] = serverPath;
                str[1] = ".";
           }
        }
        catch(Exception e)
        {
            System.out.println("Exception in splitHostNameAndDirectory("+ serverPath +"): " + e.toString());
            errorMessage += "Exception in splitHostNameAndDirectory("+ serverPath +"): " + e.toString() + "\n";
        }

        return str;
    }

    private static void getIVRSTrialList()
    {
        Statement stmt = null;

        try
        {
            //Class.forName("oracle.jdbc.driver.OracleDriver");
            //conn = DriverManager.getConnection("jdbc:oracle:thin:@162.44.191.17:1521:odt01", "impact_admin", "august");
            stmt = conn.createStatement();

            ResultSet rset = stmt.executeQuery("select t.trial_alias_code from ip_tr_item ti, trial t where t.trial_no=ti.trial_no and ti.item_code='IVRS_DOWNLOAD' and ti.item_value='Y'");

            while (rset.next())
            {
                IVRSTrialList.add(rset.getString(1));
                System.out.println (rset.getString(1));
            }
        }
        catch (Exception e)
        {
            System.out.println("Exception in getIVRSTrialList(): " + e.toString());
            errorMessage += "Exception in getIVRSTrialList(): " + e.toString() + "\n";
        }
        finally
        {
            try
            {
                stmt.close();
            }
            catch(Exception e)
            {
                System.out.println("Statement close error in getIVRSTrialList() -> " + e.toString());
                errorMessage += "Statement close error in getIVRSTrialList() -> " + e.toString() + "\n";
            }

            //try{
            //    conn.close();
            //} catch (SQLException ex) {
            //    java.util.logging.Logger.getLogger(SFTPFileLoader.class.getName()).log(Level.SEVERE, null, ex);
            //}
        }
    }

    public static String loadFilesFromSFTP(String fileName,String localDirectory,String username,String password, String serverPath,int port) throws Exception
    {
        int i =1;

        if(i==1) throw new Exception();

        try
        {
            String[] strArray=splitHostNameAndDirectory(serverPath);

            if(! ( (strArray[0].length()>0) && (strArray[1].length()>0)) )
            {
                return "F+Invalid server path.+" + "Error Occurred in loadFilesFromSFTP(): "+ errorMessage;
            }

            String strHost = strArray[0];
            String strServerDirectory = strArray[1];

            setProperties(strServerDirectory,localDirectory,username,password, strHost,port);

            boolean validConnection = getConnection(username,password,strHost,port);
 
            if(validConnection)
            {
                boolean isAccessible = goToServerDirectory();

                if(isAccessible)
                {
                    if(!isDirecotryExist(processedDirectory))
                        sftpChannel.mkdir(processedDirectory);

                   
                    getIVRSTrialList();

                    if(fileName.matches("\\x2A\\x2E(([\\p{Alnum}]{3,4})|(\\x2A))")) //pattern for [*.txt] or [*.html]  // [*->42(Ox2A) and .->46(Ox2E)]
                    {
                        int dotPos = fileName.toLowerCase().lastIndexOf('.', fileName.length());
                        String fileType = fileName.toLowerCase().substring(dotPos, fileName.length());
                        downloadAllFiles(fileType);
                    }
                    else
                    {
                        totalFileCount = 1;
                        downloadFileByName(fileName);
                    }
                }

                disconnectFromSFTP();

                errorMessageFurnishing();

                if( (totalFileCount == 0) && (downloadedFileCount == 0) )
                {
                    logMessage = "T+"+ "Server has no files to download.+" + errorMessage;
                }
                else if(totalFileCount != downloadedFileCount)
                {
                    logMessage = "T+"+ downloadedFileCount + " file(s) downloaded out of " + totalFileCount + " files.+" + errorMessage;
                }
                else if(totalFileCount == downloadedFileCount)
                {
                    logMessage = "T+Successfully " + downloadedFileCount + " file(s) downloaded.+" + errorMessage;
                }
            }
            else
            {
                logMessage = "F+Connection Error Occurred.+" + errorMessage;
            }

            return logMessage;

        }
        catch(Exception e)
        {
            disconnectFromSFTP();
            System.out.println("Exception in loadFilesFromSFTP(): " + e.toString());
            errorMessage += "Exception in loadFilesFromSFTP(): " + e.toString();
            return "F+Error Occurred in loadFilesFromSFTP()+" + errorMessage;
        }

    }

    public static void main(String args[])
    {
        try {
            String temp;
            temp = loadFilesFromSFTP("*.txt", "D:\\testing", "unixbox", "25May2010", "localhost/a/b", 22);
            System.out.println("temp = " + temp + "\n");
        } catch (Exception ex) {
            java.util.logging.Logger.getLogger(SFTPFileLoader.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    static class MyUserInfo implements UserInfo
    {
        String passwd;

        public String getPassword()
        {
            return passwd;
        }

        public void setPassword(String password)
        {
            passwd=password;
        }

        public boolean promptYesNo(String str)
        {
          return true;
        }

        public String getPassphrase()
        {
            return null;
        }

        public boolean promptPassphrase(String message)
        {
            return true;
        }

        public boolean promptPassword(String message)
        {
            return true;
        }

        public void showMessage(String message)
        {
            System.out.print(message);
        }
    }

}



//        errorMessage="Hello World";
//
//        if(errorMessage.length() < 5)
//        {
//            errorMessage = errorMessage.substring(0, errorMessage.length());
//        }
//        else
//        {
//            errorMessage = errorMessage.substring(0, 5);
//        }
//        System.out.println(errorMessage);

        //\\x2A\\x2E[a-zA-Z][a-zA-Z][a-zA-Z][a-zA-Z]?
//        Pattern p = Pattern.compile("\\x2A\\x2E(([\\p{Alnum}]{3,4})|(\\x2A))");
//        Matcher m = p.matcher("*.mp3");
//        boolean b = m.matches();
//        Matcher n = p.matcher("*.*");
//        boolean c = m.matches();



//String temp1=loadFilesFromSFTP("*.pdf","D:\\testing", "unixbox", "25May2010", "localhost", 22);
        //System.out.println("temp1 = "+ temp1 + "\n");
        //String temp2=loadFilesFromSFTP("1-4-2010.txt","D:\\testing", "unixbox", "25May2010", "localhost", 22);
        //System.out.println("temp2 = "+ temp2 + "\n");
        //String temp3=loadFilesFromSFTP("*.*","D:\\testing", "unixbox", "25May2010", "localhost\\incoming", 22);
        //System.out.println("temp3 = "+ temp3 + "\n");