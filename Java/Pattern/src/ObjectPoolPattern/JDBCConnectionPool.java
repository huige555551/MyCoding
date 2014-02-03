package ObjectPoolPattern;

import ObjectPoolPattern.Connection;

public class JDBCConnectionPool extends ObjectPool<Connection> {
	private String dsn;
	private String usr;
	private String pwd;
	
	public JDBCConnectionPool(String dsn, String usr, String pwd) {
		
		super();
		
		/*try {
			Class.forName(driver).newInstance();
		} catch (Exception e) {
			e.printStackTrace();
		}*/
		
		this.dsn = dsn;
		this.usr = usr;
		this.pwd = pwd;
	}
	
	@Override
	public Connection create() {
		Connection con = new Connection(dsn, usr, pwd);
		return con;
	}
	
	@Override
	public boolean validate(Connection o) {
		return o.isClosed();
	}
	
	@Override
	public void expire(Connection o) {
		o.close();
	}
	
	
}
