
/**
 * A CSP solver using the static variable order. Prepared for COSC 322.  
 * 
 * @author yongg
 *
 */

public class CSPSolver {

	  public int consistencyLevel = ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY;	
	
	  public int[] solution; 			//the assignment to the variables  
	 	  
	  public CSPInstance csp = null; 	// the CSP instance to solve
      public int backtracking = 0;   	//recording the number of backtracks 
      
	  /**
 		Calls the forward checking method 
	  */
	  private boolean forwardChecking(int current, int value){
		//CSPInstance csp = new CSPInstance(C, domains);  
		boolean nonemptyDomain = ConstraintPropagator.forwardChecking(csp, current, value);        
	    return nonemptyDomain; // true;
	  }
	  	  
	  
	  /**
 		Calls the arcConsistency method
	  */
	  private boolean arc_consistency(int currentLevel){
		  //CSPInstance csp = new CSPInstance(C, domains);  
		  boolean nonemptyDomain = ConstraintPropagator.arcConsistency(csp, currentLevel); 
		  return nonemptyDomain; //true;  
	  }
      
	  
	  /**
	   * Call this to start the solver
	   * @param csp: a CSP instnace
	   * @param consistencyLevel: the level of consistency to be maintained 
	   */
	  public void solve(CSPInstance csp, int consistencyLevel)
	  {
		this.csp = csp;  
		solution = new int[csp.numOfVariables];   
		
	    // do an arc consistency as a pre-processing step.		
		if(consistencyLevel == ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY) 
		{
			boolean result = arc_consistency(-2); 
			
			if(result == false)
			{
				String msg = "Instance found unsatisfiable during pre-processing.";				
				output(result, msg); 				
				return;
			}
		}
 
		//call the recursive procedure to start the backtracking   
		boolean result = backtrackingSearch(0, consistencyLevel); 
		output(result, null);
	     
	  }
	  	  
	  
	  //int current: the current level of the search tree (begins with 0, the first variable) 
	  //int consistencyLevel: the level of constraint consistency to be maintained 
	  private boolean backtrackingSearch(int currentLevel, int consistencyLevel )
	  {	  
	       // if the recursion gets to the level N, then all the variables
		   // have been assigned without creating any conflict  
	       if(currentLevel == csp.numOfVariables)
	       {
			  return true; 
		   }
	      		  
		   // for each domain value of the current variable x_current
		   for(int i = 0; i < csp.numOfDomains; i++)
		   {		   
			   // domain value i is currently not allowed for whatever reasons 
		       if(csp.domains[currentLevel][i] != CSPInstance.IS_VALID)
			      continue;  			   
			   
		       // assign the value i to the current variable 
			   solution[currentLevel] = i;  			   
			   
			   //this is where the forward checking  
			   boolean consistent = true;
			   if(consistencyLevel >= ConstraintPropagator.CONSISTENCY_LEVEL_FORWARD_CHECKING)
			   {
				   consistent = this.forwardChecking(currentLevel, solution[currentLevel]);
			   }			   
			   if(consistencyLevel >= ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY)
			   {			   
				   consistent = this.arc_consistency(currentLevel);
			   }
			   			   
			   //dump(current);  
			   
			   //For now, the assignment solution[current] = i is ok, we continue the search
			   if(consistent)
			   { 			       
				   boolean success = backtrackingSearch(currentLevel + 1, consistencyLevel);
				   
				   if(success){
				      return true; 
				   }
				   else{
				       //if at some point, the recursion call fails, we backtrack  
				       backtracking++;
				   } 
			   }
			   
			   //restore the matrix int[][] domains to the state priori to  
			   //calling to the consistency checking
			   restore(currentLevel);
		   }
		   
		   //all the available domain values of x_current have been tried  
		   //without success 
	       return false;
	       
	  }//end of backtrackingSearch
	  
	  
	  
	  //Restore the domain matrix when backtracking
	  private void restore(int levelNumber)
	  {
	      for(int i = levelNumber + 1; i < csp.numOfVariables; i++)
	      {
			  for(int d = 0; d < csp.numOfDomains; d++)
			  {
				  if(csp.domains[i][d] == levelNumber)
				  {
					  csp.domains[i][d] = CSPInstance.IS_VALID;
				  }
			  } 
	      }
	  }
	  
	  
	 // the rest are some helper functions for output and solution verification
	
	 //output solving info 
	 private void output(boolean result, String msg){
	 
	   System.out.println("------------------------------");	 
	   System.out.println("Solving a CSP instance:  N = " + csp.numOfVariables + ", K = " + csp.numOfDomains + 
			    ", E = " +csp.numOfConstraints);
	   System.out.println("Num of Backtracking = " +  backtracking); 
	   
	   if(msg != null){
		   System.out.println(msg);
	   }
	   
	   if(!result){
	     System.out.println("Instance Unsatisfiable!");
	   }
	   else{
		   boolean v = verifySolution();
		   if(!v){
			   System.out.println("Fail to verify the solution");
		   }
		   else{
			   System.out.println("Solution Verified"); 	 
			   printSolution();  
		   }
	   }
	   
	   System.out.println("------------------------------");	
	   System.out.println();
	   
	 } 
	 
	 
	 //verifyies the solution
	 private boolean verifySolution()
	 {
	 
	    boolean verified = true;
	 
	    for(int i = 0; i < csp.numOfVariables; i++)
	    {
		   if(csp.domains[i][solution[i]] == - 2)
		   {
		     verified = false;
			 return verified;
		   }
		   
		}
	 
	    for(int i = 0; i < csp.numOfVariables; i++)
	    {
		  for(int j = i + 1; j < csp.numOfVariables; j++)
		  {
		    if(csp.constraints[i][j] != null)
		    {
		      if(!csp.constraints[i][j].isCompatible(solution[i], solution[j]))
		      {
			    verified = false;
			    return verified;
			   } 
			}
		  }
		}
	 
	    return verified;
	 }
	
	//print the solution  
	private void printSolution()
	{
	  //System.out.print(solution[0]); 
	  for(int i = 0; i < csp.numOfVariables; i++)
	  {
	      System.out.print("[x" + i + "=" + solution[i] + "]"); 
	  }
	  System.out.println();
	}  
	 
    //dump the state of the CSP instance 
	private void dump(int current)
	{
        printSolution();
			
        for(int i = 0; i < csp.numOfVariables; i++){
			for(int j = 0; j < csp.numOfDomains; j++){
			    System.out.print(csp.domains[i][j] + " ");
			}
			System.out.println();
        }
	 } 
	 
	 
} //end of the class
