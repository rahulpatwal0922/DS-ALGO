#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

void dfs(vector<int> adj[] , int node, vector<bool>& vis)
{
	vis[node] = true;
	cout << node << " ";
	for (auto it : adj[node]) {
		if (vis[it] == false) {
			dfs(adj, it , vis);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	// 1 based indexing
	vector<int> adj[n + 1];
	vector<bool> vis(n + 1 , false);
	for (int i = 0; i < m ; i++) {
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n ; i++) {
		if (vis[i] != true)
			dfs(adj, i, vis);
	}
	return 0 ;
}