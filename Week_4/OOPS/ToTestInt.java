
public class ToTestInt {
    public static void main(String[] args) {
        System.out.println("############## TEST: ARITHMETIC ###############");
        Test t = new Arithmetic();
        System.out.println("Square: " + t.square(10));

        InnerClassDemo outer = new InnerClassDemo();
        outer.display("i'm outer class");

        InnerClassDemo.Inner inner = outer.new Inner();
        inner.display("i'm innner class");

        System.out.println("############## TEST: POINT ###############");

        Point p = new Point(10, 20);
        p.show();
        p.setX(100);
        p.show();
        p.setY(200);
        p.show();
        p.setXY(199, 999);
        p.show();

        System.out.println("############## TEST: BOX-3D ###############");
        Box3d bx3d = new Box3d(10, 20, 30);

        System.out.println("AREA: " + bx3d.Area());
        System.out.println("VOL: " + bx3d.Volume());
    }
}
