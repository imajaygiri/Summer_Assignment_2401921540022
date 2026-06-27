public class InnerClassDemo {
    public void display(String display) {
        System.out.println("Outer displaying: " + display);
    }

    public class Inner {
        public void display(String display) {
            System.out.println("Inner displaying: " + display);
        }
    }
}
