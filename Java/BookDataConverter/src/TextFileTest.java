

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class TextFileTest {

	@Test
	public void testConvert2Xml() {
		StringBuilder sb1 = new StringBuilder(UtilityClass.trim("name: Effective Java\nauthors: Joshua Bloch, James gosling\npublishedDate: October 2005"));
		StringBuilder sb2 = new StringBuilder("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<book xmlns:b=\"http://example.com/programmin/text/book\">\n <name>Effective Java</name>\n <authors>\n  <author>Joshua Bloch</author>\n  <author>James gosling</author>\n </authors>\n <publishedDate>October 2005</publishedDate>\n</book>");
		
		ArrayList<String> strArray1 = UtilityClass.string2ArrayList(sb1);
		ArrayList<String> strArray2 = UtilityClass.string2ArrayList(sb2);
		
		TextFile t = new TextFile(strArray1);
		ArrayList<String> xmlArray = t.convert2Xml();
		assertTrue(xmlArray.equals(strArray2));
	}

}
