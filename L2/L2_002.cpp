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

int first_address;
int n;
int address[maxn];
map<int, int> key;
map<int, int> nxt;
int j;
int check[maxn];
int mp[maxn];

struct node{
	int address, key, nxt;
}ans[maxn];
int cnt = 0;

int main() {
	cin >> first_address >> n;
	memset(check, 0,sizeof check);

// nt[5] = 2

    for(int i = 1; i <= n; i++) {
    	cin >> address[i];
    	cin >> key[address[i]] >> nxt[address[i]];
    	mp[ address[i] ] = i;
    	if( address[i] == first_address )
    		j = i;
    }
    mp[-1] = 100000;

    while(1) {
    	printf("%05d %d", address[j], key[address[j]]);
    	//show4(j, address[j], key[address[j]], nxt[address[j]]);
    	int mid = abs(key[address[j]]);
    	check[mid] = 1;


    	while( check[ abs(key[nxt[address[j]]]) ] == 1 ) // == 1
    	{
    		ans[cnt].address = nxt[address[j]];
    		ans[cnt].key = key[nxt[address[j]]];
    		ans[cnt].nxt = nxt[ nxt[address[j] ]];
    		// show4(cnt,ans[cnt].address,ans[cnt].key,ans[cnt].nxt);
    		cnt++;
    		j = mp[ nxt[address[j]] ];
    		if(  j == 100000 )
    			break;
    	}

    	if(  nxt[address[j]] == -1)
    		printf(" -1\n");
		else printf(" %05d\n",nxt[address[j]]);
		j = mp[ nxt[address[j]] ];

    	if( j == 100000 )
    		break;
    }
    for(int i = 0; i < cnt-1; i++)		
    	printf("%05d %d %05d\n", ans[i].address,
    		ans[i].key, ans[i+1].address);

    if( cnt!= 0) printf("%05d %d -1\n", ans[cnt-1].address,
    		ans[cnt-1].key);
// 23854 -15 00000
// 00000 -15 99999
}
