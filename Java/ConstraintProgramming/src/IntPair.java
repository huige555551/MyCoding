
public class IntPair {
	public int x;
	public int y;

	public IntPair(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	@Override
	public String toString() {
		return "IntPair [x=" + x + ", y=" + y + "]";
	}	
	
	@Override
	public int hashCode() {
		final int prime = 31;		
		int k = ((x+y)<<5) | ((x+y)>>27);
		int result = (prime * k + 11)%1000;		
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		IntPair other = (IntPair) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}	
	
}
