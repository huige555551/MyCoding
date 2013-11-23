package FactoryPattern;

abstract class Button {

    public abstract void draw();
}

class WindowsButton extends Button {

    @Override
    public void draw() {
        System.out.println("Drawing Windows Button");
    }
}

class LinuxButton extends Button {

    @Override
    public void draw() {
        System.out.println("Drawing Linux Button");
    }
}

class ButtonFactory {

    public static Button createButton(String os) {
        if (os.equals("Windows")) {
            return new WindowsButton();
        } else if (os.equals("Linux")) {
            return new LinuxButton();
        }
        return null;
    }
}

public class Factory2 {

    public static void main(String[] args) {
        Button windowsButton = ButtonFactory.createButton("Windows");
        windowsButton.draw();

        Button linuxButton = ButtonFactory.createButton("Linux");
        linuxButton.draw();
    }
}

