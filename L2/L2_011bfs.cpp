#include  <iostream>
#include  <cstdio>
#include  <cstring>
#include  <queue>
using namespace std;
const int maxn=1000000;
int n,num(0);
int pre[maxn],in[maxn],tree[maxn];

void build(int tag,int left,int right) {
	tree[tag]=pre[++num];

	if(left==right) return;
	int index=-1;
	for(int i=left;i<=right;i++) if(in[i]==tree[tag]) index=i;
	if(index==-1) return;

	if(index-1>=left)  build(tag<<1, left, index-1);
	if(index+1<=right)  build(tag<<1|1, index+1, right);
}

void bfs() {

	queue<int> que;
	que.push(1);
	int tag = tree[1];

	while(!que.empty()){
		int temp=que.front();
		que.pop();

		if(tree[temp]!=tag) printf(" ");
		printf("%d",tree[temp]);

		if(tree[temp*2+1]!=0) que.push(temp*2+1);
		if(tree[temp*2]!=0)  que.push(temp*2);
	}
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&in[i]);
	for(int i=1;i<=n;i++) scanf("%d",&pre[i]);

	build(1,1,n);
	bfs();
}