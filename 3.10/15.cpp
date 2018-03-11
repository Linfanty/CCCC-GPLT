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

std::vector<int> g[maxn];
bool vit[maxn];

int main() {
    /* code */
    int n, m, k;
    cin >> n >> m >> k;
    int u, v;
    for(int i = 1; i <= m; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
   		g[v].push_back(u); 		
    }
    
    while( k-- ) {
    	int st, level[maxn], maxlever = 0; // 最远能到的数
    	cin >> st;

    	memset(level, 0, sizeof(level));
		memset(vit, 0, sizeof(vit));

		queue<int> q;
		q.push(st);
		vit[st] = 1;
		int ans = st; // 1

		while( !q.empty() ) {
			int now = q.front();
			q.pop();

			if( level[now] > maxlever ) {
				maxlever = level[now]; // 更新最大值
				ans = now; // 更新山的编号
			}
			else if( level[now] == maxlever )
				ans = min(ans, now); // 输出编号最小的山

			for(int i = 0; i < g[now].size(); i++) { // G[NOW].SIZE()
				int nxt = g[now][i]; // ..

				if( !vit[nxt] ) {
					q.push(nxt);
					vit[nxt] = 1;
					level[nxt] = level[now] + 1; // nxt = now + 1
				}
			}
		}

		if( ans == st ) cout << "0\n"; // 2
		else cout << ans << endl;
    }
}
