pub struct Point {
    x: i32,
    y: i32,
}

impl Point {
    pub fn new(x: i32, y: i32) -> Self {
        Self { x, y }
    }

    pub fn set_x(&mut self, x: i32) {
        self.x = x;
    }
    pub fn set_y(&mut self, y: i32) {
        self.y = y;
    }

    pub fn sex_xy(&mut self, x: i32, y: i32) {
        self.x = x;
        self.y = y;
    }

    pub fn show(&self) {
        println!("x: {} y: {}", self.x, self.y);
    }
}
