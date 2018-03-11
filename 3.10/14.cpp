#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl
const int maxn = 100005;
#define LOCAL

int e[505][505], n, m, k, a, b, city;
bool vit[505];

void dfs(int x){
	vit[x] = true;
	for(int i = 0; i < n; i++)
		if( vit[i] == false && e[x][i] == 1 ) // 有边 可访问
			dfs(i);
}

int check() {
	int ans = 0;
	memset(vit, 0, sizeof vit);
	for(int i = 0; i < n; i++) {// 计算联通块
		if( vit[i] == false ) {
			dfs(i); 
			ans++;
		}
	}
	return ans;
}

// 深度优先遍历 图内的连通分量
// if now >= yuan + 2 则RED
// if i == n - 1 Game Over

int main() {
    /* code */
    cin >> n >> m;
    while( m-- ) {
    	cin >> a >> b;
    	e[a][b] = e[b][a] = 1; // 邻接矩阵存图
    }
    
    int	yuan = check();
    cin >> k;
    for(int i = 0; i < k; i++ ) {
    	cin >> city;
    	for(int j = 0; j < n; j++) {
    		if( e[city][j] == 1 || e[j][city] == 1)
    			e[city][j] = 0, e[j][city] = 0; // 先 取消联通 ！！
    	}
	    int now = check();
	    if( now >= yuan + 2)
	    	printf("Red Alert: City %d is lost!\n", city);
	    else printf("City %d is lost.\n", city);
	    yuan = now;
	    if( i == n - 1 ) printf("Game Over.\n");
    }
}
