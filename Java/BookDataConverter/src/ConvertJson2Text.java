import java.util.ArrayList;


public class ConvertJson2Text implements ConvertInterface{

	public void convert(String inputFileName, String outputFormat) {
		
		System.out.println("Reading input...");
		System.out.println("++++");
		
		JsonFile x = new JsonFile();
		x.read(inputFileName);
		x.display();
		
		System.out.println("----");
		
		String guessFormat = UtilityClass.guessTextFormat(inputFileName);
		System.out.printf("Book data is in %s format\n", guessFormat);
		System.out.printf("Converting to %s format\n", outputFormat);
		
		System.out.println("Here is the output...");
		System.out.println("++++");
		
		ArrayList<String> str = x.convert2Text();
		TextFile t = new TextFile(str);
		t.display();
		//t.writeInFile(UtilityClass.getFileName(inputFileName));
		
		System.out.println("----");
	}
		
}