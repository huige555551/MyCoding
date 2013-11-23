
public class IntPair {
	public int x;
	public int y;
	
	public IntPair(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
	
	public boolean equals(Object o)
	{
		IntPair p = (IntPair)o;
		return (p.x == this.x && p.y == this.y);
	}
	
	public String toString()
	{
		return "(" + x + ", " + y + ")";
	}
}
