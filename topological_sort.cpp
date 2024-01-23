#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vertices,edges,i;
	cin>>vertices>>edges;
	vector<int>adj[vertices+1];
	vector<int>res;
	for(i=0; i<vertices; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	vector<int>In_deg(vertices,0);
	for(auto i:adj)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
			In_deg[j]++;
		}
		cout<<endl;
	}
	for(auto i:In_deg)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	queue<int>q;
	for(i=0; i<vertices; i++)
	{
		if(In_deg[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int val=q.front();
		q.pop();
		res.push_back(val);
		for(auto i:adj[val])
		{
			if((--In_deg[i])==0)
			{
				q.push(i);
			}
		}
	}
	for(auto i:res)
	{
		cout<<i<<" ";
	}

}