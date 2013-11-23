/**
 * A struct-like class for a CSP instance. Variables are all public.    Prepared for COSC 322
 * @author yonggao
 *
 */
public class CSPInstance {
	
	/**
	 * C[i][j] stores a reference variable for the binary Constraint between var i and var j. 	
	 *To make things simple, we will assume that the constraint is symmetric. 
	 */
	Constraint[][] C = null;
	
	
	/**
    The i-th row domains[i][*] stores the status of the domain values of the 
    variable i:
    (1). domains[i][j] = -2:  value j is not a valid domain value for variable i: 
							  either set by the problem definition or deleted 
							  during pre-processing, e.g. pre-arc-processing.
    (2). domains[i][j] = -1:  value j is a valid domain value for variable i.
    (3). domains[i][j] = t >= 0: value j is deleted during the 
							consistency propagation at level t of the search tree      	  
    */
	public int domains[][] = null;
	
	int N = 0; //num of variables
	int K = 0; //domain size
	int E = 0; //number of constraints
	
	/**
	 * Constructor
	 * @param C
	 * @param domains
	 */
	public CSPInstance(Constraint[][] C, int domains[][]) {
		this.C = C;
		this.domains = domains;
		
		N = C.length;
		K = domains[1].length;
		
		for(int i = 0; i < N; i++) {
			for(int j = i + 1; j < N; j++) {
				if(C[i][j] != null){
					E++;
				}
			}
		}		
	}
}
