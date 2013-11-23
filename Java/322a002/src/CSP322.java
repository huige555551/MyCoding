import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
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
         
		testRandomGraphColoring();
		
		testTextbookExample();
		
		testAllSudokuInstances();
    }
	
    
	public static void testCircleTwoColoring(int N, int K){
	
		CSPSolver  solver = new CSPSolver();
		
		//the constraint graph is a circle with N nodes
		Constraint[][] C = new Constraint[N][N];
		Constraint c = new Constraint();
		for(int i = 0; i < N - 1; i++){
		     C[i][i+1] = c;
		     C[i + 1][i] = c;
 
		} 
		C[0][N-1] = c;
		C[N - 1][0] = c;
		
		int[][] domains = new int[N][K]; 
		
		for(int i = 0; i < N; i++){
		   for(int j = 0; j < K; j++){
		      domains[i][j] = -1;
		   }
		}
		
		domains[N-1][1] = -2; // delete 0 from the domain of x_0 for testing purposes 
		
		CSPInstance csp = new CSPInstance(C, domains); 
		
	    solver.solve(csp, ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY);	
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
		solver.solve(csp, ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY);	
	}
	
	public static CSPInstance setupEmptySudokuInstance()
	{
		int N = 81;
		int K = 10;
		
		// Rows are group variables 0-8, 9-17, 18-26, etc.
		// Columns are varaibles grouped (0, 9, 18, ...), etc.
		
		Constraint[][] C = new Constraint[N][N];
		Constraint c  = new Constraint();
		int[][] domains = new int[N][K];
		
		for (int i = 0; i < N; i++)
		{
			// Setup domain values
			domains[i][0] = -2;
			for (int k = 1; k < K; k++)
			{
				domains[i][k] = -1;
			}
			
			// Find row limit for constraint enforcement.
			int rowLimit = i+1;
			while (rowLimit % 9 > 0)
			{
				rowLimit++;
			}
			
			/// Setup constraints.
			// Row constraints
			for (int j = i+1; j < rowLimit; j++)
			{
				//System.out.println("i: " + i + ", j: " + j);
				C[i][j] = c;
				C[j][i] = c;
			}
			// Column constraints
			for (int j = i+9; j < N; j+=9)
			{
				C[i][j] = c;
				C[j][i] = c;
			}
		}
		
		// Now we setup same square constraints.  This is tricky.
		int k = 0;
		while (k < 61)
		{
			//System.out.println("!!!! " + k + " !!!!");
			// Create array of square indices.
			int[] square = {k, k+1, k+2, k+9, k+10, k+11, k+18, k+19, k+20};
			
			for (int i = 0; i < square.length; i++)
			{
				for (int j = i+1; j < square.length; j++)
				{
					//System.out.println("i: " + square[i] + ", j: " + square[j]);
					C[square[i]][square[j]] = c;
					C[square[j]][square[i]] = c;
				}
			}
			
			// Setup next iteration.
			if (k % 9 == 6)
			{
				k += 21; 
			}
			else
			{
				k += 3;
			}
		}
		
		return new CSPInstance(C, domains);
		
	}
	
	public static CSPInstance parseSudokuProblem(String filename)
	{
		FileReader file;
		CSPInstance sudoku = setupEmptySudokuInstance();
		
		int row = 0;
		try {
			file = new FileReader(filename);
			
			BufferedReader reader = new BufferedReader(file);
			
			String nextLine = null;
			while ((nextLine = reader.readLine()) != null)
			{
				String[] boardData = nextLine.split(";");
				for (int i = 0; i < boardData.length; i++)
				{
					for (int j = 0; j < boardData[i].length(); j++)
					{
						String toParse = "" + boardData[i].charAt(j);
						int value = Integer.parseInt(toParse);
						//System.out.print(value);
						if (value != 0)
						{
							setSudokuDomainValue(sudoku, row, j, value);
						}
					}
					row++;
				}
			}
			System.out.println("");
		} catch (Exception e) {
			e.printStackTrace();
		}
		return sudoku;
	}
	
	public static void setSudokuDomainValue(CSPInstance sudoku, int position, int value)
	{
		// Delete all values not equal to value for positions domain.
		for (int j = 0; j < sudoku.domains[position].length; j++)
		{
			if (j == value)
			{
				continue;
			}
			else
			{
				sudoku.domains[position][j] = -2;
			}
		}
		
		for (int j = 0; j < sudoku.N; j++)
		{
			if (j == position) continue;
			
			if (sudoku.C[position][j] != null || sudoku.C[j][position] != null)
			{
				sudoku.domains[j][value] = -2;
			}
		}
	}
	public static void setSudokuDomainValue(CSPInstance sudoku, int row, int col, int value)
	{
		int position = (row*9) + col;
		setSudokuDomainValue(sudoku, position, value);
	}
	
	public static void testTextbookExample()
	{
		CSPInstance sudoku = setupEmptySudokuInstance();
		
		// Setup domain values.
		/**/
		setSudokuDomainValue(sudoku, 0, 2, 3);
		setSudokuDomainValue(sudoku, 0, 4, 2);
		setSudokuDomainValue(sudoku, 0, 6, 6);
		
		setSudokuDomainValue(sudoku, 1, 0, 9);
		setSudokuDomainValue(sudoku, 1, 3, 3);
		setSudokuDomainValue(sudoku, 1, 5, 5);
		setSudokuDomainValue(sudoku, 1, 8, 1);
		
		setSudokuDomainValue(sudoku, 2, 2, 1);
		setSudokuDomainValue(sudoku, 2, 3, 8);
		setSudokuDomainValue(sudoku, 2, 5, 6);
		setSudokuDomainValue(sudoku, 2, 6, 4);
		
		setSudokuDomainValue(sudoku, 3, 2, 8);
		setSudokuDomainValue(sudoku, 3, 3, 1);
		setSudokuDomainValue(sudoku, 3, 5, 2);
		setSudokuDomainValue(sudoku, 3, 6, 9);
		
		setSudokuDomainValue(sudoku, 4, 0, 7);
		setSudokuDomainValue(sudoku, 4, 8, 8);
		
		setSudokuDomainValue(sudoku, 5, 2, 6);
		setSudokuDomainValue(sudoku, 5, 3, 7);
		setSudokuDomainValue(sudoku, 5, 5, 8);
		setSudokuDomainValue(sudoku, 5, 6, 2);
		
		setSudokuDomainValue(sudoku, 6, 2, 2);
		setSudokuDomainValue(sudoku, 6, 3, 6);
		setSudokuDomainValue(sudoku, 6, 5, 9);
		setSudokuDomainValue(sudoku, 6, 6, 5);
		
		setSudokuDomainValue(sudoku, 7, 0, 8);
		setSudokuDomainValue(sudoku, 7, 3, 2);
		setSudokuDomainValue(sudoku, 7, 5, 3);
		setSudokuDomainValue(sudoku, 7, 8, 9);
		
		setSudokuDomainValue(sudoku, 8, 2, 5);
		setSudokuDomainValue(sudoku, 8, 4, 1);
		setSudokuDomainValue(sudoku, 8, 6, 3);
		
		CSPSolver solver = new CSPSolver();
		solver.solve(sudoku, ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY);
	}
	
	public static void testAllSudokuInstances()
	{
		File dir = new File("./src/sudokuData");
		
		File[] files = dir.listFiles();
		
		for (File f : files)
		{
			//if (f.toString().equals("./src/sudokuData/test04.sdata"))
			//	continue;
			//if (f.toString().equals("./src/sudokuData/test06.sdata"))
			//	continue;
			System.out.println("Solving sudoku puzzle in: " + f.toString());
			CSPInstance sudoku = parseSudokuProblem(f.toString());
			CSPSolver solver = new CSPSolver();
			solver.solve(sudoku, ConstraintPropagator.CONSISTENCY_LEVEL_ARC_CONSISTENCY);
		}
	}
}


