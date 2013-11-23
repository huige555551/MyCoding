package ObserverPattern;

import java.util.Observable;

/**
 * A subject to observe!
 * But this subject already extends another class.
 * So use a contained DelegatedObservable object.
 * Note that in this version of SpecialSubject we do
 * not duplicate any of the interface of Observable.
 * Clients must get a reference to our contained
 * Observable object using the getObservable() method.
 */
class SpecialSubject extends Object {

    private String name;
    private float price;
    private DelegatedObservable obs;

    public SpecialSubject(String name, float price) {
        this.name = name;
        this.price = price;
        obs = new DelegatedObservable();
    }

    public String getName() {
        return name;
    }

    public float getPrice() {
        return price;
    }

    public Observable getObservable() {
        return obs;
    }

    public void setName(String name) {
        this.name = name;
        obs.setChanged();
        obs.notifyObservers(name);
    }

    public void setPrice(float price) {
        this.price = price;
        obs.setChanged();
        obs.notifyObservers(new Float(price));
    }
}

// A subclass of Observable that allows delegation.
class DelegatedObservable extends Observable {

    @Override
    public void clearChanged() {
        super.clearChanged();
    }

    @Override
    public void setChanged() {
        super.setChanged();
    }
}


// Test program for SpecialSubject with a Delegated Observable.
class TestSpecial {

    public static void main(String args[]) {

        // Create the Subject and Observers.
        SpecialSubject s = new SpecialSubject("Corn Pops", 1.29f);
        NameObserver nameObs = new NameObserver();
        PriceObserver priceObs = new PriceObserver();

        // Add those Observers!
        s.getObservable().addObserver(nameObs);
        s.getObservable().addObserver(priceObs);

        // Make changes to the Subject.
        s.setName("Frosted Flakes");
        s.setPrice(4.57f);
        s.setPrice(9.22f);
        s.setName("Sugar Crispies");
    }
}


/**
 * Apparently, the designers of Observable felt that only subclasses
 * of Observable (that is, "true" observable subjects) should be able
 * to modify the state-changed flag
 *
 * If SpecialSubject contains an Observable object, it could not
 * invoke the setChanged() and clearChanged() methods on it
 *
 * So we have DelegatedObservable extend Observable and override
 * these two methods making them have public visibility
 *
 * Java rule: An subclass can changed the visibility of an overridden
 * method of its superclass, but only if it provides more access
 */