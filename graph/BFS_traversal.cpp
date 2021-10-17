#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

void bfsOfGraph(int n, vector<int>adj[] , vector<int>& vis , vector<int>& bfs)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			q.push(i);
			vis[i] = 1;
			while (!q.empty())
			{
				int node = q.front();
				q.pop();
				bfs.push_back(node);

				for (auto it : adj[node]) {
					if (!vis[it]) {
						q.push(it);
						vis[it] = 1;
					}
				}
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	//n -> number of nodes  m -> no of edges
	int n, m ;
	cin >> n >> m;
	vector<int> adj[n + 1];
	vector<int> vis(n + 1, 0);
	vector<int> bfs;
	for (int i = 0 ; i < m ; i++)
	{
		int u , v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfsOfGraph(n , adj , vis, bfs);
	for (auto ele : bfs)
		cout << ele << " ";
	cout << endl;
	return 0 ;
}