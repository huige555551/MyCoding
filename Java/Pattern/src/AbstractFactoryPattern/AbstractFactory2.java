package AbstractFactoryPattern;

abstract class AbstractProductA {

    public abstract void operationA1();
    public abstract void operationA2();
}

class ProductA1 extends AbstractProductA {

    ProductA1(String arg) {
        System.out.println("Hello " + arg);
    }

    @Override
    public void operationA1() {
    }

    @Override
    public void operationA2() {
    }    
}

class ProductA2 extends AbstractProductA {

    ProductA2(String arg) {
        System.out.println("Hello " + arg);
    }

    @Override
    public void operationA1() {
    }

    @Override
    public void operationA2() {
    }
}

abstract class AbstractProductB {
    public abstract void operationB1();
    public abstract void operationB2();
}

class ProductB1 extends AbstractProductB {

    ProductB1(String arg) {
        System.out.println("Hello " + arg);
    } // Implement the code here

    @Override
    public void operationB1() {

    }

    @Override
    public void operationB2() {

    }
}

class ProductB2 extends AbstractProductB {

    ProductB2(String arg) {
        System.out.println("Hello " + arg);
    } // Implement the code here

    @Override
    public void operationB1() {

    }

    @Override
    public void operationB2() {

    }
}

abstract class AbstractFactory {

    abstract AbstractProductA createProductA();
    abstract AbstractProductB createProductB();
}

class ConcreteFactory1 extends AbstractFactory {

    AbstractProductA createProductA() {
        return new ProductA1("ProductA1");
    }

    AbstractProductB createProductB() {
        return new ProductB1("ProductB1");
    }
}

class ConcreteFactory2 extends AbstractFactory {

    AbstractProductA createProductA() {
        return new ProductA2("ProductA2");
    }

    AbstractProductB createProductB() {
        return new ProductB2("ProductB2");
    }
}

//Factory creator - an indirect way of instantiating the factories
class FactoryMaker {

    private static AbstractFactory pf = null;

    static AbstractFactory getFactory(String choice) {
        if (choice.equals("a")) {
            pf = new ConcreteFactory1();
        } else if (choice.equals("b")) {
            pf = new ConcreteFactory2();
        }
        return pf;
    }
}

// Client
class Client {

    public static void main(String args[]) {
        AbstractFactory pf = FactoryMaker.getFactory("a");
        AbstractProductA product = pf.createProductA();
        product.operationA1();
        //more function calls on product
    }
}


