class Solution {
    func subarraysWithKDistinct(_ nums: [Int], _ k: Int) -> Int {
        var atk = atmostK(nums, k)
        var atkone = atmostK(nums, k - 1)
        return atk - atkone
    }
    
    func atmostK(_ nums: [Int],_ k: Int) -> Int {
        var dict : [Int : Int] = [:]
        let len = nums.count - 1
        var ans = 0
        var j = 0
        
        for i in 0...len {
            if dict[nums[i]] == nil {
                dict[nums[i]] = 1
            }
            else {
                dict[nums[i]]! += 1
            }
            if (dict.count > k) {
                while (dict.count > k) {
                    dict[nums[j]]! -= 1
                    if dict[nums[j]] == 0 {
                        dict[nums[j]] = nil
                    }
                    j += 1
                }
            }
            ans += (i - j + 1)
        }
        return ans
    }
}

// [1,2,1,3,4,1,2,1,2,3]