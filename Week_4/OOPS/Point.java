public class Point {
    private int x, y;

    Point() {
    }

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    void show() {
        System.out.println("X: " + this.x + " Y: " + this.y);
    }
}
