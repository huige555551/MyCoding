/**
 * A struct-like class for a CSP instance. Variables are all public.    Prepared for COSC 322
 * @author yonggao
 *
 */
public class CSPInstance {
	
	public static final int NOT_VALID = -2;
	public static final int IS_VALID = -1;
	
	/**
	 * C[i][j] stores a reference variable for the binary Constraint between var i and var j. 	
	 * To make things simple, we will assume that the constraint is symmetric.
	 * Dimension = N * N
	 * i, j \in N 
	 */
	Constraint[][] constraints = null;
	
	/**
    The i-th row domains[i][*] stores the status of the domain values of the 
    variable i:
    (1). domains[i][j] = -2:  value j is not a valid domain value for variable i: 
							  either set by the problem definition or deleted 
							  during pre-processing, e.g. pre-arc-processing.
    (2). domains[i][j] = -1:  value j is a valid domain value for variable i.
    (3). domains[i][j] = t >= 0: value j is deleted during the 
							consistency propagation at level t of the search tree  
	dimension = N * K
	i \in N
	j \in K       	  
    */
	public int domains[][] = null;
	
	int numOfVariables = 0; //num of variables
	int numOfDomains = 0; //domain size
	int numOfConstraints = 0; //number of constraints
	
	/**
	 * Constructor
	 * @param constraints
	 * @param domains
	 */
	public CSPInstance(Constraint[][] constraints, int domains[][])
	{
		this.constraints = constraints;
		this.domains = domains;
		
		numOfVariables = constraints.length;
		numOfDomains = domains[1].length;
		
		for(int i = 0; i < numOfVariables; i++)
		{
			for(int j = i + 1; j < numOfVariables; j++)
			{
				if(constraints[i][j] != null)
				{
					numOfConstraints++;
				}
			}
		}		
	}
}
