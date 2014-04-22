import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;


public class UtilityClass {
	
	public static String getFileFormat(String fileName) {
		int index = fileName.lastIndexOf('.');
		String format = fileName.substring(index+1);
		return format;
	}
	
	public static String getFileName(String inputFileName) {
		int index = inputFileName.lastIndexOf('.');
		String fileName = inputFileName.substring(0, index);
		return fileName;
	}
	
	public static InputStream createInputStream(ArrayList<String> lines) throws UnsupportedEncodingException {
		StringBuilder str = new StringBuilder();
		for(String s: lines) str.append(s);
		InputStream stream = new ByteArrayInputStream(str.toString().getBytes("UTF-8"));
		return stream;
	}
	
	public static String createString(ArrayList<String> lines) {
		StringBuilder str = new StringBuilder();
		for(String s: lines) str.append(s + "\n");
		return str.toString();
	}
	
	public static String guessTextFormat(String fileName) {
		
		try (BufferedReader br = new BufferedReader(new FileReader(fileName))) { 
			String sCurrentLine;
 
			while ((sCurrentLine = br.readLine()) != null) {
				sCurrentLine = sCurrentLine.trim();
				if(sCurrentLine.isEmpty()) continue;
				
				if((sCurrentLine.charAt(0) >= 'a' && sCurrentLine.charAt(0) <= 'z') || 
				   (sCurrentLine.charAt(0) >= 'A' && sCurrentLine.charAt(0) <= 'Z')) {
					System.out.println("Guessing text format...");
					return "txt";
				}
				else if(sCurrentLine.startsWith("<?xml")){
					System.out.println("Guessing xml format...");
					return "xml";
				}
				else if(sCurrentLine.charAt(0)=='{'){
					System.out.println("Guessing json format...");
					return "json";					
				}
				else{
					String inputFormat = getFileFormat(fileName);
					System.out.println("Normal guessing is not working...");
					System.out.printf("Guessing %s from file name...", inputFormat);
					return inputFormat;
				}
			} 
		} catch (IOException e) {
			e.printStackTrace();
		}		
		return null; 		
	}
	
	public static String trim(String s) {
		return s.replace(String.valueOf((char) 160), " ").trim();
	}
	
	public static ArrayList<String> string2ArrayList(StringBuilder strBuilder2) {
		ArrayList<String> newLines = new ArrayList<String>();
		String[] strArray = strBuilder2.toString().split("\n");
		for(String s: strArray){
			if(!s.isEmpty())
				newLines.add(s);
		}
		return newLines;
	}

}
