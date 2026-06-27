use crate::test::Test;
pub struct Arithmetic{}
impl Test for Arithmetic {
    fn square(x: i32) -> i32 {
        x * x
    }
}
