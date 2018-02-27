#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl
const int maxn = 3005; // 树中要开很大才行阿
#define LOCAL

int tree[maxn];
int n, x;
vector<int> postt, midd;

void build(int root, vector<int> post, vector<int> mid) {// 根 后 中
	if( post.size() == 0 ) return;//递归出口
	
	int p = 0;
	for(int i = 0; i < mid.size(); i++)
		if( mid[i] == post[post.size() - 1] ) 
			p = i; // 找根

	// 分成四部分
	vector<int>left_post, right_post, left_mid, right_mid;
	for(int i = 0; i < p; i++) left_post.push_back(post[i]); //左子树的后序遍历序列  
	for(int i = p; i < post.size()-1; i++) right_post.push_back(post[i]); //右子树的后序遍历序列  

	for(int i = 0; i < p; i++) left_mid.push_back(mid[i]); //左子树的中序遍历序列  
	for(int i = p+1; i < mid.size(); i++) right_mid.push_back(mid[i]); //右子树的中序遍历序列  

	tree[root] = mid[p]; //建根  建立前序遍历 根左右
	// 根 后 中
	build(root<<1, left_post, left_mid); //递归建左子树  
	build(root<<1|1, right_post, right_mid); //递归建右子树
}

// build是递归 下面q.push只是推一个结点

//用bfs将前序遍历转变为层次遍历 
void bfs() {
	queue<int> q;
	int root = 1;
	q.push(root);

	int f = 0;
	while( !q.empty() ) {
		if( f++ ) cout << " ";
		root = q.front();
		q.pop();
		cout << tree[root]; // 输出根阿

		if( tree[root<<1] != -1 ) q.push(root << 1); // 找一个左边阿
		if( tree[root<<1|1] != -1 ) q.push(root<<1|1); // 找一个右边阿
	}
}

int main() {
	cin >> n;
	memset(tree, -1, sizeof tree);// 标记未找过的
	// 输入后序遍历和中序遍历
	for(int i = 0; i < n; i++) cin >> x, postt.push_back(x);
	for(int i = 0; i < n; i++) cin >> x, midd.push_back(x);

	build(1, postt, midd);
	bfs(); // 输出层次遍历
}
