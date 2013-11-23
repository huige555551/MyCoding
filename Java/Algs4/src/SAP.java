import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;



/**
 * @author Shahadat
 *
 */
public class SAP {

	/**
	 * 
	 */
	private static final int INFINITY = Integer.MAX_VALUE;
	/**
	 * 
	 */
	private final Digraph diGraph;
	
	
	/**
	 * Constructor takes a digraph (not necessarily a DAG).
	 * @param graph input
	 */
	public SAP(final Digraph graph) {
		this.diGraph = graph;
	}

	// 
	/**
	 * length of shortest ancestral path between v and w; -1 if no such path.
	 * @param v 1st node
	 * @param w 2nd node
	 * @return int
	 */
	public int length(final int v, final int w) {
		BreadthFirstDirectedPaths vBFS = 
				new BreadthFirstDirectedPaths(diGraph, v);
		BreadthFirstDirectedPaths wBFS = 
				new BreadthFirstDirectedPaths(diGraph, w);
				
		int comAnc = ancestor(v, w);
		if (comAnc == -1) {
			return -1;
		}
			
		int	len = vBFS.distTo(comAnc) + wBFS.distTo(comAnc);

		return len;
	}

	/**
	 * A common ancestor of v and w that participates in 
	 * a shortest ancestral path; -1 if no such path.
	 * @param v node
	 * @param w node
	 * @return int
	 */
	public int ancestor(final int v, final int w) {
		Map<Integer, Integer> map1 = new HashMap<Integer, Integer>();
		Map<Integer, Integer> map2 = new HashMap<Integer, Integer>();
		
		//first bfs
		int s = v;
		Queue<Integer> q = new Queue<Integer>();
		boolean[] marked  = new boolean[diGraph.V()];
	    int[] distTo = new int[diGraph.V()];
	    int[] edgeTo = new int[diGraph.V()];        
        
        marked[s] = true;
        distTo[s] = 0;        
        map1.put(s, distTo[s]);
        q.enqueue(s);
        while (!q.isEmpty()) {
            int u = q.dequeue();
            for (int t : diGraph.adj(u)) {
                if (!marked[t]) {
                    edgeTo[t] = u;
                    distTo[t] = distTo[u] + 1;
                    marked[t] = true;                    
                    map1.put(t, distTo[t]);                    
                    q.enqueue(t);
                }
            }
        }
        
        //2nd bfs
        s = w;
        q = new Queue<Integer>();
        marked = new boolean[diGraph.V()];
        distTo = new int[diGraph.V()];
        edgeTo = new int[diGraph.V()];
        
        marked[s] = true;
        distTo[s] = 0;        
        if (map1.containsKey(s)) {
			map2.put(s, map1.get(s) + distTo[s]);
		}
        q.enqueue(s);        
        while (!q.isEmpty()) {
            int u = q.dequeue();
            for (int t : diGraph.adj(u)) {
                if (!marked[t]) {
                    edgeTo[t] = u;
                    distTo[t] = distTo[u] + 1;
                    marked[t] = true;                    
                    if (map1.containsKey(t)) {
						map2.put(t, distTo[t] + map1.get(t));
					}
                    q.enqueue(t);
                }
            }
        }
        
        //iterate through map
        int min = INFINITY;
        int comAnc = -1;
        for (Integer t: map2.keySet()) {
        	if (map2.get(t) < min) {
        		comAnc = t;
        		min = map2.get(t);
        	}
        }
        
        
		return comAnc;
	}
	

	// length of shortest ancestral path between any vertex in v and any vertex in w; -1 if no such path
	public int length(final Iterable<Integer> v, final Iterable<Integer> w){
		BreadthFirstDirectedPaths vBFS = new BreadthFirstDirectedPaths(diGraph, v);
		BreadthFirstDirectedPaths wBFS = new BreadthFirstDirectedPaths(diGraph, w);
				
		int comAnc = ancestor(v, w);
		if (comAnc == -1) {
			return -1;
		}
			
		int	len = vBFS.distTo(comAnc) + wBFS.distTo(comAnc);

		return len;
	}

	// a common ancestor that participates in shortest ancestral path; -1 if no such path
	public int ancestor(final Iterable<Integer> v, final Iterable<Integer> w){
		BreadthFirstDirectedPaths vBFS = new BreadthFirstDirectedPaths(diGraph, v);
		BreadthFirstDirectedPaths wBFS = new BreadthFirstDirectedPaths(diGraph, w);
		
		ArrayList<Integer> tempArr = new ArrayList<Integer>();
		for (int i = 0; i < diGraph.V(); i++){
			if (vBFS.hasPathTo(i) && wBFS.hasPathTo(i)){
				tempArr.add(i);
			}
		}
		
		int min = INFINITY;
		int comAnc = -1;
		
		for (Integer i: tempArr){
			int sum = vBFS.distTo(i) + wBFS.distTo(i); 
			if (sum < min) {
				min = sum;
				comAnc = i;
			}
		}
		
		return comAnc;
	}

	// for unit testing of this class (such as the one below)	
	public static void main(final String[] args) {
	    In in = new In(args[0]);
	    Digraph G = new Digraph(in);
	    SAP sap = new SAP(G);
	    while (!StdIn.isEmpty()) {
	        int v = StdIn.readInt();
	        int w = StdIn.readInt();
	        int length   = sap.length(v, w);
	        int ancestor = sap.ancestor(v, w);
	        StdOut.printf("length = %d, ancestor = %d\n", length, ancestor);
	        
	    }
	}
}
