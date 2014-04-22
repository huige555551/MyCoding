import java.util.ArrayList;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.JSONValue;


public class JsonFile extends GeneralFile{
	
	public JsonFile(){}
	
	public JsonFile(ArrayList<String> str) {
		super(str);
	}
	
	@Override
	public boolean writeInFile(String fileName) {
		fileName += ".json";
		return super.writeInFile(fileName);		
	}
	
	public ArrayList<String> convert2Text() {
		
		String s = UtilityClass.createString(lines);
		
		ArrayList<String> outStr = new ArrayList<String>();
		
		JSONObject obj = (JSONObject) JSONValue.parse(s);
		obj = (JSONObject) obj.get("book");
		outStr.add("name: " + obj.get("name"));
		
		String temp = "authors: ";
		JSONArray arr = (JSONArray) obj.get("authors");
		for(int i1=0; i1<arr.size(); i1++) { 
			temp += arr.get(i1);
			if(i1!=arr.size()-1) temp += ", ";
		}
		outStr.add(temp);
		outStr.add("publishedDate: " + obj.get("publishedDate"));
		
		return outStr;
	}
}
