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

int main() {
	int n; cin >> n;
	string s;
	ll fz = 0, fm = 1;
	ll a, b;

	for(int i = 1;  i <= n; i++) {
		scanf("%lld/%lld", &a, &b);
		fz = b*fz + a*fm;
		fm = fm * b;

		if( a == 0 || fz == 0){
			cout << 0;return 0;}

		// show4(a, b, fm, fz);
		ll g = __gcd(fz, fm);
		fz = fz/g;
		fm = fm/g;
	}
	if( abs(fz) >= abs(fm) && fz%fm != 0) 
		cout << fz/fm << ' ';
	else if( abs(fz) >= abs(fm) && fz%fm == 0)
		cout << fz/fm ;
	if( fz%fm != 0)
		cout << fz%fm << '/' << fm <<endl;
} 