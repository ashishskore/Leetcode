func fourSum(nums []int, target int) [][]int{
	sort.Ints(nums)
	// fmt.Println(nums)
	var ret [][]int 
	var sum int
	for i := 0; i < len(nums)-3; i++ {
		// if nums[i] > target {
		// 	return ret
		// }
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i+1; j < len(nums)-2; j++ {
			// fmt.Println(nums[i], nums[j])
			if j > 1 && j-i > 1 && nums[j-1] == nums[j]{
				continue
			}
			k := j+1
			l := len(nums)-1
			for k<l{
				sum = nums[i] + nums[j] + nums[k] + nums[l]
				// fmt.Print(nums[i],nums[j],nums[k],nums[l], sum)
				
				if target == sum {
					// fmt.Println("=")
					ret = append(ret , []int {nums[i], nums[j],nums[k],nums[l]})
					k++
					l--
					for k<l && nums[k-1]==nums[k]{
						k++
					}
					for k<l && nums[l] == nums[l+1]{
						l--
					}
				} else if target > sum{
					// fmt.Println(">")
					k++
					for k<l && nums[k-1]==nums[k]{
						k++
					}
				} else {
					// fmt.Println("<")
					l--
					for k<l && nums[l] == nums[l+1]{
						l--
					}
				}
			}
		}
	}
	return ret
}
