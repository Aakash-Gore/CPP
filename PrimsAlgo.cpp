#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int>> mst(vector<pair<int, int>>  adj[],int n)
{
	priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> pq;
	pq.push({ 0,{0,-1} });

	vector<int> vis(n, 0);
	//vis[0] = 1;
	vector<pair<int, int>> ans;

	while (!pq.empty())
	{
		auto it = pq.top();
		int node = it.second.first;
		int parent = it.second.second;
		pq.pop();
		if (vis[node])
			continue;
		vis[node] = 1;
		
		int wt = it.first;
		if (parent!= -1)
		{
			ans.push_back({ parent, node });
		}
		

		
		for (auto u : adj[node])
		{
			if (!vis[u.first])
			{
				pq.push({ u.second, {u.first,node} });

			}
		}
	}

	return ans;
}

int main()
{
	vector<pair<int, int>>  adj[5];
	adj[0] = { {1,2}, {2,1} };
	adj[1] = { {0,2}, {2,1} };
	adj[2] = { {0,1}, {1,1}, {4,2}, {3,2} };
	adj[3] = { {2,2}, {4,1} };
	adj[4] = { {2,2}, {3,1} };

	
	vector<pair<int, int>> ans;
	ans = mst(adj, 5);
	for (auto u : ans)
	{
		cout << u.first << " " << u.second << endl;
	}

}