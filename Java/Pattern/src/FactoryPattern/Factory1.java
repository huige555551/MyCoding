package FactoryPattern;

interface Dog {

    public void speak();
}

class Poodle implements Dog {

    public void speak() {
        System.out.println("The poodle says \"arf\"");
    }
}

class Rottweiler implements Dog {

    public void speak() {
        System.out.println("The Rottweiler says (in a very deep voice) \"WOOF!\"");
    }
}

class SiberianHusky implements Dog {

    public void speak() {
        System.out.println("The husky says \"Dude, what's up?\"");
    }
}

class DogFactory {

    public static Dog getDog(String criteria) {
        if (criteria.equals("small")) {
            return new Poodle();
        } else if (criteria.equals("big")) {
            return new Rottweiler();
        } else if (criteria.equals("working")) {
            return new SiberianHusky();
        }

        return null;
    }
}

/**
 * A "driver" program to demonstrate our "dog factory".
 * @author alvin alexander, devdaily.com
 */
public class Factory1 {

    public static void main(String[] args) {
    	
    	Dog[] d = new Dog[2];
    	
        // create a small dog
        d[0] = DogFactory.getDog("small");
        d[0].speak();

        // create a big dog
        d[1] = DogFactory.getDog("big");
        d[1].speak();

        // create a working dog
        Dog dog = DogFactory.getDog("working");
        dog.speak();
        
     // create a big dog
        dog = DogFactory.getDog("big");
        dog.speak();
    }
}
