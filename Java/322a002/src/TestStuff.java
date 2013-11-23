import static org.junit.Assert.*;

import org.junit.Test;


public class TestStuff {

	@Test
	public void testArcRevise() {
		CSPInstance sudoku = CSP322.setupEmptySudokuInstance();
		
		Constraint c = new Constraint();
		
		sudoku.C[1][2] = c;
		sudoku.C[2][2] = c;
		
		assertEquals(ConstraintPropagator.sizeOfDomain(sudoku, 1), 9);
		
		assertFalse(ConstraintPropagator.arcRevise(sudoku, 1, 2, -2));
		
		for (int i = 0; i < sudoku.K; i++)
		{
			sudoku.domains[2][i] = -2;
		}
		
		sudoku.domains[2][3] = -1;
		assertTrue(ConstraintPropagator.arcRevise(sudoku, 1, 2, -2));
		assertEquals(ConstraintPropagator.sizeOfDomain(sudoku, 1), 8);
	}

}
