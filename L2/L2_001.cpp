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

int n, m, s, d;
int head[505], dis[505];
bool vis[505];

int nume = 0;
int ans = 0;

struct node {
	int to, cost, next;
}e[505];

void init() {
	memset(vis, false, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	memset(head, -1, sizeof head);
	memset(e, 0, sizeof e);
}

void add(int u, int v, int w) {
	e[nume] = (node){v, w, head[u]};
	head[u] = nume;
	nume++;
}

int numq[505];
bool spfa(int st, int ed) {
	int to, cost, now;
	
	/***/
	queue<int> q;
	q.push(st);
	dis[st] = 0;
	vis[st] = true;
	/***/

	while( !q.empty() ) {
		/***/
		now = q.front();
		q.pop();
		vis[now] = false;
		/***/
		
		for(int i = head[now]; ~i; i = e[i].next ) {
			to = e[i].to;
			cost = e[i].cost;

			if( dis[to] > dis[now] + cost ) {
				dis[to] = dis[now] + cost;

				if( !vis[to] ) {
					numq[to]++;
					if( numq[to] > n) return true;
					
					vis[to] = true;
					q.push(to);
				}
			}
		}
	}
	ans = dis[ed];
} 

int a[505];
int main() {
	init();
	cin >> n >> m >> s >> d;

	for(int i = 0; i < n; i++)
		cin >> a[i];
    
    int u, v, w;
    for(int i = 1; i <= m; i++) {
    	cin >> u >> v >> w;
    	add(u, v, w);
    	add(v, u, w);
    }

    spfa(0, n - 1);
    cout << ans << endl;
}