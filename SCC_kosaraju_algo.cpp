#include<bits/stdc++.h>
using namespace std;
vector<int>l;
void DFS(int node,vector<int> adj[],vector<bool>&visited,vector<int>&l)
{
    visited[node]=1;	
    for(auto i:adj[node])
   	{
   		if(!visited[i])
   		{
   			DFS(i,adj,visited,l);
   		}
    }
   	l.push_back(node);
}
int main()
{
	int vertices,edges;
	cin>>vertices>>edges;
	vector<int>adj[vertices+1];
	vector<bool>visited(vertices,false);
	int i;
	for(i=0; i<edges; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
    vector<int>l;
    for(i=0; i<vertices; i++)
    {
    	if(!visited[i])
    	{
    		DFS(i,adj,visited,l);
    	}
    }
    reverse(l.begin(),l.end());
    fill(visited.begin(), visited.end(), false);
    vector<int>rev[vertices];
    for(i=0; i<vertices; i++)
    {
    	for(auto j:adj[i])
    	{
    	    rev[j].push_back(i);
    	}
    }
    int c=0;
   	for(i=0; i<vertices; i++)
  	{
   	    if(!visited[l[i]])
    	{
            c++;
   	        DFS(l[i],rev,visited,l);
   	    }
   	}
    cout<<c<<endl;	
}





