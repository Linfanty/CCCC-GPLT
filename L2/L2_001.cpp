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

// 建议数组开大一些
int n, m, s, d;
int head[505*505], dis[505];
bool vis[505];// 点的总数

int nume = 0;
int ans = 0;

struct node {
	int to, cost, next;
}e[505*505];// maxn的百倍以上 MAXM表示边的总数

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

int num[505]; // 从出发点到i结点拥有的路的条数
int dui[505]; // 能找到的救援队的数目 边值的sum
int pre[505]; // 表示最短路径的前一个结点
int a[505]; // 每个结点的权值

bool spfa(int st, int ed) {
	int to, cost, now;
	
	/***/
	queue<int> q;
	q.push(st);
	dis[st] = 0;
	vis[st] = true;
	/***/
	num[st] = 1;
	dui[st] = a[st];

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

				// num[to] = num[now]; // == 
				dui[to] = dui[now] + a[to];
				pre[to] = now;

				if( !vis[to] ) {
					numq[to]++;
					if( numq[to] > n) return true;
					
					vis[to] = true;
					q.push(to);
				}
			}
			else if( dis[to] == dis[now] + cost) {
				// num[to] = num[to] + num[now]; // += 
			

				if( dui[to] < dui[now] + a[to])
				{
					dui[to] = dui[now] + a[to];
					pre[to] = now;
				
					if( !vis[to] ) {
						numq[to]++;
						if( numq[to] > n) return true;
						
						vis[to] = true;
						q.push(to);
					}
				}
					
			}
		}
	}
	ans = dis[ed];
}


int numd = 0;
void dfs(int now) {// 计算最短路的条数
	if( now == d )
	{numd++; return;}
	for(int i = head[now]; ~i; i = e[i].next ){
		int to = e[i].to;
		int cost = e[i].cost;

		if( !vis[to] && dis[to] == dis[now] + cost)// 满足是最短路
		{
			vis[to] = 1;
			dfs(to);
			vis[to] = 0;
		}
	}
}

void print(int x) {
	if( x == s )
	{cout << x; return; }
	print(pre[x]);
	cout << ' ' << x;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
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

    spfa(s, d);
    // cout << ans << endl;

    memset(vis, 0, sizeof(vis)); dfs(s);
    cout << numd << ' ' << dui[d] << endl;
    // cout << num[d] << ' ' << dui[d] << endl;

    print(d);
}
