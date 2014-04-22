
public class FileConverter {
	private ConvertInterface converter;
	private String inputFileName;
	private String outputFormat;
	
	public FileConverter(String fileName, String format) {
		this.inputFileName = fileName;
		this.outputFormat = format;
	}
	
	public void convertFile() {
		this.converter = getConverter();
		converter.convert(inputFileName, outputFormat);
	}
	
	public ConvertInterface getConverter() {
		
		String guessFormat = UtilityClass.guessTextFormat(inputFileName);
		
		if(guessFormat.equals("txt") && outputFormat.equals("xml")){
			return new ConvertText2Xml();
		}
		else if(guessFormat.equals("xml") && outputFormat.equals("txt")){
			return new ConvertXml2Text();
		}
		else if(guessFormat.equals("txt") && outputFormat.equals("json")){
			return new ConvertText2Json();
		}
		else if(guessFormat.equals("json") && outputFormat.equals("txt")){
			return new ConvertJson2Text();
		}
		else return null;
	}

	public String getInputFileName() {
		return inputFileName;
	}

	public String getOutputFormat() {
		return outputFormat;
	}
}
