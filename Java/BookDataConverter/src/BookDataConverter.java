import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class BookDataConverter {

	public static void main(String[] args) {
		String inputFileName = args[0];
		String outputFormat = args[1];

		FileConverter cc = new FileConverter(inputFileName, outputFormat);
		cc.convertFile();
	}
}
