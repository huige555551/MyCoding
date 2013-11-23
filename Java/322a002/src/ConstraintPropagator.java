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
	public static boolean forwardChecking(CSPInstance csp, int currentLevel, int currentValue) {
		// FOREACH variable
		for (int i = currentLevel+1; i < csp.domains.length; i++)
		{
			boolean empty = true;
			
			// FOREACH domain value of variable i
			for (int j = 0; j < csp.domains[i].length; j++)
			{
				// If this is currently a valid domain value but is not compatible with the current level / current value
				if (csp.domains[i][j] == -1 && csp.C[i][currentLevel] != null && !(csp.C[i][currentLevel].isCompatible(j, currentValue)))// && csp.C[currentLevel][i].isCompatible(j, currentValue)))
				{
					csp.domains[i][j] = currentLevel;
				}
				// Otherwise, this is a nonempty domain
				else
				{
					empty = false;
				}
			}
			
			// If it is empty.
			if (empty)
			{
				return false;
			}
		}
		
	    return true; 
	}//end of forwardChecking
	
	/**
	 * Implementation of the AC-3 algorithm.
	 * @param csp: the csp instance
	 * @param currentLevel: the current level in the search tree. Equal to the index of the current variable
	 * @return false if the domain of some variable becomes empty after arc consistency maintaining 
	 */
	   //You are required to implement this function to maintain the arc consistency 
	   //Delete value j of variable i by assigning domains[i][j] = currentLvel
	   //Return false when some variable's domain become empty 
	
	public static boolean arcConsistency(CSPInstance csp, int currentLevel) {
		// Create and add all elements to the constraint queue.
		Queue<IntPair> q = new LinkedList<IntPair>();
		addAllArcs(csp, q);
		
		while (!q.isEmpty())
		{
			IntPair next = q.poll();
			int x = next.x;
			int y = next.y;
			
			// If some value was deleted from x's domain...
			if (arcRevise(csp, x, y, currentLevel))
			{
				//  If x's domain is empty.
				if (sizeOfDomain(csp, x) == 0)
				{
					return false;
				}
				
				// Add back all arcs.
				addAllXArcs(csp, q, x, y);
			}
		}
		
		
		return true; 
	}//end of arcConsistency
	
	/**
	 * The arc revision subroutine of AC-3 algorithm.
	 * 
	 * @param csp	The CSPInstance to be worked with.
	 * @param x		The index of the variable whose domain is to be reduced.
	 * @param y		The index of the variable whose domain is to be compared
	 * 				against.
	 * @param currentLevel	The current level.
	 * @return		<code> true </code> if <code> x </code>'s domain changed,
	 * 				<code> false </code> otherwise.
	 */
	public static boolean arcRevise(CSPInstance csp, int x, int y, int currentLevel) {
		// Must be a real arc between y and x
		if (csp.C[x][y] == null) return false;
		
		boolean changed = false;
		
		// FOREACH value in x's domain
		for (int i = 0; i < csp.K; i++)
		{
			// Only consider those values not pruned in pre-processing
			if (csp.domains[x][i] == -2) continue;
			
			boolean valExists = false;
			
			// FOREACH value in y's domain
			for (int j = 0; j < csp.K; j++)
			{
				// Only consider those values not pruned in pre-processing
				if (csp.domains[y][j] == -2) continue;
				
				// If there is a compatible value, indicate and stop searching
				if (csp.C[x][y].isCompatible(i, j))
				{
					valExists = true;
					break;
				}
			}
			
			
			// If no compatible value found, delete the value from x's domain
			if (!valExists)
			{
				csp.domains[x][i] = currentLevel;
				changed = true;
			}
		}
		
		return changed;
	}
	
	/**
	 * Find the size of a domain.
	 * 
	 * @param csp	The CSPInstance of the problem.
	 * @param x		The index of the variable whose domain we wish to get the
	 * 				size of. Set to -1 if we wish to get size of overall domain.
	 * @return		The size of the domain specified.
	 */
	public static int sizeOfDomain(CSPInstance csp, int x)
	{
		int count = 0;
		if (x < 0)
		{
			return csp.K;
		}
		
		for (int i = 0; i < csp.domains[x].length; i++)
		{
			if (csp.domains[x][i] != -2)
			{
				count++;
			}
		}
		
		return count;
	}
	
	/**
	 * Add all constraints to the constraint queue.
	 * 
	 * @param csp	CSPInstance to be worked with.
	 * @param q		The queue to add the arcs to.
	 */
	private static void addAllArcs(CSPInstance csp, Queue<IntPair> q)
	{
		for (int i = 0; i < csp.C.length; i++)
		{
			for (int j = 0; j < csp.C[i].length; j++)
			{
				if (i == j) continue;
				
				IntPair toAdd = new IntPair(i, j);
				
				if (csp.C[i][j] != null)// && !q.contains(toAdd))
				{
					q.offer(toAdd);
				}
			}
		}
	}
	
	/**
	 * Add all constraints related to variable x.
	 * @param csp	The CSPInstance whose constraints we wish to add from.
	 * @param q		The queue containing the constraints.
	 * @param x		The index of the variable whose constraints we wish to add.
	 * @param y		The index of the variable whose constraints we wish to ignore.
	 */
	private static void addAllXArcs(CSPInstance csp, Queue<IntPair> q, int x, int y)
	{
		for (int j = 0; j < csp.C[x].length; j++)
		{
			if (j == x || j == y) continue;
			
			IntPair toAdd = new IntPair(j, x);
			
			if (csp.C[x][j] != null)// && !q.contains(toAdd))
			{
				q.offer(toAdd);
			}
		}
	}
	
}//end of class
