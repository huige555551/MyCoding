package HashExample;

import java.util.HashMap;
import java.util.Iterator;

public class HashMapExample {

    public static void main(String args[]) {

        HashMap hashMap = new HashMap();

        hashMap.put("One", 1); // adding value into HashMap
        hashMap.put("Two", new Integer(2));
        hashMap.put("Three", new Integer(3));

        System.out.println("HashMap contains " + hashMap.size() + " key value pairs.");

        if (hashMap.containsValue(new Integer(1))) {
            System.out.println("HashMap contains 1 as value");
        } else {
            System.out.println("HashMap does not contain 1 as value");
        }

        if (hashMap.containsKey("One")) {
            System.out.println("HashMap contains One as key");
        } else {
            System.out.println("HashMap does not contain One as value");
        }

        Integer one = (Integer) hashMap.get("One");
        System.out.println("Value mapped with key \"One\" is " + one);

        System.out.println("Retrieving all keys from the HashMap");
        Iterator iterator = hashMap.keySet().iterator();

        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

        System.out.println("Retrieving all values from the HashMap");
        iterator = hashMap.entrySet().iterator();

        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

        System.out.println(hashMap.remove("One") + " is removed from the HashMap.");

    }
}

/*
OUTPUT of the above given Java HashMap Example would be :
HashMap contains 3 key value pair.
HashMap contains 1 as value
HashMap contains One as key
Value mapped with key "One" is 1
Retrieving all keys from the HashMap
Three
Two
One
Retrieving all values from the HashMap
Three=3
Two=2
One=1
1 is removed from the HashMap.
 */
