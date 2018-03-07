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


// 朋友之间的关系用并查集解决
// 敌人之间的关系用enemy[a][b] = enemy[b][a] = 1解决

int pre[101*101];
int en[105][105];

int fd(int x) {
	return x == pre[x] ? x : pre[x] = fd(pre[x]);
}

void join(int a, int b) {
	int fx = fd(a);
	int fy = fd(b);
	if( fx != fy )
		pre[fx] = fy;
}


int main() {
	int n, m, k, a, b, c;
	cin >> n >> m >> k;

	for(int i = 0; i <= n; i++) pre[i] = i;
	//for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) en[i][j] = 0;

	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if( c == 1 ) 
			join(a, b);
		else
			en[a][b] = en[b][a] = 1;
	}
    
    for(int i = 0; i < k; i++) {
    	cin >> a >> b;
    	if( fd(a) == fd(b) && en[a][b] == 0)
    		cout << "No problem\n";
    	else if( fd(a) != fd(b) && en[a][b] == 0)
    		cout << "OK\n";
    	else if( fd(a) == fd(b) && en[a][b] == 1)
    		cout << "OK but...\n";
    	else if( en[a][b] == 1)
    		cout << "No way\n";
    }
 
}
