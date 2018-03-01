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

struct bag{
	int id, income, num;
}a[maxn];

bool cmp(bag x, bag y) {
	if( x.income == y.income )
		if( x.num == y.num )
			return x.id < y.id;
		else return x.num > y.num;
	else return x.income > y.income;
}

int main() {
	int k, n, d, p;
	cin >> n;
	for(int i = 0; i <= n; i++) {
		a[i].id = i; a[i].income = a[i].num = 0;
	}
    
    for(int i = 1; i <= n; i++) {
    	cin >> k;
    	for(int j = 0; j < k; j++) {
    		cin >> d >> p;
    		a[d].income += p;
    		a[d].num++;
    		a[i].income -= p;// subtrat
    	}
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    	printf("%d %.2lf\n", a[i].id, (double)a[i].income/100.0);
}


