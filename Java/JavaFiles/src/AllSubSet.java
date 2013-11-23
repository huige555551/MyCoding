import java.util.ArrayList;

public class AllSubSet {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArrayList<Integer> v = new ArrayList<Integer>();
		v.add(1);
		v.add(2);
		v.add(3);
		
		ArrayList<ArrayList<Integer>> subsets = getSubsets(v, 0);
		
		System.out.println(subsets);
	}
	
	static ArrayList<ArrayList<Integer>> getSubsets(ArrayList<Integer> set, int index) 
	{
		 ArrayList<ArrayList<Integer>> allsubsets;
		 
		 if (set.size() == index) {
			 allsubsets = new ArrayList<ArrayList<Integer>>();
			 allsubsets.add(new ArrayList<Integer>()); // Empty set
		 } else {
			 allsubsets = getSubsets(set, index + 1);
			 int item = set.get(index);
			 ArrayList<ArrayList<Integer>> moresubsets =
			 new ArrayList<ArrayList<Integer>>();
			 
			 for (ArrayList<Integer> subset : allsubsets) {
				 ArrayList<Integer> newsubset = new ArrayList<Integer>();
				 newsubset.addAll(subset); //
				 newsubset.add(item);
				 moresubsets.add(newsubset);
			 }
			 allsubsets.addAll(moresubsets);
		 }
		 return allsubsets;
	}

}
