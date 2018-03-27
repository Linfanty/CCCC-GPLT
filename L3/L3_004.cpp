#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, z;
};
int m, n, l, t;
int xx[] = {1, 0, 0, -1, 0, 0};
int yy[] = {0, 1, 0, 0, -1, 0};
int zz[] = {0, 0, 1, 0, 0, -1};

int arr[1305][130][80];
bool vit[1305][130][80];

bool check(int x, int y, int z) {
	if( x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)
		return false;
	if( arr[x][y][z] == 0 || vit[x][y][z] ) return false;
	return true;
}

int bfs(int x, int y, int z) {
	int cnt = 0;
	node tmp;
	queue<node> q;
	q.push((node){x, y, z});
	vit[x][y][z] = 1;

	while( !q.empty() ) {
		node now = q.front();
		q.pop();

		cnt++;
		for(int i = 0; i <= 5; i++) {
			int dx = now.x + xx[i];
			int dy = now.y + yy[i];
			int dz = now.z + zz[i];

			if( check(dx, dy, dz)){
				vit[dx][dy][dz] = 1;
				q.push((node){dx, dy, dz});
			}
		}
	}
	if(cnt >= t) return cnt;
	else return 0;
}

int main() {
	cin >> m >> n >> l >> t;
	for(int i = 0; i < l; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < n; k++)
				cin >> arr[j][k][i];

	int ans = 0;
	for(int i = 0; i < l; i++)
		for(int j = 0; j < m; j++)
			for(int k = 0; k < n; k++)
				if( arr[j][k][i] == 1 && !vit[j][k][i] )
					ans += bfs(j, k, i);
	cout << ans;
}