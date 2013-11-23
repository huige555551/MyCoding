/*
 * Created on Sep 12, 2004
 *
 */
package gdouglas;

import aima.search.framework.GoalTest;

/**
 * @author Ravi Mohan
 * @author Graeme Douglas
 * 
 */

public class GaschnigGoalTest implements GoalTest {
	GaschnigBoard goal = new GaschnigBoard(GaschnigBoard.GOAL_BOARD);

	public boolean isGoalState(Object state) {
		GaschnigBoard board = (GaschnigBoard) state;
		return board.equals(goal);
	}

}