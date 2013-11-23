package SingletonPattern;

/**
 * The nested class is referenced no earlier (and therefore loaded no earlier by the class loader)
 * than the moment that getInstance() is called. Thus, this solution is thread-safe without
 * requiring special language constructs (i.e. volatile or synchronized).
 **/
class SingletonClass2
{
    // Private constructor prevents instantiation from other classes
    private SingletonClass2()
    {
    }

    /**
     * SingletonHolder is loaded on the first execution of SingletonClass2.getInstance()
     * or the first access to SingletonHolder.INSTANCE, not before.
     */
    private static class SingletonHolder
    {
        public static final SingletonClass2 INSTANCE = new SingletonClass2();
    }

    public static SingletonClass2 getInstance()
    {
        return SingletonHolder.INSTANCE;
    }
}

public class Singleton2
{
    public static void main(String[] args)
    {

        SingletonClass2 instance1 = SingletonClass2.getInstance();
        SingletonClass2 instance2 = SingletonClass2.getInstance();

        if (instance1 == instance2)
        {
            System.out.println("Both the references are pointing to the same object");
        }
        else
        {
            System.out.println("Objects are not equal");
        }
    }
}
