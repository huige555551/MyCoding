import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public abstract class GeneralFile {
	protected ArrayList<String> lines;
	
	public GeneralFile(){
		lines = new ArrayList<>();		
	}
	public GeneralFile(ArrayList<String> lines){
		this.lines = lines;
	}
	
	public ArrayList<String> read(String fileName) {
		lines.clear();
		try (BufferedReader br = new BufferedReader(new FileReader(fileName)))
		{
			String sCurrentLine;
 
			while ((sCurrentLine = br.readLine()) != null) {	
				lines.add(sCurrentLine);
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} 
		
		return lines;
	}

	public void display() {
		if (lines.size()==0) 
			System.out.println("Nothing to display.");
		
		for( String s : lines) {
			System.out.println(s);			
		}
	}
	
	public boolean writeInFile(String fileName) {	
		try {
			FileWriter fileWriter = new FileWriter(fileName, false);
			PrintWriter printLine = new PrintWriter(fileWriter);
			
			for( String s : lines) {
				printLine.println(s);			
			}
			
			printLine.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}
		
		return true;
	}
}
