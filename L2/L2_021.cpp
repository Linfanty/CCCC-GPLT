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

// 用set维护出每个人点赞的个数
int n, k, tmp;

struct Node{
	string name;
	int x, sum;
}node[maxn];

bool cmp(Node xx, Node yy) {
	if( xx.sum != yy.sum )
		return xx.sum > yy.sum;
	return xx.x <  yy.x; // 并列时 输出标签出现次数平均值最小
}

int main() {
	cin >> n;
	set<int> s;
	for(int i = 0; i < n; i++) {
		cin >> node[i].name;
		cin >> k;

		s.clear();
		for(int j = 0; j < k; j++) {
			cin >> tmp;
			s.insert(tmp); // qu chong 
		}
		node[i].sum = s.size(); // how many people
		node[i].x = k; // 总个数越xiao平均值越小
	}

	sort(node, node + n, cmp);

	for(int i = 0; i < min(n, 3); i++) {
		if( i == 0) cout << node[i].name;
		else cout << " " << node[i].name;
	}
    
    for(int i = n; i < 3; i++) {
    	if( i == 0 ) cout << "-";
    	else cout << " -";
    }
}
