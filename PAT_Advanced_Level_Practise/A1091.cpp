#include <cstdio>
#include <queue>
using namespace std;

int M, N, L, T;
int cnt = 0;
int cube[1287][129][61];
int sum[1287*129*61] = {0};
bool inq[1287][129][61] = {false};
struct Node{
	int x, y, z;
	Node(int a=-1, int b=-1, int c=-1) : x(a), y(b), z(c){}
} temp;
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool check(int x, int y, int z){
	if(x >= M || x < 0 || y >= N || y < 0 || z >= L || z < 0) return false;
	if(inq[x][y][z] == true || cube[x][y][z] == 0) return false;
	return true;
}

void DFS(int x, int y, int z){
	queue<Node> q;
	//temp.x = x; temp.y = y; temp.z = z;
	//q.push(temp);
	q.push(Node(x, y, z));
	inq[x][y][z] = true;
	//++sum[cnt];
	while(!q.empty()){
		Node f = q.front();
		q.pop();
		++sum[cnt];
		for(int i = 0; i < 6; ++i){
			int newX = f.x + X[i];
			int newY = f.y + Y[i];
			int newZ = f.z + Z[i];
			if(check(newX, newY, newZ)){
				//temp.x = newX; temp.y = newY; temp.z = newZ;
				//q.push(temp);
				q.push(Node(newX, newY, newZ));
				inq[newX][newY][newZ] = true;
			}
		}
	}
}

int main(){
	scanf("%d%d%d%d", &M, &N, &L, &T);
	for(int z = 0; z < L; ++z){
		for(int x = 0; x < M; ++x){
			for(int y = 0; y < N; ++y){
				scanf("%d", &cube[x][y][z]);
			}
		}
	}
	for(int z = 0; z < L; ++z){
		for(int x = 0; x < M; ++x){
			for(int y = 0; y < N; ++y){
				if(cube[x][y][z] == 1 && inq[x][y][z] == false){
					DFS(x, y, z);
					++cnt;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < cnt; ++i){
		if(sum[i] >= T)
			ans += sum[i];
	}
	printf("%d", ans);
	return 0;
}