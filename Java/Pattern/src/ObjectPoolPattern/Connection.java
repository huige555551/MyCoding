package ObjectPoolPattern;

public class Connection {
	private String dsn;
	private String usr;
	private String pwd;
	private boolean closed;
	
	public Connection(String dsn, String usr, String pwd) {
		this.dsn = dsn;
		this.usr = usr;
		this.pwd = pwd;
		this.closed = false;
	}
	
	public boolean isClosed() {
		return closed;		
	}
	
	public void close() {
		this.closed = true;
	}

	
	public String getDsn() {
		return dsn;
	}
	
	public void setDsn(String dsn) {
		this.dsn = dsn;
	}

	public String getUsr() {
		return usr;
	}

	public void setUsr(String usr) {
		this.usr = usr;
	}

	public String getPwd() {
		return pwd;
	}

	public void setPwd(String pwd) {
		this.pwd = pwd;
	}

}
