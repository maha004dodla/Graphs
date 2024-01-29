#include<bits/stdc++.h>
using namespace std;
#define n 3
#define m 3
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
void DFS(int row, int col,int mat[][m],bool visited[][m])
{
	stack<pair<int,int>>st;
	st.push({row,col});
	while(!st.empty()) 
	{
		int row = st.top().first;
		int col = st.top().second;
		st.pop();
		if(!valid(visited,row,col))
		{
			continue;
		}
		visited[row][col] = true;
		cout << mat[row][col] << " ";
		for (int i = 0; i < 4; i++) 
		{
			int adjx = row + dRow[i];
			int adjy = col + dCol[i];
			st.push({adjx,adjy});
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
    DFS(0,0,mat,visited);
}
