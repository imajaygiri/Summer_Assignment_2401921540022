pub struct Box {
    pub length: i32,
    pub breadth: i32,
}

impl Box {
    pub fn new(length: i32, breadth: i32) -> Self {
        Self { length, breadth }
    }

    pub fn area(&self) -> i32 {
        self.length * self.breadth
    }
}

pub struct Box3d {
    _box: Box,
    height: i32,
}

impl Box3d {
    pub fn new(length: i32, breadth: i32, height: i32) -> Self {
        Self {
            _box: Box::new(length, breadth),
            height,
        }
    }

    pub fn volume(&self) -> i32 {
        self._box.area() * self.height
    }

    pub fn area(&self) -> i32 {
        let lh = self._box.length * self.height;
        let bh = self._box.breadth * self.height;
        let bl = self._box.breadth * self._box.length;
        2 * (lh + bh + bl)
    }
}
