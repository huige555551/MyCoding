
public class FileConverter {
	private ConvertInterface converter;
	private String inputFileName;
	private String outputFormat;
	
	public FileConverter(){}
	
	public FileConverter(ConvertInterface converter, String fileName, String format) {
		setConverter(converter);
		setInputFileName(fileName);
		setOutputFormat(format);
	}
	
	public void convertFile() {
		converter.convert(inputFileName, outputFormat);
	}

	public ConvertInterface getConverter() {
		return converter;
	}

	public void setConverter(ConvertInterface converter) {
		this.converter = converter;
	}

	public String getInputFileName() {
		return inputFileName;
	}

	public void setInputFileName(String inputFileName) {
		this.inputFileName = inputFileName;
	}

	public String getOutputFormat() {
		return outputFormat;
	}

	public void setOutputFormat(String outputFormat) {
		this.outputFormat = outputFormat;
	}	
}
