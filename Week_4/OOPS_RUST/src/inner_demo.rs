pub struct Inner {}
impl Inner {
    pub fn display(display: String) {
        println!("Inner: {display}");
    }
}
pub struct Outer {
    pub inner: Inner,
}
impl Outer {
    pub fn new() -> Self {
        Self { inner: Inner {} }
    }
    pub fn display(display: String) {
        println!("Outer: {display}");
    }
}
