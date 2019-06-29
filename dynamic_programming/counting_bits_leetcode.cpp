// overall solution = O(NlogN)

class Solution {
public:
    // O(logN) in average case
    int getOnes(int x) {
        int ans = 0;
        while(x) {
            ans++;
            x = x - (x&-x); // neat trick 
        }    
        return ans;
    }
    
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0;i<=num;i++) {
            // ans.push_back(getOnes(i));
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};


// DP Approach :- 
// overall solution = O(N)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>arr(num+1,0);
        for(int i=1;i<=num;i++){
            if(i%2==0){
                arr[i]=arr[i/2];
            }
            else
                arr[i]=arr[i/2]+1;
        }
        return arr;
    }
};