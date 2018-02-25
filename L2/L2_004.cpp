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
/*
分析：假设它是二叉搜索树，一开始isMirror为FALSE，根据二叉搜索树的性质将已知的前序转换为后序，
转换过程中，如果发现最后输出的后序数组长度不为n，那就设isMirror为true，然后清空后序数组，
重新再转换一次（根据镜面二叉搜索树的性质），如果依旧转换后数组大小不等于n，就输出no否则输出yes

为何“最后输出的后序数组长度不为n”为转换失败条件？

因为假设原数列是先序遍历，按其性质，我们定能依次找到分支节点，理清每个子树，若不是，转换节点不全。

如何实现前序转换为后序？

利用平衡二叉树性质：节点A的左子树全部小于A，右子树全部大于A
充分利用递归，只求原理，不过分追究细节，简单易懂的特点。

*/
bool isMirror;
std::vector<int> pre;
std::vector<int> post;
// 将已知的前序转换为后序
//1）8 6 5 7 10 8 11
//2）8 10 11 8 6 7 5

void getpost(int root, int tail) { // 头结点 尾结点
	if( root > tail ) return;
	
	int i = root + 1, j = tail;
	if( !isMirror ) {
		while( i <= tail && pre[root] >= pre[i]) i++; // 6 5 7 10<-
		while( j > root && pre[root] <= pre[j]) j--; // 11 8 10 7<-
	} else {
		while( i <= tail && pre[root] <= pre[i]) i++;
		while( j > root && pre[root] > pre[j]) j--;
	} 

	if( i - j != 1) return; // i j 互相挨着说明分开了左 右子树
	getpost(root + 1, j);   /// 左 ←j 指向了左边
	getpost(i, tail);       /// 右 i→ 指向了右边
	post.push_back( pre[root] ); // 依照递归顺序来看push的先后顺序为 左←右→根↑
}

int main() {
	int n; cin >> n;
	pre.resize(n);
	for(int i = 0; i < n; i++) cin >> pre[i]; // 输入前序遍历
    
    getpost(0, n - 1);
	if( post.size() != n) { // 重新再转换一次

		isMirror = true; // 查找镜像的
		post.clear(); // 清空后序数组
		getpost(0, n - 1); // 重新再转换一次
	}

	if( post.size() == n) { // 输出后序遍历
		cout << "YES\n" << post[0];
		for(int i = 1; i < n; i++) cout << ' ' << post[i];
	} 

	else cout << "NO";
}
