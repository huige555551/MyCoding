import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * A static class for functions that implement constraint propagation methods.  Prepared for COSC 322
 * 
 * @author yonggao
 *
 */

public class ConstraintPropagator {
	
	
	private static boolean runConsistencyChecking = false;
	
	public final static int CONSISTENCY_LEVEL_FORWARD_CHECKING = 1;
	public final static int CONSISTENCY_LEVEL_ARC_CONSISTENCY = 2;
	public final static int CONSISTENCY_LEVEL_PATH_COSISTENCY = 3;
	
	/**
	 * Implements the forward checking method
	 * 
	 * @param csp: the CSP instance
	 * @param currentLevel: the current level of the search tree. Equal to the index of the current variable
	 * @param currentValue: the value currently assigned to the current variable x_currentLevel
	 * @return false if the domain of some variable becomes empty after the forward checking
	 */	
   //You are required to implement this function to do the forward-checking
   //If a domain value k of a variable x_j is not compatible with the assignment
   //x_current = value, delete k by letting domains[j][k] = current  
   //
   //Return false only if some variable's domain become empty  	
	public static boolean forwardChecking(CSPInstance csp, int currentLevel, int currentValue)
	{				
		//for all the other variables
		for(int i=currentLevel+1; i<csp.numOfVariables; i++)
		{
			//if there is any constraint with currentLevel
			if(csp.constraints[currentLevel][i]!=null)
			{
				boolean success = false;
				
				//iterate through the domain of the variable
				for(int d=0; d<csp.numOfDomains; d++)
				{					
					//if domain value is not changed yet
					if(csp.domains[i][d] == CSPInstance.IS_VALID)
					{		
						//check whether the value is compatible with currentValue
						if(!csp.constraints[currentLevel][i].isCompatible(currentValue, d))
						{
							//if not compatible then mark it
							csp.domains[i][d] = currentLevel;	
						}
						else {// compatible then success
							success = true;
						}
					}
				}
				if(!success) return false;
			}			
		}
		
	    return true;  	 
	}//end of forwardChecking
	
	
	/**
	 * Implements the arc consistency method 
	 * @param csp: the csp instance
	 * @param currentLevel: the current level in the search tree. Equal to the index of the current variable
	 * @return false if the domain of some variable becomes empty after arc consistency maintaining 
	 */
	   //You are required to implement this function to maintain the arc consistency 
	   //Delete value j of variable i by assigning domains[i][j] = currentLvel
	   //Return false when some variable's domain become empty 
	
	public static boolean arcConsistency(CSPInstance csp, int currentLevel)
	{	
		// queue for all storing all arcs
		Queue<IntPair> q = new LinkedList<IntPair>();		
		// add all arcs to queue
		addAllArcs(csp, q);		
		
		// while queue is not empty
		while(!q.isEmpty())
		{
			// pull one arc
			IntPair pair = q.poll();
			int x = pair.x;
			int y = pair.y;
			
			// revise the domain of X with respect of Y
			if(arcRevise(csp, x, y, currentLevel))
			{	
				// size of valid domain in DomX
				if(sizeOfDomain(csp, x) == 0) 
					return false;
				
				addAllXArcs(csp, q, x, y);
			}
		}
		
		return true; //does nothing currently 
	}//end of arcConsistency
	
	/**
	 * Add all constraints related to variable x.
	 * @param csp	The CSPInstance whose constraints we wish to add from.
	 * @param q		The queue containing the constraints.
	 * @param x		The index of the variable whose constraints we wish to add.
	 * @param y		The index of the variable whose constraints we wish to ignore.
	 */
	public static void addAllXArcs(CSPInstance csp, Queue<IntPair> q, int x, int y)
	{
		for(int i=0; i<csp.numOfVariables; i++)
		{
			if(i==x || i==y) continue;
			
			if(csp.constraints[x][i]!=null)
			{
				IntPair pair = new IntPair(i, x);
				q.add(pair);
			}
		}
	}
	
	public static int sizeOfDomain(CSPInstance csp, int x)
	{		
		int count = 0;
		
		for(int i=0; i<csp.numOfDomains; i++)
		{
			if(csp.domains[x][i]== CSPInstance.NOT_VALID) continue;
			count++;
		}
		
		return count;		
	}
	
	public static boolean arcRevise(CSPInstance csp, int x, int y, int currentLevel)
	{
		boolean xDomainChanged = false;
		
		// foreach domain values of x
		for(int i=0; i<csp.numOfDomains; i++)
		{			
			if(csp.domains[x][i] == CSPInstance.NOT_VALID) 
				continue;
			
			boolean compatible = false;
			
			// foreach domain values of y
			for(int j=0; j<csp.numOfDomains; j++)
			{				
				if (csp.domains[y][j] == CSPInstance.NOT_VALID) 
					continue;
				
				// check compatibility
				// whether i \in DomX is comatible with any of j \in DomY
				if(csp.constraints[x][y].isCompatible(i, j))
				{
					compatible = true;
					break;
				}
			}
			
			// if i \in DomX is not compatible
			// then DomX needs to be reviesed 
			if(!compatible)
			{
				csp.domains[x][i] = currentLevel;
				xDomainChanged = true;
			}
			
		}
		
		return xDomainChanged;
	}
	
	public static void addAllArcs(CSPInstance csp, Queue<IntPair> q)
	{
		for(int i=0; i<csp.numOfVariables; i++)
		{
			for(int j=0; j<csp.numOfVariables; j++)
			{
				if(csp.constraints[i][j]!=null && i!=j)
				{
					IntPair pair = new IntPair(i,j);
					q.add(pair);					
				}
			}			
		}
	}
	
}//end of class
