pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
    let mut curr_sum: i32 = 0;

    for i in 0..k {
        curr_sum += nums[i as usize];
    }

    let mut max_sum = curr_sum;

    for i in k as usize..nums.len() {
        curr_sum += nums[i] - nums[i - k as usize];
        max_sum = std::cmp::max(curr_sum, max_sum);
    }

    max_sum as f64 / k as f64
}
