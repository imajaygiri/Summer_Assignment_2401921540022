use std::collections::HashMap;
pub fn contains_duplicate(nums: Vec<i32>) -> bool {
    let mut hash = HashMap::<i32, u32>::new();

    for num in nums {
        let element_ref = hash.entry(num).or_insert(0);

        *element_ref += 1;

        if *element_ref > 1 {
            return true;
        }
    }

    // for (k, v) in hash.iter() {
    //     println!("key: {} value: {}", *k, *v);
    // }
    return false;
}

fn main() {
    let nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2];
    let res = contains_duplicate(nums.to_vec());
    assert_eq!(true, res);
}
