import java.util.*;

/**
 * Prepared for COSC 322
 * For Testing and Demo.
 * 
 * @author yongg
 *
 */

public class CSP322 {
	
	
    public static void main (String args[]) {
    	
    	 //Should be found unsatisfiable during pre-processing with arc-consistency;
    	 //Without arc-consistency, should be found unsatisfiable  after a number of backtrackings  
         testCircleTwoColoring(21, 2);
         
         //With forward checking, we should find a solution without backtracking
         testCircleTwoColoring(20, 2); 
         
		 //testRandomGraphColoring();
         
         
        String easy1 = "000260701;680070090;190004500;820100040;004602900;050003028;009300074;040050036;703018000;";
 		testSudoku(easy1);
 		
 		String easy2 = "100489006;730000040;000001295;007120600;500703008;006095700;914600000;020000037;800512004;";
 		testSudoku(easy2);
 		
 		String inter = "020608000;580009700;000040000;370000500;600000004;008000013;000020000;009800036;000306090;";
 		testSudoku(inter);
 		
 		String diff1 = "000600400;700003600;000091080;000000000;050180003;000306045;040200060;903000000;020000100;";
 		testSudoku(diff1);
 		
 		String diff2 = "200300000;804062003;013800200;000020390;507000621;032006000;020009140;601250809;000001002;";
 		testSudoku(diff2);
 		
 		String notfun = "020000000;000600003;074080000;000003002;080040010;600500000;000010780;500009000;000000040;";
 		testSudoku(notfun);
 		
 		String text = "003020600;900305001;001806400;008102900;700000008;006708200;002609500;800203009;005010300;";
 		testSudoku(text);
    }

    // defautl given
	public static void testCircleTwoColoring(int N, int K){
	
		CSPSolver  solver = new CSPSolver();
		
		//the constraint graph is a circle with N nodes
		Constraint[][] C = new Constraint[N][N];
		Constraint c = new Constraint();
		
		for(int i = 0; i < N - 1; i++)
		{
		     C[i][i+1] = c;
		     C[i + 1][i] = c;
 
		} 
		C[0][N-1] = c;
		C[N - 1][0] = c;
		
		int[][] domains = new int[N][K]; 
		
		for(int i = 0; i < N; i++){
		   for(int j = 0; j < K; j++){
		      domains[i][j] = CSPInstance.IS_VALID;
		   }
		}		
		domains[N-1][1] = CSPInstance.NOT_VALID; // delete 0 from the domain of x_0 for testing purposes 
		
		CSPInstance csp = new CSPInstance(C, domains); 
		
	    solver.solve(csp, ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY);	
		//solver.solve(csp, ConstraintPropagator.CONSISTENCY_LEVEL_FORWARD_CHECKING);
	}
	public static void testRandomGraphColoring()
	{
	   int K = 3;    		// number of colors 
	   int N = 30;   		// number of nodes
	   double T = 4.0 / N;  // probability of a constraint 
	   	
	   Constraint[][] C = new Constraint[N][N];
	   Random r = new Random();  
	   
	   
	   Constraint c = new Constraint();
	   int M = 0;
	   for(int i = 0; i < N - 1; i++){
	      for (int j = i+1; j < N; j++){
		      if(r.nextDouble() < T){
			    C[i][j] = c;
			    C[j][i] = c;
				M++;
			  }  
		  }
	   }
	    	
	   int[][] domains = new int[N][K];
	
	   for(int i = 0; i < N; i++){
		   for(int j = 0; j < K; j++){
		      domains[i][j] = -1;
		   }
		}
	    
	    CSPInstance csp = new CSPInstance(C, domains); 
	   
		CSPSolver solver = new CSPSolver();
		//solver.solve(csp, ConstraintPropagator.CONSISTENCY_LEVEL_FORWARD_CHECKING);
		solver.solve(csp, ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY);	
	}
	
	/**********************************
	 * 
	 * Sudoku implementation
	 * 
	 ***********************************/
	
    public static void testSudoku(String problem)
    {
    	int N = 81;
		int K = 10; // domain value of 0 will be given -2 for ignoring 
		
		Constraint[][] C = new Constraint[N][N];
		int[][] domains = new int[N][K];
		
		Constraint con = new Constraint();
		
		for(int i=0; i<N; i++)
		{
			domains[i][0]=-2;
			
			for(int k=1; k<K; k++)
			{
				domains[i][k] = CSPInstance.IS_VALID;
			}
		}
		
		buildSudokuConstraints(C, con);
		
		readAndAssignInitialDomainValues(problem, C, domains);
		
		CSPInstance csp = new CSPInstance(C, domains);
		CSPSolver solver = new CSPSolver();
		//solver.solve(csp, ConstraintPropagator.CONSISTENCY_LEVEL_FORWARD_CHECKING);
		solver.solve(csp, ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY);
		
		printSudokuSolution(solver);
    }
	
    private static void buildSudokuConstraints(Constraint[][] C, Constraint con) 
    {
		for(int r=0; r<9; r++)
		{
			for(int c=0; c<9; c++)
			{
				int index = r*9+c;
				//System.out.print(index + "->");
				
				//row constraints
				for(int i=r*9; i<(r*9)+9; i++)
				{
					if(i==index) continue;
					C[index][i]= con;
					//System.out.print(i+" ");
				}				
				
				//column constraints
				for(int j=0; j<9; j++)
				{
					int t = j*9+c;
					if(t==index) continue;
					
					C[index][t]=con;	
					//System.out.print(t+" ");
				}
				//System.out.print("\n");
				
				//box constraints
				int box_r = r/3;
				int box_c = c/3;				
				for(int ir = 0; ir<3; ir++)
				{
					for(int ic = 0; ic<3; ic++)
					{
						int ii = (box_r*27) + (ir*9) + (box_c*3) + ic;
						if(index==ii) continue;
						
						C[index][ii] = con;
						//System.out.print(ii+" ");
					}
				}
				//System.out.print("\n");
			}
		}
	}
	
    private static void printSudokuSolution(CSPSolver solver) {
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				int index = i*9+j;
				System.out.print(solver.solution[index]+" ");
			}
			System.out.print("\n");
		}
	}
	
	private static void readAndAssignInitialDomainValues(String problem,	Constraint[][] C, int[][] domains) 
	{
		//System.out.println("\nString Tokenize begin:");
		StringTokenizer strToken = new StringTokenizer(problem, ";");
		for(int i=0; i<9; i++)
		{
			if(!strToken.hasMoreTokens()){System.out.println("Input error."); return;}			
			String rowStr = strToken.nextToken();			
			if(rowStr.length()!=9){System.out.println("Input error."); return;}
			
			for(int j=0; j<rowStr.length(); j++)
			{						
				int value = Integer.parseInt(rowStr.substring(j, j+1));
				if(value==0) continue;
				int index = i*9+j;
				
				setSudokuDomainValue(C, domains, index, value);
			}		
			
		}
	}    
    
	public static void setSudokuDomainValue(Constraint[][] C, int[][] domains, int index, int value)
    {
    	for(int i=0; i<domains[index].length; i++)
    	{
    		if(i==value) continue;
    		domains[index][i]=-2;
    	}
    	
    	//System.out.println(index+"->");
    	for(int i=0; i<C[index].length; i++)
    	{
    		if(i==index) continue;
    		if(C[index][i]!=null || C[i][index]!=null){
    			domains[i][value]=-2;
    			//System.out.print(i+" ");
    		}
    	}
    	//System.out.print("\n");
    }
	
    
    
 
}


