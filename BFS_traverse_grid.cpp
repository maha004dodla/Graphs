#include<bits/stdc++.h>
using namespace std;
#define n 4
#define m 4
int dRow[]={-1,0,1,0};
int dCol[]={0,1,0,-1};
bool valid(bool visited[][m],int r,int c)
{
	if(r<0 or r>=n or c<0 or c>=m)
	{
		return 0;
	}
	if(visited[r][c])
	{
		return 0;
	}
	return 1;
}
void BFS(int mat[][m],bool visited[][m],int r,int c)
{
	queue<pair<int,int>>q;
	q.push({r,c});
	visited[r][c]=true;
	while(!q.empty())
	{
		int a=q.front().first;
		int b=q.front().second;
		cout<<mat[a][b]<<" ";
		q.pop();
		for (int i=0; i<4; i++) 
		{
            int adjx=a+dRow[i];
            int adjy=b+dCol[i];
            if(valid(visited,adjx,adjy)) 
            {
                q.push({adjx,adjy});
                visited[adjx][adjy] = true;
            }
        }
	}
}
int main()
{
	int i,j;
	int mat[n][m];
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			cin>>mat[i][j];
		}
	}
	bool visited[n][m];
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			visited[i][j]=false;
		}
	}
    BFS(mat,visited,0,0);
}