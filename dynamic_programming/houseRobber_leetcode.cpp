class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp(n+2,0);
        
        // dp[i] = maximum profit till ith house
        // dp[i-1] = max profit till (i-1)th house
        // dp[i+1] = max profit till (i+1)th house
        int i;
        for(i=0;i<n;i++) {
            // basically nums[i] corresponding to the (i+1)th house
            dp[i+2] = dp[i+1]; 
            dp[i+2] = max(dp[i+2], nums[i] + dp[i]); 
            
        }
        return dp[n+1];
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        
        // dp[i] = maximum profit till ith house
        // dp[i-1] = max profit till (i-1)th house
        // dp[i+1] = max profit till (i+1)th house
        
        int ppMax = 0;
        int pMax = 0;
        int curMax = 0;
        int i;
        for(i=0;i<n;i++) {
            // basically nums[i] corresponding to the (i+1)th house
            curMax = pMax; 
            curMax = max(curMax, nums[i] + ppMax); 
            ppMax = pMax;
            pMax = curMax;
            
        }
        return curMax;
    }
};


