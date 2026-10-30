class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        runway =0
        for i in range (n):
            if runway<i:
                return False
            runway = max(runway, i+nums[i])
        
        return True
        