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
	int address;
	int key;
	int next;
	int num; // 将num变量先初始化为2 * maxn
}node[maxn]; 

bool exist[maxn];

int cmp1(Node a, Node b) {
	return a.num < b.num;
} 

int main() {
	int begin, n, cnt1 = 1, cnt2 = 1, a;
	cin >> begin >> n;

	for(int i = 0; i < maxn; i++) node[i].num = 2 * maxn;// inf

	for(int i = 0; i < n; i++) {
		cin >> a;
		cin >> node[a].key >> node[a].next;
		node[a].address = a;
	}

	for(int i = begin; i != -1; i = node[i].next) {
		int k = abs(node[i].key);
		
		if( exist[k] == false ) {
			exist[k] = true;
			node[i].num = cnt1++;
		}
		else node[i].num = maxn + cnt2++;
	}
	// 用num区分两条链表
	sort(node, node + maxn, cmp1);

	int cnt = cnt1 + cnt2;
	for(int i = 0; i < cnt; i++) {
		if( i != cnt1 && i != cnt)
			printf("%05d %d %05d\n", 
				node[i].address, node[i].key, node[i+1].address);
		else printf("%05d %d -1\n", node[i].address, node[i].key);
		// cnt1一处-1  cnt处一个-1
	} 

}