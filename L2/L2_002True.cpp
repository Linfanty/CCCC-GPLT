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
	return a.num < b.num; // 用num区分两条链表
} 

int main() {
	int begin, n, cnt1 = 1, cnt2 = 1, a;// 两种结果分别的个数
	cin >> begin >> n;

	for(int i = 0; i < maxn; i++) node[i].num = 2 * maxn;// 费空间 分成两部分存储
	// 初始化排序数组 inf

	for(int i = 0; i < n; i++) {
		cin >> a;
		cin >> node[a].key >> node[a].next;
		node[a].address = a; // node[12345].address = 12345 方便输出
	}

	for(int i = begin; i != -1; i = node[i].next) { // i！=-1 i=node[i].snext
		int k = abs(node[i].key);
		
		if( exist[k] == false ) {
			exist[k] = true;
			node[i].num = cnt1++;
		}
		else node[i].num = maxn + cnt2++;// 费空间 分成两部分
	}
	// 用num区分两条链表
	sort(node, node + maxn, cmp1);// 合并

	int cnt = cnt1 + cnt2;
	for(int i = 0; i < cnt; i++) {
		if( i != cnt1 && i != cnt)
			printf("%05d %d %05d\n", 
				node[i].address, node[i].key, node[i+1].address); // i+1
		else printf("%05d %d -1\n", node[i].address, node[i].key);
		// cnt1一处-1  cnt处一个-1
	} 

}