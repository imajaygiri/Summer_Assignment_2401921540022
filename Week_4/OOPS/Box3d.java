class Box {
    int length;
    int breadth;

    public Box(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public void SetLen(int length) {
        this.length = length;
    }

    public void SetBeadth(int breadth) {
        this.breadth = breadth;
    }

    public void SetLenBreadth(int length, int breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public int Area() {
        return this.length * this.breadth;
    }
}

public class Box3d extends Box {
    private int height;

    Box3d(int length, int breadth, int height) {
        super(length, breadth);
        this.height = height;
    }

    public int Volume() {
        return this.height * super.length * super.breadth;
    }

    @Override
    public int Area() {
        int lb = this.length * this.breadth;
        int bh = this.breadth * this.height;
        int hl = this.height * this.length;
        return 2 * (lb + bh + hl);
    }

}
