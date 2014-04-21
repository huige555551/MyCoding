import java.util.ArrayList;


public class ConvertText2Xml implements ConvertInterface{

	public void convert(String inputFileName, String outputFormat) {
		
		System.out.println("Reading input...");
		System.out.println("++++");
		
		TextFile t = new TextFile();
		t.read(inputFileName);
		t.display();
		
		System.out.println("----");
		
		String guessFormat = UtilityClass.guessTextFormat(inputFileName);
		System.out.printf("Book data is in %s format\n", guessFormat);
		System.out.printf("Converting to %s format\n", outputFormat);
		
		System.out.println("Here is the output...");
		System.out.println("++++");
		
		ArrayList<String> str = t.convert2Xml();
		XmlFile x = new XmlFile(str);
		x.display();
		//x.writeInFile(UtilityClass.getFileName(inputFileName));
		
		System.out.println("----");
	}
		
}