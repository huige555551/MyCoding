package fileReader;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileFilter;
import java.io.FileReader;
//import oracle.jdbc.*;
import java.sql.*;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.Date;

public class IVRSDataProcessor
{
    static Connection conn = null;
    static String localDirectory = null;
    static String movingDirectoryGood = null;
    static String movingDirectoryBad = null;
    static String dataSourceId = null;
    static long execution_no = 0;

    static String logMessage = null;
    static String errorMessage = null;
    static String badQueryList = null;
    static String emailMessage = "";

    static int goodFileCounter = 0;
    static int badFileCounter = 0;

    static int totalRowCount = 0;
    static int enteredRowCount = 0;

    static void setProperties(String localDir,String goodDir,String badDir,String dataSource,long exec_no)
    {
        localDirectory = localDir;
        movingDirectoryGood = goodDir;
        movingDirectoryBad = badDir;
        dataSourceId = dataSource;
        execution_no = exec_no;
        emailMessage="";
        goodFileCounter = 0;
        badFileCounter = 0;

        try
        {
            conn=DriverManager.getConnection("jdbc:default:connection:");
        }
        catch(Exception e)
        {
            emailMessage += "Database Connection Error in setProperties() -> " + e.toString() + "\n\n";
        }
    }

    static void readFileByName(String fileName)
    {
        logMessage = "";
        errorMessage = "";
        badQueryList = "";
        totalRowCount = 0;
        enteredRowCount = 0;

        try
        {
            boolean valid = true;
            String line;
            File fileObj = new File(fileName);

            if (fileObj.length() < 1)
            {
                valid = false;
                badFileCounter++;
                logMessage = "Invalid file format.\n";
            }

            BufferedReader bufferedReader = new BufferedReader(new FileReader(fileObj));

            while ((line=bufferedReader.readLine())!=null)
            {
                String data[] = line.split("\t");
                valid=validationCheck(data);

                if(!valid)
                {
                    badFileCounter++;
                    logMessage = "Invalid file format. \n";
                    break;
                }
            }
            bufferedReader.close();

            if(valid)
            {
                goodFileCounter++;
                logMessage = "Valid file format. \n";
                loadFileData(fileName);
            }

            moveFile(fileName,valid);

            logEvent(fileName,valid);
        }
        catch(Exception e)
        {
            errorMessage += "\tError in readFileByName() -> " + e.toString() + "#";
        }
    }

    static void loadFileData(String fileName)
    {
        BufferedReader bufferReader = null;

        try
        {
            bufferReader = new BufferedReader(new FileReader(fileName));
            boolean errorOccurred = false;
            String line;
            //conn=DriverManager.getConnection("jdbc:default:connection:");

            while ((line=bufferReader.readLine())!=null)
            {
                totalRowCount++;
                String data[] = line.split("\t");
                String query=buildQuery(data);

                Statement stmt = null;
                try
                {
                    stmt=conn.createStatement();
                    stmt.execute(query);
                    enteredRowCount++;
                }
                catch(Exception e)
                {
                    errorOccurred = true;
                    badQueryList += query + "\n";
                    errorMessage += "\tStatement error in loadFileData() -> " + e.toString() + "#";
                }
                finally
                {
                    try
                    {
                        stmt.close();
                    }
                    catch(Exception e)
                    {
                        errorMessage += "\tStatement close error in loadFileData() -> " + e.toString() + "#";
                    }
                }
            }
            //bufferReader.close();

            if(errorOccurred)
            {
                logMessage += "Could not insert all rows into ip_enrollment_external. Inserted " + enteredRowCount + " row(s) out of " + totalRowCount + " row(s).\n";
            }
            else
            {
                logMessage += "All row(s) inserted successfully into ip_enrollment_external. Row count: " + totalRowCount + ". \n";
            }
        }
        catch (Exception e)
        {
            errorMessage += "\tError in loadFileData() -> " + e.toString()+"#";
        }
        finally
        {
            try
            {
                bufferReader.close();
            }
            catch (Exception e)
            {
                errorMessage += "\tError in loadFileData() -> BufferReader error -> " + e.toString()+"#";
            }
        }
    }

    static void moveFile(String fileName,boolean valid)
    {
        try
        {
            Date date = new Date();
            SimpleDateFormat sdf=new SimpleDateFormat("yy.MM.dd");
            String dateString = sdf.format(date);

            File file=new File(fileName);
            String newFileName = "";
            boolean success=true;

            if(valid==true)
            {
                File dir=new File(movingDirectoryGood);
                newFileName= dateString + "_" +file.getName();
                success = file.renameTo(new File(dir, newFileName));
            }
            else
            {
                File dir=new File(movingDirectoryBad);
                newFileName= dateString + "_" + file.getName();
                success = file.renameTo(new File(dir, newFileName));
            }

            if(success)
            {
                logMessage += "File has been moved to " + (valid == true ? movingDirectoryGood : movingDirectoryBad) + " and renamed as " + newFileName + ".";
            }
            else
            {
                logMessage += "File cannot be moved to " + (valid == true ? movingDirectoryGood : movingDirectoryBad) + ". The file might already exists in destination.";
                errorMessage += "\tFile cannot be moved. The file might already exists in destination.#";
            }
        }
        catch(Exception e)
        {
            errorMessage += "\tError in movieFile(): " + e.toString()+"#";
        }
    }

