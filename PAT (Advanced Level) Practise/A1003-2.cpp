#include <cstdio>
#define INF 0x3f3f3f3f
#define MAX 501
using namespace std;


int *dijkstra(const int (&w)[MAX][MAX], const int (&teams)[MAX], int n, int start, int end){
	int dist[MAX];
	bool visited[MAX];

	int pathcount[MAX];
	int amount[MAX];
	static int result[2];

	for(int i = 0; i < n; ++i){
		visited[i] = false;
		pathcount[i] = 0;
		amount[i] = 0;
		dist[i] = INF;
	}

	//visited[start] = true;
	amount[start] = teams[start];
	pathcount[start] = 1;
	dist[start] = 0;

	for(int i = 0; i < n; ++i){
		int min = INF;
		int k;
		for(int j = 0; j < n; ++j){
			if(visited[j] == false && dist[j] < min){
				min = dist[j];
				k = j;
			}
		}
		visited[k] = true;
		for(int j = 0; j < n; ++j){
			if(visited[j] == false && dist[j] > dist[k] + w[k][j]){
				dist[j] = dist[k] + w[k][j];
				amount[j] = amount[k] + teams[j];
				pathcount[j] = pathcount[k];
			}else if(visited[j] == false && dist[j] == dist[k] + w[k][j]){
				pathcount[j] += pathcount[k];
				if(amount[j] < amount[k] + teams[j]){
					amount[j] = amount[k] + teams[j];
				}
			}
		}
	}
	result[0] = pathcount[end];
	result[1] = amount[end];
	return result;
}
int main(){
	int w[MAX][MAX];
	int teams[MAX];
	int N, M, C1, C2;
	scanf("%d%d%d%d", &N, &M, &C1, &C2);
	for(int i = 0; i < N; ++i){
		scanf("%d", &teams[i]);
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			w[i][j] = INF;
		}
	}
	for(int i = 0; i < M; ++i){
		int m, n, l;
		scanf("%d%d%d", &m, &n, &l);
		w[m][n] = w[n][m] = l;
	}
	int *r = dijkstra(w, teams, N, C1, C2);
	printf("%d %d", *r, *(r + 1));
	return 0;
}