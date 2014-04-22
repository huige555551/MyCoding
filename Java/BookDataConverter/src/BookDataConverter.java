


public class BookDataConverter {

	public static void main(String[] args) {
		String inputFileName = args[0];
		String outputFormat = args[1];

		FileConverter cc = new FileConverter(inputFileName, outputFormat);
		cc.convertFile();
	}
}
