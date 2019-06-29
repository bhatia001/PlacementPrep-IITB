#include "bits/stdc++.h"

using namespace std;

const int N = 1e3;
int A[N], n;
int dp[N][N], vis[N][N];

int ways(int pos, int S) {
	// base case
	if(pos == n) return S == 0;

	// dp initialization
	int &ans = dp[pos][S];
	if(vis[pos][S]) return ans;

	// dp working
	vis[pos][S] = 1;
	ans = 0;
	int times = 0;
	while(S >= times*A[pos]) {
		ans += ways(pos + 1, S - times*A[pos]);
		times ++ ;
	}	
	return ans;
}

int fasterWays(int pos, int S) {
	if(pos == n) return S == 0;

	int &ans = dp[pos][S];

	if(vis[pos][S]) return ans;

	vis[pos][S] = 1;
	ans = 0;

	ans = fasterWays(pos, S-A[pos]) + fasterWays(pos+1, S);

	return ans;
}


int main() {
	int i, S;
	cin >> n >> S;
	for(i=0; i<n; i++) cin >> A[i];	
	cout << fasterWays(0, S) << endl;
	return 0;
}