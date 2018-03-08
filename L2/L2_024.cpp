#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl
const int maxn = 10005;
#define LOCAL

int pre[maxn];

int fd(int x) {
	return x == pre[x] ? x : pre[x] = fd(pre[x]);
}

void join(int x, int y) {
	int fx = fd(x);
	int fy = fd(y);
	if( fx != fy )
		pre[fx] = fy;
}

bool vit[maxn];

int main() {
	memset(vit, 0, sizeof(vit));
	int n, a, b, m;
	cin >> n;
	for(int i = 0; i <= maxn; i++)
		pre[i] = i;

	int k, tmp;
    for(int i = 0; i < n; i++) {
    	cin >> k;
    	cin >> tmp;
    	vit[tmp] = 1;
    	for(int j = 1; j < k; j++) {
    		cin >> b;
    		vit[b] = 1;
    		join(tmp, b);
    	}

    }

    int cnt = 0, ans = 0;
    for(int i = 0; i < maxn; i++) {
    	if( vit[i] == 1 ) {
    		cnt++;
    		if( pre[i] == i) // !!!!!!!!!!! 并查集联通块数
    			ans++;
    	}
    }
    cout << cnt << ' ' << ans << endl;

    cin >> k;
    for(int i = 0; i < k; i++) {
    	cin >> a >> b;
    	if( fd(a) == fd(b) )
    		cout << "Y\n";
    	else cout << "N\n";
    }


}
