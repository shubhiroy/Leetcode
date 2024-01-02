
func containsDuplicate(nums []int) bool {
	hashSet := make(map[int]int)
	for _, val := range nums {
		_, exists := hashSet[val]
		if exists {
			return true
		}
		hashSet[val] = 1
	}
	return false
}

// func containsDuplicate(nums []int) bool {
// 	for ind, val := range nums {
// 		for i := ind + 1; i < len(nums); i++ {
// 			if val == nums[i] {
// 				return true
// 			}
// 		}
// 	}
// 	return false
// }
