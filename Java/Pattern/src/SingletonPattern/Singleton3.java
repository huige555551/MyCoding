/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package SingletonPattern;

class SingletonClass3
{
    private static SingletonClass3 instance = null;

    private SingletonClass3()
    {
    }

    public static SingletonClass3 getInstance()
    {
        initObject();
        return instance;
    }

    private static void initObject()
    {
        //synchronized (SingletonClass3.class) //for synchronization purpose
        //{
            if (instance == null)
            {
                instance = new SingletonClass3();
            }
        //}
    }
}

public class Singleton3
{
    public static void main(String[] args)
    {

        SingletonClass3 instance1 = SingletonClass3.getInstance();
        SingletonClass3 instance2 = SingletonClass3.getInstance();

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
