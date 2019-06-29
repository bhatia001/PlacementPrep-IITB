#include <bits/stdc++.h>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 1e7+2, M = N;
//=======================


const int N = 1003;

int dp[N][N], a[N][N], vis[N][N];

int go(int i, int j) {
	// base case 
	if(i == n-1 && j == m-1) 
		return a[i][j];
	
	//incorporation of dp
	if(vis[i][j]) return dp[i][j];

	vis[i][j] = 1;


	int &ans = dp[i][j];

	if(i < n-1 && j < m-1) // HAVEN'T HIT BOTTOM OR RIGHT
		ans = a[i][j] + max(go(i,j+1), go(i+1,j));
	else if(i == n-1) // HIT THE BOTTOM, can only go right
		ans = a[i][j] + go(i,j+1);
	else // HIT THE RIGHT, can only go down
		ans = a[i][j] + go(i+1, j);

	return ans;



}

int main() {
	int i, j;
	cin >> n >> m;
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			cin >> a[i][j];
			
	//Display the matrix
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
			
	//Print the answer
	cout << go(0, 0) << endl;
	//It should be 73 i.e 1+5+9+13+14+15+16
	
	
	return 0;
}


//Input:
//4 4
//1 2 3 4
//5 6 7 8
//9 10 11 12
//13 14 15 16