package AdapterPattern.OneWay;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;


/**
 * The SquarePeg class.
 * This is the Target class.
 */
class SquarePeg {

    public void insert(String str) {
        System.out.println("SquarePeg insert(): " + str);
    }
}

/**
 * The RoundPeg class.
 * This is the Adaptee class.
 */
class RoundPeg {

    public void insertIntoHole(String msg) {
        System.out.println("RoundPeg insertIntoHole(): " + msg);
    }
}

/**
 * The PegAdapter2 class.
 * This is the Adapter1 class.
 * It adapts a RoundPeg to a SquarePeg.
 * Its interface is that of a SquarePeg.
 */

class PegAdapter1 extends SquarePeg {

    private RoundPeg roundPeg;

    public PegAdapter1(RoundPeg peg) {
        this.roundPeg = peg;
    }

    @Override
    public void insert(String str) {
        roundPeg.insertIntoHole(str);
    }
}

public class Adapter1 {

    public static void main(String[] args) throws IOException {
        // Create some pegs.
        RoundPeg roundPeg = new RoundPeg();
        SquarePeg squarePeg = new SquarePeg();
        // Do an insert using the square peg.
        squarePeg.insert("Inserting square peg...");

        // Now we'd like to do an insert using the round peg.
        // But this client only understands the insert()
        // method of pegs, not a insertIntoHole() method.
        // The solution: create an adapter that adapts
        // a square peg to a round peg!
        PegAdapter1 adapter = new PegAdapter1(roundPeg);
        adapter.insert("Inserting round peg...");

        BufferedReader reader;
        InputStream inStream = System.in;
        InputStreamReader inReader = new InputStreamReader(inStream);

        reader = new BufferedReader(inReader);

        String str = reader.readLine();

        System.out.println(str);

    }
}
