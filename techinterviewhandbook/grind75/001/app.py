from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        
        for idx, value in enumerate(nums):
            exp = target - value
            if exp in m:
                return [idx, m[exp]]
            m[value] = idx
            
        return []
        
if __name__ == '__main__':
    s = Solution()
    print(s.twoSum([2,7,11,15], 9)) # expected [0,1]