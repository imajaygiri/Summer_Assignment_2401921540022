use Day_2::*;
fn main() {
    let nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
    let res = max_sub_array(nums.to_vec());
    assert_eq!(6, res);

    let nums = [1, 12, -5, -6, 50, 3];
    let k = 4 as i32;
    assert_eq!(12.75000, find_max_average(nums.to_vec(), k));

    let nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2];
    let res = contains_duplicate(nums.to_vec());
    assert_eq!(true, res);
}
