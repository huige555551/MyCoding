package SingletonPattern;

/**
This solution is thread-safe without requiring special language constructs,
but it lacks the laziness of the one below. The INSTANCE is created as
soon as the Singleton class is initialized. That might even be long before
getInstance() is called.
 **/
class SingletonClass1
{
    private static final SingletonClass1 INSTANCE = new SingletonClass1();

    // Private constructor prevents instantiation from other classes
    private SingletonClass1()
    {
    }

    public static SingletonClass1 getInstance()
    {
        return INSTANCE;
    }
}

public class Singleton1
{
    public static void main(String[] args)
    {

        SingletonClass1 instance1 = SingletonClass1.getInstance();
        SingletonClass1 instance2 = SingletonClass1.getInstance();

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
