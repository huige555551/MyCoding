package ObjectPoolPattern;

public class Main {

	public static void main(String[] args) {
		// Do something...
	    //...

	    // Create the ConnectionPool:
	    JDBCConnectionPool pool = new JDBCConnectionPool( "mydb", "sa", "secret");

	    // Get a connection:
	    Connection con = pool.checkOut();

	    // Use the connection
	    //...

	    // Return the connection:
	    pool.checkIn(con);

	}

}


//http://www.javaworld.com/article/2076690/java-concurrency/build-your-own-objectpool-in-java-to-boost-app-speed.html
//http://best-practice-software-engineering.ifs.tuwien.ac.at/patterns/objectpool.html