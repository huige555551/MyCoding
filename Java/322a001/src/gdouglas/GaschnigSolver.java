/*
 * Created on Sep 12, 2004
 *
 */
package gdouglas;

import java.util.Iterator;
import java.util.List;
import java.util.Properties;

import aima.search.framework.GraphSearch;
import aima.search.framework.Problem;
import aima.search.framework.Search;
import aima.search.framework.SearchAgent;
import aima.search.informed.AStarSearch;
import aima.search.informed.GreedyBestFirstSearch;

/**
 * @author Ravi Mohan
 * 
 */

public class GaschnigSolver {
	static GaschnigBoard boardWithThreeMoveSolution = new GaschnigBoard(
			new int[] { 1, 2, 5, 3, 4, 0, 6, 7, 8 });
	
	static GaschnigBoard experiment1 = new GaschnigBoard(new int[] { 3, 6, 0,
			2, 7, 4, 1, 8, 5});
	
	static GaschnigBoard experiment2 = new GaschnigBoard(new int[] { 0, 8, 7,
			6, 5, 4, 3, 2, 1 });
	
	static GaschnigBoard experiment3 = new GaschnigBoard(new int[] { 1, 4, 2,
			7, 5, 8, 3, 0, 6 });

	public static void main(String[] args) {
		runExperiment(boardWithThreeMoveSolution);
		//runExperiment(experiment1);
		//runExperiment(experiment2);
		//runExperiment(experiment3);
	}
	
	private static void runExperiment(GaschnigBoard board) {
		System.out.println("\n\n");
		System.out.println("Board tested: ");
		System.out.println(board.toString());
		
		gaschnigGreedyBestFirst(board);
		gaschnigAStar(board);
	}

	private static void gaschnigGreedyBestFirst(GaschnigBoard board) {
		System.out
				.println("\nGaschnig Puzzle Greedy Best First Search (MisplacedTileHeursitic)-->");
		try {
			Problem problem = new Problem(board,
					new GaschnigSuccessorFunction(),
					new GaschnigGoalTest(),
					new MisplacedTilleHeuristicFunction());
			Search search = new GreedyBestFirstSearch(new GraphSearch());
			SearchAgent agent = new SearchAgent(problem, search);
			printActions(agent.getActions());
			printInstrumentation(agent.getInstrumentation());
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	private static void gaschnigAStar(GaschnigBoard board) {
		System.out
				.println("\nGaschnig Puzzle AStar Search (MisplacedTileHeursitic)-->");
		try {
			Problem problem = new Problem(board,
					new GaschnigSuccessorFunction(),
					new GaschnigGoalTest(),
					new MisplacedTilleHeuristicFunction());
			Search search = new AStarSearch(new GraphSearch());
			SearchAgent agent = new SearchAgent(problem, search);
			printActions(agent.getActions());
			printInstrumentation(agent.getInstrumentation());
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	private static void printInstrumentation(Properties properties) {
		Iterator<Object> keys = properties.keySet().iterator();
		while (keys.hasNext()) {
			String key = (String) keys.next();
			String property = properties.getProperty(key);
			System.out.println(key + " : " + property);
		}

	}

	private static void printActions(List actions) {
		for (int i = 0; i < actions.size(); i++) {
			String action = (String) actions.get(i);
			System.out.println(action);
		}
	}

}