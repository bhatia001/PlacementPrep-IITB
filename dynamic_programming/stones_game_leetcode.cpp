class Solution {
    vector<int> arr;
    vector<vector<int>> dp;
    map<pair<int,int>, bool> vis;
public:
    
    int go(int lo, int hi) {
        //base case
        if(lo + 1 == hi) return abs(arr[lo] - arr[hi]);
        
        // incorporating dp
        if(vis[{lo, hi}]) return dp[lo][hi];
        
        vis[{lo, hi}] = 1;
        
        // case 1
        int maxPointsForCurrentPlayer = arr[lo] - go(lo + 1, hi);
        // case 2
        maxPointsForCurrentPlayer = max(maxPointsForCurrentPlayer, arr[hi] - go(lo, hi-1));
        dp[lo][hi] = maxPointsForCurrentPlayer;
        return maxPointsForCurrentPlayer;
    }
    
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        arr = piles;
        dp.resize(n, vector<int>(n, 0));
        int Apoints = go(0, piles.size()-1);
        if(Apoints < 0) 
            return 0;
        else 
            return 1;
    }
};