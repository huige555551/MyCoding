import java.util.*;

public class Solution
{
	public static int[] start = new int[9];
	public static int[] last = new int[9];
	public static int[] pegs = new int[6];
	public static int[][] steps = new int[9][2];
	public static int minSteps = 7;
	public static int[][] optimSteps = new int[9][2];
	public static int N = -1;
	public static int K = -1;
	public static int MAX = 100;

	public static int oldi;
	public static int oldj;
	public static int old;

	public static void print()
	{
		System.out.print(minSteps);
		System.out.print("\n");
		for (int i = 1; i <= minSteps; ++i)
		{
			System.out.print(optimSteps[i][0]);
			System.out.print(" ");
			System.out.print(optimSteps[i][1]);
			System.out.print("\n");
		}
	}

	public static void initPeg()
	{
		for (int i = 1; i <= K; ++i)
		{
			pegs[i] = MAX;
			for (int j = 1; j <= N; ++j)
			{
				if (start[j] == i)
				{
					pegs[i] = j;
					break;
				}
			}
		}
	}

	public static void fun(int depth) //steps: 0-7
	{
		if (depth++ >= minSteps)
			return;

		for (int i = 1; i <= K; ++i)
		{
			for (int j = 1; j <= K; ++j)
			{
				if (pegs[i] < pegs[j]) // possible step, go ahead!
				{
					int disc = pegs[i];
					start[pegs[i]] = j;
					Solution.initPeg();
					steps[depth][0] = i;
					steps[depth][1] = j;

					//after the switch 
					boolean flag = true;
					for (int idx = 1; idx <= N; ++idx)
						if (start[idx] != last[idx])
						{
							flag = false;
							break;
						}
					if (flag == true) //find one
					{
						minSteps = depth;
						for (int idx = 1; idx <= depth; ++idx)
						{
							optimSteps[idx][0] = steps[idx][0];
							optimSteps[idx][1] = steps[idx][1];
						}
						return;
					}
					else //not a result
					{
						Solution.fun(depth);
					}
					start[disc] = i;
					Solution.initPeg();
				}
			}
		}
	}


	public static void main(String arg[])
	{
		Scanner sc=new Scanner(System.in);
		N=sc.nextInt();
		K=sc.nextInt();
		for (int i = 1; i <= N; ++i)
			start[i]=sc.nextInt();
		for (int i = 1; i <= N; ++i)
			last[i]=sc.nextInt();
		Solution.initPeg();

		Solution.fun(0);
		Solution.print();

	}
}