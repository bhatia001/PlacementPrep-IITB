class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> f(n, INT_MAX-1);
        
        f[n-1] = 0;
        
        
        for(int i=n-2;i>=0;i--) {
            
            for(int j=i+1;j<=i+nums[i] && j < n;j++) {
                
                f[i] = min(f[i], 1 + f[j]);
                
            }
            
            
        }
    
        return f[0];
    }
    
};

// O(n) solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 2) return 0;
        int maxIndexReachable = nums[0];
        int lim = maxIndexReachable; // nums[0]
        int ans = 1; // already considering 1 jump
        
        for(int i=1;i<n;i++) {
            if(i > lim) { // we have iterated over all the possible values 
                ans++;
                lim = maxIndexReachable;
            }
            // maxIndexReachable is updated at every iteration
            maxIndexReachable = max(maxIndexReachable, i+nums[i]);
        }
        return ans;
    }
    
};