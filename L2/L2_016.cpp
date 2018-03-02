#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int sex, f, m; // sex father mather
}node[100010];

int level[100010]; // 标记他们当前的层数
bool exist[100010]; // 标记是否存在这个结点
 

int main() {
	int n, m, id, fa, ma, a, b;
	cin >> n;
	char c;
	for(int i = 1; i <= n; i++) {
		scanf("%d %c %d %d",&id, &c, &fa, &ma);
		node[id].f = fa; node[id].m = ma;

		if( c == 'M') node[id].sex = 0; // nan
		else node[id].sex = 1; // nv
	
		exist[id] = true; // 存在这个结点 避免不小心把0压入到队列里面
		node[ fa ].sex = 0; // nan
		node[ ma ].sex = 1; // nv
	}   

	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		// memset(level, 0, sizeof level); // false
		fill(level, level + 100010, 0); // true

		scanf("%d %d", &a, &b);
		if( node[a].sex == node[b].sex ) // 两人是同性
		{  printf("Never Mind\n"); continue; } 

		queue<int> q;
		q.push(a); q.push(b);
		level[a] = 1; level[b] = 1; 
	
		set<int> s;
		int flag = 0;
		/*以上 初始条件*/

		while( !q.empty() ) { // 如果结束了还没有输出过No，那么就输出yes
			int top = q.front(); q.pop();
			int size = s.size();
			s.insert(top);
// 判断set前后有没有大小改变，如果没改变说明重复了，所以有相同祖先
			if( size == s.size() ) {  // 和集合有已有元素一样
				printf("No\n"); // No ooooooooo
				flag = 1;
				break;
			}
			if( exist[top] == false ) continue; // 没有就不要push了
			if( level[top] <= 4 ) { // 层数为上一层+1 到五层判断结束
				fa = node[top].f;
				ma = node[top].m;
				if( fa != -1 ) {
					q.push(fa);
					level[fa] = level[top] + 1;
				}
				if( ma != -1 ) {
					q.push(ma);
					level[ma] = level[top] + 1;
				}
			}
		} 
		if( flag == 0 ) printf("Yes\n");
	}
}
