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

/// int v[1005]; // 结点 可能为负数 所以不能用
vector<int> v; // v.resize(n+1); // !!!!!!!! 
int n;
/*
5 4
46 23 26 24 10
24 is 		the 			root
26 and 23 are siblings
46 is 		the			    parent of 23
23 is 		a child of 10
*/

void up(int i) { // 更新最小堆 向上调整 难点 建树
	if( i == 1 ) return;
	while( i != 1) { // 一直更新到root
		if( v[i] < v[i/2]) { // child < parent
			swap(v[i], v[i/2]); // 向上调整
			i = i / 2;
		}
		else break;
	}
}

void judge1(int x) {
	if( x == v[1] ) cout << "T\n";
	else cout << "F\n";
}

void judge2(int x, int y) { // xiong di
	int a = 0, b = 0;
	for(int i = 1; i <= n; i++) {
		if( v[i] == x ) a = i;
		if( v[i] == y ) b = i;
	}

	if( a > b ) swap(a, b);
	if( a % 2 == 0 && b - a == 1) cout << "T\n"; // 偶数 则为 树中左边的结点
	else cout << "F\n"; 
}

void judge3(int x, int y) { // x是y的父亲结点
	int a, b;
	for(int i = 1; i <= n; i++) {
		if(v[i] == x) a = i;
        if(v[i] == y) b = i;
	}

	if( (2*a) == b || (2*a)+1 == b) cout << "T\n";
	else cout << "F\n"; 
}

void judge4(int x, int y) { // x是y的子结点
	int a, b;
	for(int i = 1; i <= n; i++) {
		if(v[i] == x) a = i;
        if(v[i] == y) b = i;
	}

	if( (2*b) == a || (2*b)+1 == a) cout << "T\n";
	else cout << "F\n"; 
}


int main() {
	int k, a, b;
	char c[105];

	cin >> n >> k; 
	v.resize(n+1); // !!!!!!!! 
	// 一定要规定大小...因为建树中要访问其他空间 或者得用map
	
	for(int i = 1; i <= n; i++) {
		cin >> v[i];
		up(i);
	}

	for(int i = 1; i <= k; i++) {
		cin >> a >> c;
		if( strcmp(c, "and") == 0) {
			cin >> b >> c >> c;
			judge2(a, b); // xiong di
		}
		else {
			cin >> c;
			if( strcmp(c, "a") == 0) {
				cin >> c >> c >> b;
				judge4(a, b);
			}
			else {
				cin >> c;
				if(strcmp(c, "root") == 0)
					judge1(a);
				else {
					cin >> c >> b;
					judge3(a, b);
				}
			}		 
		}
	}
}
