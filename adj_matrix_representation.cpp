#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vertices,edges,i,j;
	cin>>vertices>>edges;
	int adj[vertices+1][vertices+1];
	//initialization of a matrix
	for(i=0; i<vertices; i++)
	{
		for(j=0; j<vertices; j++)
		{
			adj[i][j]=0;
		}
	}
	//placing its respective edges
	for(i=0; i<edges; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	for(i=0; i<vertices; i++)
	{
		for(j=0; j<vertices; j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*input:
4 4
1 2
2 3
3 3
2 2

output:
0 0 0 0 
0 0 1 0 
0 1 1 1 
0 0 1 1 