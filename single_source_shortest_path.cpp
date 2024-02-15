#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100001];
int visited[100001];
void bfs(int node,vector<int>&result_paths)
{
	queue<int>q;
	q.push(node);
	visited[node]=1;
	result_paths[node]=0;
	while(!q.empty())
	{
		node=q.front();
		q.pop();
		for(auto i:adj[node])
		{
			if(!visited[i])
			{
				result_paths[i]=min(result_paths[node]+1,INT_MAX);
				q.push(i);
				visited[i]=1;
			}
		}
	}
}
int main()
{
	int vertices,edges;
	cin>>vertices>>edges;
	int i;
	for(i=0; i<edges; i++)
	{
		int v,u;
		cin>>v>>u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	// for(i=1; i<edges; i++)
	// {
	// 	cout<<i<<"-----";
	// 	for(auto j:adj[i])
	// 	{
	// 		cout<<j<<" ";
	// 	}
	// 	cout<<endl;
	// }
	vector<int>result_paths(vertices+1,INT_MAX);
    bfs(1, result_paths);
    for(i=1; i <= vertices; i++) 
    {
        cout<<"shortest path to "<<i<<": "<<result_paths[i]<<endl;
    }
    return 0;
}









