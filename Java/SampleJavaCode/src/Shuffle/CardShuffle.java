package Shuffle;

public class CardShuffle {

    static void shuffleArray(int[] cards) {
        int temp, index;
        for (int i = 0; i < cards.length; i++) {
            double t = Math.random();
            index = (int) (Math.random() * (cards.length - i)) + i;
            temp = cards[i];
            cards[i] = cards[index];
            cards[index] = temp;
        }
    }

    public static void main(String args[]) {
        int cards[]=new int[52];
        shuffleArray(cards);
    }
}
