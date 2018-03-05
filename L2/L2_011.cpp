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

/* index，表示当前的根结点在二叉树中所对应的下标（从0开始）
把根结点下标所对应的值存储在level数组中
（一开始把level都置为-1表示此处没有结点），
镜面反转只需改变index的值，左孩子为2 * index + 2，右孩子为2 * index + 1，
这样在递归完成后level数组中非-1的数就是按照下标排列的层序遍历的顺序~~
*/

// 无须构造二叉树再进行广度优先搜索

vector<int> mid, pre, level(100005, -1); // 从0开始 每个结点的编号

void levelorder(int root, int st, int ed, int index) {
	if(st > ed) return;

	int i = st;
	while( i < ed && mid[i] != pre[root]) i++;

	level[index] = pre[root];
	levelorder(root + 1, st, i - 1, 		2 * index + 2); // level[右] = pre[左]
	levelorder(root + 1 + i - st, i + 1, ed,  		2 * index + 1); // level[左] = pre[右]
}

int main() {
	int n, cnt = 0;
	cin >> n;
	mid.resize(n); pre.resize(n); // 重要
	for(int i = 0; i < n; i++) cin >> mid[i];
	for(int i = 0; i < n; i++) cin >> pre[i];
	
	levelorder(0, 0, n-1, 0);
	
	for(int i = 0; i < level.size(); i++) { // level.size() : 慢二叉树的结点数 
		// show3(i, level[i], cnt);
		if( level[i] != -1 && cnt != n - 1) { // -1表示此处没有结点
			cout << level[i] << ' ';
			cnt++;
		}
		else if( level[i] != -1 ) {
			cout << level[i];
			break;
		}
	}

    
    
}
