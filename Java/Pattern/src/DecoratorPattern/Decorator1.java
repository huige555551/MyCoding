package DecoratorPattern;

/**
 * Window Interface
 *
 * Component window
 */
interface Window {

    public void renderWindow();
}

/**
 * Window implementation
 *
 * Concrete implementation
 */
class SimpleWindow implements Window {

    @Override
    public void renderWindow() {
        // implementation of rendering details
    }
}

class DecoratedWindow implements Window {

    /**
     * private reference to the window being decorated
     */
    private Window privateWindowRefernce = null;

    public DecoratedWindow(Window windowRefernce) {

        this.privateWindowRefernce = windowRefernce;
    }

    @Override
    public void renderWindow() {

        privateWindowRefernce.renderWindow();

    }
}

class ScrollableWindow extends DecoratedWindow {

    /**
     * Additional State
     */
    private Object scrollBarObjectRepresentation = null;

    public ScrollableWindow(Window windowRefernce) {

        super(windowRefernce);

    }

    @Override
    public void renderWindow() {

        // render scroll bar
        renderScrollBarObject();

        // render decorated window
        super.renderWindow();
    }

    private void renderScrollBarObject() {

        // prepare scroll bar
        scrollBarObjectRepresentation = new Object();


        // render scrollbar

    }
}

public class Decorator1 {

    public static void main(String[] args) {


        // create a new window

        Window window = new SimpleWindow();

        window.renderWindow();

        // at some point later
        // maybe text size becomes larger than the window
        // thus the scrolling behavior must be added

        // decorate old window
        window = new ScrollableWindow(window);

        //  now window object
        // has additional behavior / state

        window.renderWindow();

    }
}
//The intent of this pattern is to add additional responsibilities dynamically to an object.

