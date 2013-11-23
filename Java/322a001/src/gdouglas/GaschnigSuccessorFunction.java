package gdouglas;

import java.util.ArrayList;
import java.util.List;

import aima.search.framework.Successor;
import aima.search.framework.SuccessorFunction;

public class GaschnigSuccessorFunction implements SuccessorFunction {

	@Override
	public List<Successor> getSuccessors(Object state) {
		List<Successor> successors = new ArrayList<Successor>();
		
		GaschnigBoard board = (GaschnigBoard)state;
		
		System.out.println("Current board:\n" + board.toString() + "\n");
		
		// FIXME: Boards don't have sizes? really?
		for (int i = 0; i < 9; i++) {
			if (board.getBoard()[i] != 0) {
				GaschnigBoard newBoard = copyOf(board);
				newBoard.moveGapToPosition(i);
				successors.add(new Successor((new Integer(i)).toString(), newBoard));
				System.out.println(newBoard.toString() + "\n");
			}
		}
		return successors;
	}
	
	private GaschnigBoard copyOf(GaschnigBoard board) {
		GaschnigBoard newBoard = new GaschnigBoard();
		newBoard.setBoard(board.getPositions());
		return newBoard;
	}
}
