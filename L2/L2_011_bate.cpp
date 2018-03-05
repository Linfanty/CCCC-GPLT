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

// 已知前序（先序）与中序输出后序

int pre[] = {1, 2, 3, 4, 5, 6};
int mid[] = {3, 2, 4, 1, 6, 5};

void post(int root, int st, int ed) {
	if( st > ed ) return;
	
	int i = st;
	while( i < ed && mid[i] != pre[root] ) i++;
	// root 是相对于前序而言的 st 和 ed 所对中序而言的
	post(root + 1, st, i - 1); // 左 root<<1
	post(root + 1 + i - st, i + 1, ed); // 右 root<<1|1
	cout << pre[root] << ' '; // 根
}

int main() {
	post(0, 0, 5);
	// root 是相对于前序而言的 st 和 ed 所对中序而言的
}

// 已知后序与中序输出前序（先序）
#include <cstdio>
using namespace std;
int post[] = {3, 4, 2, 6, 5, 1};
int in[] = {3, 2, 4, 1, 6, 5};
void pre(int root, int start, int end) {
    if(start > end) return ;

    int i = start;
    while(i < end && in[i] != post[root]) i++;
    printf("%d ", post[root]); // 根左右
    pre(root - 1 - end + i, start, i - 1);
    pre(root - 1, i + 1, end);
}

int main() {
    pre(5, 0, 5);
    return 0;
}