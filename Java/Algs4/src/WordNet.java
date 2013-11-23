import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


/**
 * @author Shahadat
 *
 */
public class WordNet {

	/**
	 * 
	 */
	private Digraph diGraph;
	/**
	 * 
	 */
	private int synSetSize = 0;
	/**
	 * 
	 */
	private SAP sapObj;
	/**
	 * 
	 */
	private Map<Integer, List<String>> id2Noun;	//map for id to noun
	/**
	 * 
	 */
	private Map<String, Integer> noun2Id = new HashMap<String, Integer>(); 
	
	// constructor takes the name of the two input files
	/**
	 * @param synsets sets
	 * @param hypernyms parent
	 */
	public WordNet(final String synsets, final String hypernyms) {
		id2Noun = new HashMap<Integer, List<String>>();
		
		readSynSets(synsets);
		constructDigraph(hypernyms);
		
		//check if it has cycle
		DirectedCycle cycle = new DirectedCycle(diGraph);
		if (cycle.hasCycle()) {
			throw new IllegalArgumentException("Invalide DAG.");
		}
		int root = 0;
		for (int i = 0; i < diGraph.V(); i++) {
			if (!diGraph.adj(i).iterator().hasNext()) {
				root++;
			}
		}
		if (root > 1) {
			throw new IllegalArgumentException("Not a rooted DAG");
		}
		sapObj = new SAP(diGraph);
	}
	
	/**
	 * @param synsetsFile file
	 */
	private void readSynSets(final String synsetsFile) {
		In inFile = new In(synsetsFile);
		String line = new String();
		int countLine = 0;
		
		while ((line = inFile.readLine()) != null) {
			
			if (line.length() == 0) {
				continue;
			}
			
			//read the elements from the line string
			String[] lineElem = line.split(",");
			
			//get the id, list of nouns
			int synId = Integer.parseInt(lineElem[0]);
			String[] nouns = lineElem[1].split(" ");
			List<String> nounList = Arrays.asList(nouns);
			
			id2Noun.put(synId, nounList);
			for (String n: nounList) {
				noun2Id.put(n, synId);
			}
			countLine++;
		}
		
		synSetSize = countLine;
	}
	
	/**
	 * @param hypernymsFile file
	 */
	private void constructDigraph(final String hypernymsFile) {
		diGraph = new Digraph(synSetSize);
		
		In inFile = new In(hypernymsFile);
		String line = new String();
		
		while ((line = inFile.readLine()) != null) {
			String[] lineElem = line.split(",");
			
			int v = Integer.parseInt(lineElem[0]);
			for (int i = 1; i < lineElem.length; i++) {
				int w = Integer.parseInt(lineElem[i]);
				diGraph.addEdge(v, w);
			}
		}		
	}
 
	/**
	 * @return the set of nouns (no duplicates), returned as an Iterable
	 */
	public Iterable<String> nouns() {
		return noun2Id.keySet();
	}

	// is the word a WordNet noun?
	/**
	 * @param word string
	 * @return boolean
	 */
	public boolean isNoun(final String word) {
		return noun2Id.containsKey(word);
	}

	/**
	 * distance between nounA and nounB (defined below).
	 * @param nounA node
	 * @param nounB node
	 * @return int
	 */
	public int distance(final String nounA, final String nounB) {
		return sapObj.length(noun2Id.get(nounA), noun2Id.get(nounB));
	}

	
	/**
	 * A synset (second field of synsets.txt) that is the common ancestor 
	 * of nounA and nounB in a shortest ancestral path (defined below).
	 * @param nounA node
	 * @param nounB node
	 * @return string
	 */
	public String sap(final String nounA, final String nounB) {
		int ancestorId = sapObj.ancestor(noun2Id.get(nounA), 
				noun2Id.get(nounB));
		return id2Noun.get(ancestorId).get(0);
	}

	
	/**
	 * for unit testing of this class.
	 * @param args arguments
	 */
	public static void main(final String[] args) {
		WordNet w = new WordNet("synsets.txt", "hypernyms.txt");
		StdOut.printf("length = %d\n", w.synSetSize);
		StdOut.printf("distance = %d\n", 
				w.distance("Rameses_the_Great", "Henry_Valentine_Miller"));
		StdOut.printf("sap = %s\n", 
				w.sap("Rameses_the_Great", "Henry_Valentine_Miller"));
	}

}
