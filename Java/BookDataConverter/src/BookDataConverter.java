import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class BookDataConverter {
	
	public static ConvertInterface getFileConverter(String inputFileName, String outputFormat) {
		String guessFormat = UtilityClass.guessTextFormat(inputFileName);
		
		if(guessFormat.equals("txt") && outputFormat.equals("xml")){
			return new ConvertText2Xml();
		}
		else if(guessFormat.equals("xml") && outputFormat.equals("txt")){
			return new ConvertXml2Text();
		}
		else return null;
	}

	public static void main(String[] args) {
		String inputFileName = args[0];
		String outputFormat = args[1];

		ConvertInterface ci = getFileConverter(inputFileName, outputFormat);
		FileConverter cc = new FileConverter(ci, inputFileName, outputFormat);
		cc.convertFile();
	}

}
