
/**
 *  The <tt>Outcast</tt> class for finding outcast word.
 *
 *  @author Shahadat Hossain
 */
public class Outcast {

	/**
	 * wordnet reference.
	 */
	private WordNet wordnet;
	/**
	 * constructor takes a WordNet object.
	 * @param wordNet a final
	 */
	public Outcast(final WordNet wordNet) {
		this.wordnet = wordNet;
	}

	/**
	 * Given an array of WordNet nouns, return an outcast.
	 * @param nouns is a list of noun
	 * @return a string
	 */
	public String outcast(final String[] nouns) {
		 String outcast = null;
         int max = 0;
         for (String noun1 : nouns) {
             int distance = 0;
             for (String noun2 : nouns) {
                 if (!noun1.equals(noun2)) {
                         distance += this.wordnet.distance(noun1, noun2);
                 }
             }
             if (distance > max) {
                 max = distance;
                 outcast = noun1;
             }
         }

         return outcast;
	}

	/**
	 * @param args arguments
	 */
	public static void main(final String[] args) {
		 Outcast out = new Outcast(new WordNet("synsets.txt", "hypernyms.txt"));
         String[] nouns = {"horse", "zebra", "cat", "bear", "table"};
         
         System.out.println(out.outcast(nouns));
	}

}
