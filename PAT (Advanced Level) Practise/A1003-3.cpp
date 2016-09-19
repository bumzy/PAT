#include <iostream>
#include <vector>
#define N 505
using namespace std;

int n,m,s,e;
int minDis, numDis, numTeams;
int matrix[N][N];
int teams[N];
bool visited[N];
vector<int> path;

void DFS(int cur){
	if(cur == e){
		int curDis = 0, curTeams = 0;
		for (int i = 0; i < path.size() - 1; ++i)
		{
			curDis += matrix[path[i]][path[i + 1]];
		}
		for (int i = 0; i < path.size(); ++i)
		{
			curTeams += teams[path[i]];
		}
		if(curDis < minDis)
		{
			numDis = 1;
			minDis = curDis;
			numTeams = curTeams;
		}else if (curDis == minDis)
		{
			++numDis;
			if (numTeams < curTeams)
			{
				numTeams = curTeams;
			}
		}
	}else{
		for (int i = 0; i < n; ++i)
		{
			if (matrix[cur][i] != -1 && !visited[i])
			{
				visited[i] = true;
				path.push_back(i);
				DFS(i);
				path.pop_back();
				visited[i] = false;
			}
		}
	}
}

int main(){
	while(cin >> n >> m >> s >> e) {
	    for (int i = 0; i < n; ++i)
	    {
	    	for (int j = 0; j < n; ++j)
	    	{
	    		matrix[i][j] = -1;
	    	}
	    	visited[i] = false;
	    	matrix[i][i] = 0;
	    }
	    for (int i = 0; i < n; ++i)
	    {
	    	cin >> teams[i];
	    }
	    for (int i = 0; i < m; ++i)
	    {
	    	int a, b, c;
	    	cin >> a >> b >> c;
	    	matrix[a][b] = matrix[b][a] = c;
	    }

	    path.clear();
	    minDis = 0x7fffffff;
	    numDis = 0;
	    numTeams = 0;

	    visited[s] = true;
	    path.push_back(s);
	    DFS(s);
	    path.pop_back();
	    visited[s] = false;

	    cout << numDis << " " << numTeams << endl;
	}
	return 0;
}