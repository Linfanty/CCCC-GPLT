#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define show(a) cout<<#a<<" = "<<a<<endl
#define show2(b,c) cout<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show3(a,b,c) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<endl
#define show4(a,b,c,d) cout<<#a<<" = "<<a<<" "<<#b<<" = "<<b<<" "<<#c<<" = "<<c<<" "<<#d<<" = "<<d<<endl
const int maxn = 10005;
#define LOCAL

struct Data { // 接收数据 
	int id, f, m, num, area;
	int c[7]; // 子女个数 
}data[maxn];

struct Node {
	int id, people; // people++统计人数
	double num, area; // num房子数
	bool flag = false; // true的个数cnt++就可以知道一共有多少个家庭
}ans[maxn]; // 输出最后的答案

int pre[maxn];
bool vit[maxn]; // visit标记所有出现过的结点

int fd(int x) {
	return x == pre[x] ? x : pre[x] = fd(pre[x]); 
}

void join(int x, int y) {
	int fx = fd(x);
	int fy = fd(y);
	if( fx > fy ) pre[fx] = fy; // 编号小的为祖先
	else if( fx < fy ) pre[fy] = fx;
}

bool cmp(Node x, Node y) {
	if( x.area != y.area )
		return x.area > y.area; // 面积大在前
	return x.id < y.id; // 编号小在前
}
// 排序后输出前cnt个

int main() {
	/* code */
    int n, k, cnt = 0;
    cin >> n;
    for(int i = 0; i < maxn; i++) pre[i] = i;
    for(int i = 0; i < n; i++) {
    	cin >> data[i].id >> data[i].f >> data[i].m >> k;

// 将每个人都标记为已访问 并与其编号合并
    	vit[ data[i].id ] = true;
    	if( data[i].f != -1 ) {
    		vit[ data[i].f ] = true;
    		join(data[i].f, data[i].id);
    	} 
    	if( data[i].m != -1 ) {
    		vit[ data[i].m ] = true;
    		join(data[i].m, data[i].id);
    	}

    	for(int j = 0; j < k; j++) {
    		cin >> data[i].c[j];
    		vit[ data[i].c[j] ] = true;
    		join(data[i].c[j], data[i].id);
    	}
    	cin >> data[i].num >> data[i].area; // 编号拥有的房子数 面积
    }

	 /******计算房子数&面积&家庭祖先是谁*****/
    for(int i = 0; i < n; i++) { // ans处理n个
    	int id = fd(data[i].id); // id找每个编号的最上的祖先
    	
    	ans[id].id = id; // 标记自己 便于输出
        ans[id].num += data[i].num; // 祖先房子数 += 当前这一行的房子数
    	ans[id].area += data[i].area; 
    	ans[id].flag = true; // id成为一个家庭
    }
   
    /*************计算人数***************/
   	for(int i = 0; i < maxn; i++) { // 暴力遍历
   		if( vit[i] ) // 为孩子 可访问
   			ans[ fd(i) ].people++; // 标记祖先的人数++
   		if( ans[i].flag ) // 为家庭
   			cnt++;  // 家庭数++
   	}

   	for(int i = 0; i < maxn; i++)
   		if( ans[i].flag ) // 家庭数
   			ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people),
   			ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);

   	sort(ans, ans + maxn, cmp);
   	cout << cnt << endl;
   	for(int i = 0; i < cnt; i++) 
   		printf("%04d %d %.3f %.3f\n",
   		ans[i].id, ans[i].people, ans[i].num, ans[i].area);
}
