#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif


	int V, e;
	cin >> V >> e;

	vector<int> adj[V + 1];

	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int src = 0;
	vector<int> dist(V + 1, INT_MAX);

	queue<int> q;
	q.push(src);
	dist[src] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto it : adj[node]) {
			if (dist[node] + 1 < dist[it]) {
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}

	for (int i = 0; i < V; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;




	return 0 ;
}