#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> mindist(int src, int dst, vector<pair<int, int>> adj[], int n)
{

	vector<int> dist(n, 10000);
	dist[src] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({ 0,src });
	while (!pq.empty())
	{
		auto it = pq.top();
		pq.pop();

		int dis = it.first;
		int node = it.second;
		for (auto u : adj[node])
		{
			if (dist[u.second] > u.first + dis)
			{
				dist[u.second] = u.first + dis;
				pq.push({ dist[u.second], u.second });
			}
		}

	}

	return dist;

}

int main()
{

}