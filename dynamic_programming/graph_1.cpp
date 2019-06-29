#include "bits/stdc++.h"
using namespace std;

const int N = 1e6+3;

vector<int> g[N];


bool vis[N];

void dfs(int u) {

	vis[u] = 1;

	for(int v : g[u]) {
		if(vis[v]) continue;
		dfs(v);
	}



}


int main() {
	
	freopen("graph_1in.txt", "r", stdin);

	int n, m, u, v;

	cin >> n >> m;

	while(m--) {
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u); // omit this line if graph is directed

	} // graph created

	// checking if there is a path from 1 to 5
	dfs(1);
	if(vis[5]) cout << "yes, a path exists" << endl;
	else cout << "No, a path does not exist" << endl;



	return 0;

}