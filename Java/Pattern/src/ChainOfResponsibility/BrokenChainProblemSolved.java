package ChainOfResponsibility;

class Request_1 {

    private int m_value;
    private String m_description;

    public Request_1(String description, int value) {
        m_description = description;
        m_value = value;
    }

    public int getValue() {
        return m_value;
    }

    public String getDescription() {
        return m_description;
    }
}

abstract class Handler_1 {

    private Handler_1 m_successor;

    public void setSuccessor(Handler_1 successor) {
        m_successor = successor;
    }

    protected abstract boolean handleRequestImpl(Request_1 request);

    public final void handleRequest(Request_1 request) {

        boolean handledByThisNode = this.handleRequestImpl(request);

        if (m_successor != null && !handledByThisNode) {
            m_successor.handleRequest(request);
        }
    }
}

class ConcreteHandlerOne_1 extends Handler_1 {

    @Override
    protected boolean handleRequestImpl(Request_1 request) {
        if (request.getValue() < 0) {           //if request is eligible handle it

            System.out.println("Negative values are handled by ConcreteHandlerOne_1:");
            System.out.println("\tConcreteHandlerOne_1.HandleRequest : " + request.getDescription() + request.getValue());

            return true;

        } // if not
        else {
            return false;
        }
    }
}

class ConcreteHandlerThree_1 extends Handler_1 {

    @Override
    protected boolean handleRequestImpl(Request_1 request) {

        if (request.getValue() >= 0) {           //if request is eligible handle it

            System.out.println("Zero values are handled by ConcreteHandlerThree_1:");
            System.out.println("\tConcreteHandlerThree_1.HandleRequest : " + request.getDescription() + request.getValue());

            return true;
        } // if not
        else {
            return false;
        }

    }
}

class ConcreteHandlerTwo_1 extends Handler_1 {

    @Override
    protected boolean handleRequestImpl(Request_1 request) {

        if (request.getValue() > 0) {           //if request is eligible handle it

            System.out.println("Positive values are handled by ConcreteHandlerTwo_1:");
            System.out.println("\tConcreteHandlerTwo_1.HandleRequest : " + request.getDescription() + request.getValue());

            return true;
        } // if not
        else {
            return false;
        }

    }
}

public class BrokenChainProblemSolved {

    public static void main(String[] args) {

        // Setup Chain of Responsibility
        Handler_1 h1 = new ConcreteHandlerOne_1();
        Handler_1 h2 = new ConcreteHandlerTwo_1();
        Handler_1 h3 = new ConcreteHandlerThree_1();

        h1.setSuccessor(h2);
        h2.setSuccessor(h3);

        // Send requests to the chain
        h1.handleRequest(new Request_1("Negative Value ", -1));
        h1.handleRequest(new Request_1("NonNegative Value ", 0));
        h1.handleRequest(new Request_1("Positive Value ", 1));
        h1.handleRequest(new Request_1("Positive Value ", 2));
        h1.handleRequest(new Request_1("Negative Value ", -5));

    }
}

