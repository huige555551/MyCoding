import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;
import java.io.StringWriter;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.JSONValue;

public class TextFile extends GeneralFile {
	
	public TextFile() {}
	
	public TextFile(ArrayList<String> str) {
		super(str);
	}
	
	@Override
	public boolean writeInFile(String fileName) {
		fileName += ".txt";
		return super.writeInFile(fileName);		
	}
	
	public void appendISBN(String inputFileName, String isbn) {
		ArrayList<String> newLines = new ArrayList<>();
		newLines.add("ISBN: u9348984995898493");
		for(String s: lines) newLines.add(s);
		lines = newLines;
		
		this.writeInFile(inputFileName);
	}
	
	public ArrayList<String> convert2Xml()
	{
		ArrayList<String> newLines = new ArrayList<>();
		
		newLines.add("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
		newLines.add("<book xmlns:b=\"http://example.com/programmin/text/book\">");
		for(String s: lines) {
			String head = UtilityClass.trim(s.substring(0, s.indexOf(":")));
			String body = UtilityClass.trim(s.substring(s.indexOf(":")+1));
			
			if(head.compareTo("authors")==0) {
				newLines.add(" <authors>");
				String[] items = body.split(",");
				for(String i: items) {
					newLines.add("  <author>" + UtilityClass.trim(i) + "</author>");
				}
				newLines.add(" </authors>");
			} else {
				newLines.add(" <"+head+">" + body + "</"+head+">");				
			}
		}
		newLines.add("</book>");
		
		return newLines;
	}
	
	public ArrayList<String> convert2Json() {
		
		ArrayList<String> strArray = new ArrayList<String>();
		strArray.add("{");
		strArray.add(" \"book\": {");
		
		int i = 0;
		for(String s: lines) {
			String head = UtilityClass.trim(s.substring(0, s.indexOf(":")));
			String body = UtilityClass.trim(s.substring(s.indexOf(":")+1));
			
			StringBuilder sb = new StringBuilder();
			sb.append("  \"" + head + "\": ");
					
			if(head.compareTo("authors")==0) {
				
				sb.append("[");
				
				String[] items = body.split(",");
				int j = 0;
				for(String item: items) {
					sb.append("\"" + UtilityClass.trim(item) + "\"");
					if(j!=items.length-1) sb.append(", ");
					j++;
				}
				sb.append("]");
			} else {
				sb.append("\"" + body + "\"");				
			}
			if(i!=lines.size()-1) sb.append(",");
			strArray.add(sb.toString());
			i++;
		}
		
		strArray.add(" }");
		strArray.add("}");
				         	
		return strArray;
	}
}
