import java.util.ArrayList;

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
}
