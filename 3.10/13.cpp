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

// 只需要保存当前所有队伍的车尾!!!!
// 用set自动排序

int main() {
    /* code */
    int n, x; cin >> n;
    set<int> s;
    s.insert(0);
    for(int i = 0; i < n; i++) {
    	cin >> x;
    	if( x < *s.rbegin() ) // 当前所有队列队尾的最大值
    		s.erase( *(s.upper_bound(x))); // 删除第一个大于x的值
    	s.insert(x);
    }
    cout << s.size() - 1;
}
/*
0
0 8
0 4 
0 2 
0 2 5
0 2 3
0 2 3 9
0 1 3 9
0 1 3 6
0 1 3 6 7
所以队尾有 1 3 6 7
*/
