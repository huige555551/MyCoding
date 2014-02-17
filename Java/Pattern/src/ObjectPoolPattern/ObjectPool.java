package ObjectPoolPattern;

import java.util.Enumeration;
import java.util.Hashtable;

public abstract class ObjectPool<T> {

	private long expirationTime;
	private Hashtable<T, Long> locked;	//OBJECTS THAT ARE IN USE
	private Hashtable<T, Long> unlocked;//OBJECTS THAT ARE NOT IN USE BUT CREATED
	
	public ObjectPool() {
	    expirationTime = 30000; // 30 seconds
	    locked = new Hashtable<T, Long>();
	    unlocked = new Hashtable<T, Long>();
	}
	
	public abstract T create();
	public abstract boolean validate(T o);
	public abstract void expire(T o);
	
	//GET AN OBJECT FROM POOL OR CREATE A NEW ONE
	//Iterate through all unlocked objects
	//	if object_time_is_expired:
	//		EXPIRE(object)
	//	else:
	//		if VALIDATE(object):
	//			remove it from unlocked_hash
	//			put object in locked_hash
	//			return
	//		else
	//			EXPIRE(object)
	public synchronized T checkOut() 
	{
		long now = System.currentTimeMillis();
		T t;

		if (unlocked.size() > 0) {
			
			Enumeration<T> e = unlocked.keys();
  
			while (e.hasMoreElements()) {
				
				t = e.nextElement();
    
				if ((now - unlocked.get(t)) > expirationTime) {
					// object has expired
					unlocked.remove(t);
					expire(t);
					t = null;
				} 
				else {
					if (validate(t)) {
						unlocked.remove(t);
						locked.put(t, now);
						return (t);
					} 
					else {
						// object failed validation
						unlocked.remove(t);
						expire(t);
						t = null;
					}
				}
			}
		}

		// no objects available, create a new one
		t = create();
		locked.put(t, now);
		return (t);
	}
	
	//return the object into the pool
	public synchronized void checkIn(T t) 
	{
		locked.remove(t);
		unlocked.put(t, System.currentTimeMillis());
	}
}
