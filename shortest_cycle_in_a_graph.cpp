#include<bits/stdc++.h>
using namespace std;
int BFS(int node, vector<int>adj[], int n)
{
    queue<pair<int,int>>q;
    vector<bool>visited(n+1,false);
    vector<int>distance(n+1,INT_MAX);
    visited[node] = true;
    distance[node] = 0;
    q.push({node,-1});
    int res = INT_MAX;
    while(!q.empty())
    {
        node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto i : adj[node])
        {
            if(!visited[i])
            {
                q.push({i,node});
                visited[i] = true;
                distance[i] = 1 + distance[node];
            }
            else
            {
                if(i!=parent)
                {
                    res = min(res,distance[i]+distance[node]+1);
                }
            }
        }
    }
    return res;
}
int main(){
    int n , m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //cout<<"hii"<<endl;
    int ans = INT_MAX;
    for(int i = 0 ; i < n ; i++)
    {
        ans = min(ans,BFS(i,adj,n));
    }
    if(ans == INT_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }


}
