class Solution {
    int solve(vector<int>&nums, int start, vector<int>& memo){
        int n = nums.size();
        if(start >= n - 1) return 1;
        if(memo[start] != -1) return memo[start];
        for(int i = 1; i <= nums[start]; i++){
            if(solve(nums, start + i, memo)) return memo[start] = 1;
        }
        return memo[start] = 0;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, 0, memo);
    }
};
