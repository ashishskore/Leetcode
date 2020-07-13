func threeSumClosest(nums []int, target int) int {
  // Constant definitions
	const MaxUint = ^uint(0)
	// const MinUint = 0

	const MaxInt = int(^uint(0) >> 1)
	// const MinInt = -MaxInt - 1
    
  sort.Ints(nums)
	var diff = 10000
	var ans = 0
	
	for i := 0; i < len(nums)-2; i++ {
		j := i+1
		k := len(nums)-1
		for j < k {
			sum := nums[i]+nums[j]+nums[k]
			curdiff := target - sum
			if curdiff == 0 {
				return target
			}
			if diff > int(math.Abs(float64(curdiff))) {
				ans = sum
				diff = int(math.Abs(float64(target - sum)))
			}
			if curdiff > 0 {
				j++
			} else {
				k--
			}
		}
	}
	return ans
}
