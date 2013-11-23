/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package CollectionFrameWork;

import java.util.ArrayList;
import java.util.LinkedList;

/**
 *
 * @author sohag
 */
public class ArrayListExample
{
    public static void main(String args[])
    {

        ArrayList<LinkedList<String>> result = new ArrayList<LinkedList<String>>();
        LinkedList<String> list = new LinkedList<String>();

        list.add("first");
        result.add(0, list);


        System.out.println(result.get(0).get(0));
        
    }
}
