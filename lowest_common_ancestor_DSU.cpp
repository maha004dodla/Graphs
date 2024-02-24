#include<bits/stdc++.h>
using namespace std;
int find_parent(int val,vector<int>parent)
{
    return parent[val];
}
void Union(int a,int b,vector<int>&parent)
{
    if(a!=b)
    {
        parent[b]=a;
    }
}
int find_lca(int n1, int n2,vector<int>parent,int n) 
{
    if(n1>n or n2>n)
    {
        return -1;
    }
    n1=find_parent(n1,parent);
    n2=find_parent(n2,parent);
    if(n1==n2)
    {
        return n1;
    }
    if(n1==find_parent(n2,parent))
    {
        return n1;
    }
    if(n2==find_parent(n1,parent))
    {
        return n2;
    }
    while(n1!=n2)
    {
        n1=find_parent(n1,parent);
        n2=find_parent(n2,parent);
        if(n1==n2)
        {
            return n1;
        }
    }
    return -1;
}
int main()
{
    int n,m,i;
    cin>>n>>m;
    int n1,n2;
    vector<int>parent(n+1);
    for(i=1; i<=n; i++)
    {
        parent[i]=i;
    }
    for(i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v,parent);
    }
    cin>>n1>>n2;
    int res=find_lca(n1,n2,parent,n);
    cout<<res<<endl;
}