    static boolean validationCheck(String data[])
    {
        if(data.length!=18) return false;

        return true;
    }

    static String buildQuery(String[] data)
    {

        StringBuffer query=new StringBuffer("INSERT INTO ip_enrollment_external(TRIAL_ALIAS_CODE,TRIAL_UNIT_REFERENCE,STATUS_DATE,ENTERED_SCREENING,WITHDRAWN_SCREENING," +
                                             "COMPLETED_SCREENING,ENTERED_BASELINE,WITHDRAWN_BASELINE,COMPLETED_BASELINE,ENTERED_TREATMENT , DISCONTINUED_TREATMENT ," +
                                             "WITHDRAWN_TREATMENT,COMPLETED_TREATMENT ,ENTERED_FOLLOWUP ,WITHDRAWN_FOLLOWUP,COMPLETED_FOLLOWUP , REMARK , ENTERED_BY ) VALUES (");

        for (int i = 0; i < data.length; i++)
        {
            if(i==2)
            {
                query.append("TO_DATE(");
                query.append("'");
                query.append(data[i]);
                query.append("','DD.MM.YY')");
            }
            else
            {
                query.append("'");
                query.append(data[i]);
                query.append("'");
            }

            if(i==17)
                query.append(")");
            else
                query.append(",");
        }
        return query.toString();
    }

    public static String processData(String localDir,String goodDir,String badDir,String dataSourceId,long execution_no)
    {
        try
        {
            setProperties(localDir,goodDir,badDir,dataSourceId,execution_no);           

            try
            {
                    File directory = new File(localDirectory);
                    File[] files = directory.listFiles(new Filter());

                    for (int index=0; index<files.length; index++)
                    {
                        readFileByName(files[index].toString());
                    }
            }
            catch(Exception e)
            {
                    System.out.println("Error in IVRSDataProcessor.processData(): Invalid directory location. Please Check the IVRS incoming directory. " + e.toString());
                    errorMessage += "\nError in IVRSDataProcessor.processData(): Invalid directory location. Please Check the IVRS incoming directory. " + e.toString();
            }           

            SimpleDateFormat sdf = new SimpleDateFormat("dd-MMM-yyyy hh:mm");

            emailMessage = "**Automatic IVRS Load Summary**\n\n" +
                           "Total File(s): " + (goodFileCounter + badFileCounter) + "\n" +
                           "Processed File(s): " + goodFileCounter + "\n" +
                           "Bad File(s) : " + badFileCounter + "\n\n" ;

            System.out.println("EMAIL:\n" + emailMessage);

            return emailMessage;
        }
        catch(Exception e)
        {
            System.out.println("Error in IVRSDataProcessor.processData(): " + e.toString());
            emailMessage += "\nError in IVRSDataProcessor.processData(): " + e.toString();
        }

        return emailMessage;
    }

    private static void logEvent(String fileName, boolean valid)
    {
        Set set = new HashSet(Arrays.asList(errorMessage.split("#")));
        String distinctError[] = (String [])set.toArray(new String[set.size()]);

        errorMessage = "";
        for(int i=0; i<distinctError.length; i++)
        {
            errorMessage += distinctError[i] + "\n";
        }

        errorMessage += badQueryList;

        String query = "INSERT INTO ip_ivrs_log (MSG_NO, DATA_SOURCE_ID, EXECUTION_NO, FILE_NAME, LOG_MESSAGE, ERROR_MESSAGE) " +
                "VALUES (IP_IVRS_LOG_SEQ.nextval," + "'" + dataSourceId + "'," + execution_no + "," + "'" + fileName + "'," + "'" + logMessage + "'," + "'" + errorMessage + "')";

        try
        {
            Statement stmt = null;
            try
            {
                stmt = conn.createStatement();
                stmt.execute(query);
            }
            catch(Exception e)
            {
                errorMessage += "\tStatement error in logEvent() -> " + e.toString()+"#\n";
            }
            finally
            {
                stmt.close();
            }
        }
        catch(Exception e)
        {
            errorMessage += "\tError in logEvent() -> " + e.toString() + "#\n";
        }
        //make message for email
        //emailMessage += "# " + fileName + "\n" +
        //logMessage +  "\n" +
        //(errorMessage.equals("\n") ? "" : "\tDetail Error:\n" + errorMessage); // + "\n"  +
        //(valid==true ? enteredRowCount + " rows of data inserted out of " + totalRowCount + " rows." + "\n" : "")+
        //(enteredRowCount < totalRowCount? "Following insertion created problems : \n" + badQueryList + "\n" : "" ) ;
    }

    static class Filter implements FileFilter
    {
        public boolean accept(File file)
        {
            if(file.getName().toLowerCase().endsWith(".txt"))
                return true;

            return false;
        }
    }

    public static void main(String args[])
    {
        String s = "";
        s = s.substring(0, 10);

        Date date = new Date();
        SimpleDateFormat sdf=new SimpleDateFormat("dd-MMM-yy HH:MM");
        System.out.println(sdf.format(date));
        String str = processData("D:\\testing","D:\\testing\\good","D:\\testing\\bad","SFTP_TEST",100);
    }
}