package Shuffle;

public class Count2s {

    static int count2sR(int n) {
        // Base case
        if (n == 0) {
            return 0;
        }

        // 513 into 5 * 100 + 13. [Power = 100; First = 5; Remainder = 13]
        int power = 1;
        while (10 * power < n) {
            power *= 10;
        }
        int first = n / power;
        int remainder = n % power;
        // Counts 2s from first digit
        int nTwosFirst = 0;
        if (first > 2) {
            nTwosFirst += power;
        } else if (first == 2) {
            nTwosFirst += remainder + 1;
        }

        // Count 2s from all other digits
        int nTwosOther = first * count2sR(power - 1) + count2sR(remainder);

        return nTwosFirst + nTwosOther;
    }

    public static void main(String args[]) {
        int n = count2sR(13);

        System.out.println(n);
    }
}
