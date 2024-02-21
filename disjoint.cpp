#include<bits/stdc++.h>
using namespace std;
int find_parent(int val,vector<int>&parent)
{
	if(parent[val]==val)
	{
		return val;
	}
	return find_parent(parent[val],parent);
}
void Union(int v1,int v2,vector<int>&parent,vector<int>&rank)
{
	int p1=find_parent(v1,parent);
	int p2=find_parent(v2,parent);
	if(rank[p1]==rank[p2])
	{
		parent[p2]=p1;
		rank[p2]++;
	}
	else if(rank[p1]<rank[p2])
	{
		parent[p2]=p1;
	}
	else
	{
		parent[p1]=p2;
	}
}
int main()
{
	int n,i;
	cin>>n;
	vector<int>parent(n+1);
	vector<int>rank(n+1,0);
	for(i=1; i<=n; i++)
	{
		parent[i]=i;
	}
	Union(1,2,parent,rank);
	Union(3,4,parent,rank);
	Union(1,4,parent,rank);
	Union(3,5,parent,rank);
	Union(6,7,parent,rank);
	// for(auto i:parent)
	// {
	// 	cout<<i<<" ";
	// }
	// cout<<endl;
	// for(auto i:rank)
	// {
	// 	cout<<i<<" ";
	// }
	// cout<<endl;
	if(find_parent(1,parent)==find_parent(3,parent))
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}

}