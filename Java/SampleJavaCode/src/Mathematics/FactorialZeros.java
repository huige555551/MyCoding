package Mathematics;

public class FactorialZeros
{
    static int numZeros(int num)
    {
        int count = 0;
        if (num < 0)
        {
            System.out.println("Invalid input");
            return 0;
        }

        for (int i = 5; num / i > 0; i *= 5)
        {
            count += num / i;
        }
        return count;
    }

    public static void main(String args[])
    {
        System.out.println(numZeros(500));
    }
}
