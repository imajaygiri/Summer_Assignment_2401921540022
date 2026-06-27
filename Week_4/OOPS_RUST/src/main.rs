use OOPS_RUST::{arithmetic::Arithmetic, inner_demo::Outer, point::Point, test::Test};

fn main() {
    println!("TESTING: ARITHMETIC");
    let sq = Arithmetic::square(10);
    println!("Square: {sq}");

    println!("TESTING: POINT");
    let mut p = Point::new(10, 20);
    p.show();
    p.set_x(100);

    println!("TESTING: INNERCLASSDEMO");
    Outer::display("from outer class".to_string());
}
