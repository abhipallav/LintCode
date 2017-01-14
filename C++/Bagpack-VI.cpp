Problem: http://www.lintcode.com/en/problem/backpack-vi/

class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
        // Write your code here
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]<=i)
                    dp[i]+=dp[i-nums[j]];
            }
        }
        
        return dp.back();
    }
};