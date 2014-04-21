import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;

import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;

public class XmlFile extends GeneralFile {

	private StringBuilder strBuilder = new StringBuilder();
	
	public XmlFile(){}
	
	public XmlFile(ArrayList<String> str) {
		super(str);
	}
	
	@Override
	public boolean writeInFile(String fileName) {
		fileName += ".xml";
		return super.writeInFile(fileName);		
	}
	
	private void printNode(NodeList nodeList, boolean tagPrint) {
		 
	    for (int count = 0; count < nodeList.getLength(); count++) {	 
			Node tempNode = nodeList.item(count);		 
			// make sure it's element node.
			if (tempNode.getNodeType() == Node.ELEMENT_NODE) {		 
				// get node name and value
				if(tagPrint) {
					//System.out.printf("%s: ", tempNode.getNodeName());
					strBuilder.append(tempNode.getNodeName()+": ");
				}
				
				if (tempNode.getChildNodes().getLength() > 1) {
					boolean firstItem = true;
					for (int i = 0; i < tempNode.getChildNodes().getLength(); i++){
						String content = tempNode.getChildNodes().item(i).getTextContent().trim();
						content = content.replace(String.valueOf((char) 160), " ").trim();
			
						if(!content.isEmpty()){
							if(firstItem) {
								//System.out.printf("%s", content);
								strBuilder.append(content);
								firstItem = false;
							}
							else {
								//System.out.printf(", %s", content);
								strBuilder.append(", " + content);
							}
						}
					}
				}
				else {
					String content = tempNode.getTextContent().replace(String.valueOf((char) 160), " ").trim();
					//System.out.printf("%s", content);
					strBuilder.append(content);
				}
				
				if(tagPrint) {
					//System.out.printf("\n");
					strBuilder.append("\n");
				}
			}
	    }
	}
	
	public ArrayList<String> convert2text() {
		try{
			InputStream stream = UtilityClass.createInputStream(lines);
			DocumentBuilder dBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
			Document doc = dBuilder.parse(stream);		 
			doc.getDocumentElement().normalize();		

			if (doc.hasChildNodes()) {
				printNode(doc.getChildNodes().item(0).getChildNodes(), true);
			}
	    } catch (Exception e) {
	    	e.printStackTrace();
	    }	
		
		return UtilityClass.string2ArrayList(strBuilder);
	}
}
