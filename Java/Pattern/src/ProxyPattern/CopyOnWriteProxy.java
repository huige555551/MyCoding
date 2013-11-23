package ProxyPattern;

import java.util.Hashtable;

class LargeHashtable extends Hashtable {

    private ReferenceCountedHashTable theHashTable;

    public LargeHashtable() {
        theHashTable = new ReferenceCountedHashTable();
    }

    @Override
    public int size() {
        return theHashTable.size();
    }

    @Override
    public synchronized Object get(Object key) {
        return theHashTable.get(key);
    }

    @Override
    public synchronized Object put(Object key, Object value) {
        copyOnWrite();
        return theHashTable.put(key, value);
    }

    @Override
    public synchronized Object clone() {
        Object copy = super.clone();
        theHashTable.addProxy();
        return copy;

    }

    // This method is called before modifying the underlying
    // Hashtable. If it is being shared then this method clones it.
    private void copyOnWrite() {
        if (theHashTable.getProxyCount() > 1) {
            synchronized (theHashTable) {
                theHashTable.removeProxy();
                try {
                    theHashTable = (ReferenceCountedHashTable) theHashTable.clone();
                } catch (Throwable e) {
                    theHashTable.addProxy();
                }
            }
        }

    }

    private class ReferenceCountedHashTable extends Hashtable {

        private int proxyCount = 1;

        public ReferenceCountedHashTable() {
            super();
        }

        // Return a copy of this object with proxyCount set back to 1.
        @Override
        public synchronized Object clone() {
            ReferenceCountedHashTable copy;
            copy = (ReferenceCountedHashTable) super.clone();
            copy.proxyCount = 1;
            return copy;
        }

        synchronized int getProxyCount() {
            return proxyCount;
        }

        synchronized void addProxy() {
            proxyCount++;
        }

        synchronized void removeProxy() {
            proxyCount--;
        }
    }
}

public class CopyOnWriteProxy {

    public static void main(String args[]) {
        LargeHashtable proxy1 = new LargeHashtable();

        proxy1.put( "1", "One");

        LargeHashtable proxy2 = new LargeHashtable();
        
        proxy2.put( "2", "Two");

        proxy1.put( "11", "OneOne");



    }
}
