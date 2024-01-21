#include<bits/stdc++.h>
using namespace std;
int main()
{
	int vertices;
	cin>>vertices;
	vector<int>adj[vertices+1];
	for(int i=0;i<vertices;i++)
	{
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	for(auto i:adj)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}

}

/*input:
5
0 1
1 2
2 3
0 3
2 2


output:
0--1 3 
1--0 2 
2--1 3 2 2 
3--2 0 */
