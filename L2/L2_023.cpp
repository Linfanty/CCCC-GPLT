#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl
const int maxn = 505;
#define LOCAL

/* 图的遍历 */
int g[maxn][maxn] = {0};
int cr[maxn] = {0};

bool vit[maxn];
bool fg;

int v, e, k, m;

void dfs(int x) {
	vit[x] = true; // 访问过
	if( !fg ) return;

	for(int i = 0; i < x; i++) {
		if( cr[x] == cr[i] && g[x][i] == 1 ) // 颜色相等 且 存在边
		// 邻接矩阵 用 i < x  g[x][i]
		{
			fg = false;
			return;
		} 
		else if( g[x][i] == 1 && vit[i] == false) // 有边 且没访问关于 就去访问
			dfs(i);
	}
}

int main() {
	cin >> v >> e >> k;
	for(int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--; // 后面 0 1 2 3 4 5 	
		g[x][y] = g[y][x] = 1;
	}
    
	cin >> m;

	for(int i = 0; i < m; i++) {

		set<int> s;
		for(int j = 0; j < v; j++) {
			int c;
			cin >> c;
			s.insert(c);
			cr[j] = c; // x--, y--;
		}

		if( s.size() != k ) // 注意需要不同颜色的个数需要等于k
			fg = false; // 每一个顶点分配一种颜色
		else {
			memset(vit, 0, sizeof vit);
			fg = true;

			for(int j = 0; j < v; j++) {
				//if( !vit[j] )
					dfs(j); // !!!!!
				if( fg == false )
					break;
			}
		}


		if( fg )
			cout << "Yes\n";
		else cout << "No\n";
	}
}
