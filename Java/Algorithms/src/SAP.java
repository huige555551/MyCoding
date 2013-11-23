

public class SAP {

	private static final int INFINITY = Integer.MAX_VALUE;
	private Digraph G;
	
	// constructor takes a digraph (not necessarily a DAG)
	public SAP(Digraph G){
		this.G = G;
	}

	// length of shortest ancestral path between v and w; -1 if no such path
	public int length(int v, int w){
		BreadthFirstDirectedPaths vBFS = new BreadthFirstDirectedPaths(G,  v);
		BreadthFirstDirectedPaths wBFS = new BreadthFirstDirectedPaths(G, w);
		
		int min = INFINITY;
		for (int i = 0; i < G.V(); i++){
			if(vBFS.distTo(i) == INFINITY || wBFS.distTo(i) == INFINITY) continue;
			int sum = vBFS.distTo(i) + wBFS.distTo(i);
			if(sum < min) min = sum;
		}
		
		if(min == INFINITY) return -1;
		return min;
	}

	// a common ancestor of v and w that participates in a shortest ancestral path; -1 if no such path
	//public int ancestor(int v, int w)

	// length of shortest ancestral path between any vertex in v and any vertex in w; -1 if no such path
	//public int length(Iterable<Integer> v, Iterable<Integer> w)

	// a common ancestor that participates in shortest ancestral path; -1 if no such path
	//public int ancestor(Iterable<Integer> v, Iterable<Integer> w)

	// for unit testing of this class (such as the one below)	
	public static void main(String[] args) {
	    In in = new In(args[0]);
	    Digraph G = new Digraph(in);
	    SAP sap = new SAP(G);
	    while (!StdIn.isEmpty()) {
	        int v = StdIn.readInt();
	        int w = StdIn.readInt();
	        int length   = sap.length(v, w);
	        int ancestor = 1; //sap.ancestor(v, w);
	        StdOut.printf("length = %d, ancestor = %d\n", length, ancestor);
	    }
	}
}
