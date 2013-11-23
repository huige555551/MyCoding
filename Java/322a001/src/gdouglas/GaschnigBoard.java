package gdouglas;

import java.util.ArrayList;
import java.util.List;

import aima.basic.XYLocation;

// PLEASE NOTE: This code is strongly inspired by aima.search.eightpuzzle.EightPuzzleBoard
public class GaschnigBoard {
	public static String SWAP_ZERO = "0";
	public static String SWAP_ONE = "1";
	public static String SWAP_TWO = "2";
	public static String SWAP_THREE = "3";
	public static String SWAP_FOUR = "4";
	public static String SWAP_FIVE = "5";
	public static String SWAP_SIX = "6";
	public static String SWAP_SEVEN = "7";
	public static String SWAP_EIGHT = "8";
	public static String SWAP_NINE = "9";

	public int[] getBoard() {
		return board;
	}
	

	public static final int[] GOAL_BOARD = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int[] board;

	public GaschnigBoard() {
		board = new int[] { 5, 4, 0, 6, 1, 8, 7, 3, 2 };

	}

	public GaschnigBoard(int[] aBoard) {
		board = aBoard;
	}

	private int[] xycoordinatesFromAbsoluteCoordinate(int x) {
		int[] retVal = null;
		switch (x) {
		case 0:
			retVal = new int[] { 0, 0 };
			break;
		case 1:
			retVal = new int[] { 0, 1 };
			break;
		case 2:
			retVal = new int[] { 0, 2 };
			break;
		case 3:
			retVal = new int[] { 1, 0 };
			break;
		case 4:
			retVal = new int[] { 1, 1 };
			break;
		case 5:
			retVal = new int[] { 1, 2 };
			break;
		case 6:
			retVal = new int[] { 2, 0 };
			break;
		case 7:
			retVal = new int[] { 2, 1 };
			break;
		case 8:
			retVal = new int[] { 2, 2 };
			break;

		}
		return retVal;
	}

	private int absoluteCoordinatesFromXYCoordinates(int x, int y) {
		return x * 3 + y;
	}

	private int getValueAt(int x, int y) {
		// refactor this use either case or a div/mod soln
		return board[absoluteCoordinatesFromXYCoordinates(x, y)];
	}

	private int getGapPosition() {

		return getPositionOf(0);
	}

	private int getPositionOf(int val) {
		int retVal = -1;
		for (int i = 0; i < 9; i++) {
			if (board[i] == val) {
				retVal = i;
			}
		}
		return retVal;
	}

	public XYLocation getLocationOf(int val) {
		int abspos = getPositionOf(val);
		int xpos = xycoordinatesFromAbsoluteCoordinate(abspos)[0];
		int ypos = xycoordinatesFromAbsoluteCoordinate(abspos)[1];
		return new XYLocation(xpos, ypos);
	}

	private void setValue(int xPos, int yPos, int val) {
		int abscoord = absoluteCoordinatesFromXYCoordinates(xPos, yPos);
		board[abscoord] = val;

	}

	public int getValueAt(XYLocation loc) {
		return getValueAt(loc.getXCoOrdinate(), loc.getYCoOrdinate());
	}
	
	public void putAppropriateInGap() {
		int gapPosition = getGapPosition();
		
		int valueWanted = GaschnigBoard.GOAL_BOARD[gapPosition];
		int incorrectPosition = getPositionOf(valueWanted);
		
		// Perform the swap.
		this.board[gapPosition] = valueWanted;
		this.board[incorrectPosition] = 0;
	}
	
	public void moveGapToPosition(int position) {
		int gapPosition = getGapPosition();
		int gapVal = board[gapPosition];
		board[gapPosition] = board[position];
		board[position] = gapVal;
	}

	@Override
	public boolean equals(Object o) {

		if (this == o) {
			return true;
		}
		if ((o == null) || (this.getClass() != o.getClass())) {
			return false;
		}
		GaschnigBoard aBoard = (GaschnigBoard) o;

		for (int i = 0; i < 8; i++) {
			if (this.getPositionOf(i) != aBoard.getPositionOf(i)) {
				return false;
			}
		}
		return true;
	}

	@Override
	public int hashCode() {
		int result = 17;
		for (int i = 0; i < 8; i++) {
			int position = this.getPositionOf(i);
			result = 37 * result + position;
		}
		return result;
	}

	public List<XYLocation> getPositions() {
		ArrayList<XYLocation> retVal = new ArrayList<XYLocation>();
		for (int i = 0; i < 9; i++) {
			int[] res = xycoordinatesFromAbsoluteCoordinate(getPositionOf(i));
			XYLocation loc = new XYLocation(res[0], res[1]);
			retVal.add(loc);

		}
		return retVal;
	}

	public void setBoard(List<XYLocation> locs) {

		int count = 0;

		for (int i = 0; i < locs.size(); i++) {
			XYLocation loc = locs.get(i);
			this.setValue(loc.getXCoOrdinate(), loc.getYCoOrdinate(), count);
			count = count + 1;
		}
	}

	public boolean canMoveGap(String where) {
		if (board[Integer.parseInt(where)] == 0) {
			return false;
		} else {
			return true;
		}
	}

	@Override
	public String toString() {
		String retVal = board[0] + " " + board[1] + " " + board[2] + "\n"
				+ board[3] + " " + board[4] + " " + board[5] + " " + "\n"
				+ board[6] + " " + board[7] + " " + board[8];
		return retVal;
	}

}
