fn max_sub_array(nums: Vec<i32>) -> i32 {
    let mut curr_sum = nums[0];
    let mut max_sum = nums[0];

    for i in 1..nums.len() {
        curr_sum = std::cmp::max(nums[i], curr_sum + nums[i]);
        max_sum = std::cmp::max(curr_sum, max_sum);
    }
    max_sum
}

fn main() {
    let nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
    let res = max_sub_array(nums);
    assert_eq!(6, res);
}
