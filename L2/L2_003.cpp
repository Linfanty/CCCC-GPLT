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

struct Node {
	double x, y;
}node[maxn];

bool cmp(Node xx, Node yy) {
	return xx.x/xx.y < yy.x/yy.y; 
}

int main() {
	/* code */
    int n; cin >> n;
    int max1; cin >> max1;

    for(int i = 1; i <= n; i++){
    	cin >> node[i].x;
    }
    for(int i = 1; i <= n; i++){
    	cin >> node[i].y;
    }
    sort(node + 1, node + n + 1, cmp);
 
 	double sum = 0;

    for(int i = 1; i <= n; i++) {
    	if( node[i].x <= max1)
    	{
    		sum += node[i].y;
    		max1 -= node[i].x;
 	   	}
 	   	else {
 	   		sum += node[i].y*max1/node[i].x;
 	   		break;
 	   	}
    }
    printf("%.2f", sum);
}
