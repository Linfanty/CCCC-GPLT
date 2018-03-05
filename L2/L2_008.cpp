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

int main() {
	/* code */
	string s;
	getline(cin, s);
	int max1 = 0, tmp;
	int len = s.size();
	for(int i = 0; i  < len; i++) {
		tmp = 1;	

		///回文串为奇数
		// j表示i-j与i+j构成的回文字串长度 1 2 3
		for(int j = 1; j < len; j++) {
			if( i - j < 0 || i + j >= len || s[i-j] != s[i+j])
				break;
			tmp += 2;
		}
	   	max1 = max(max1, tmp);
	   	tmp = 0;

	    ///回文串为偶数
	    // j表示i+1左边j个字符一直到i右边j个字符的回文字串长度 2 3 所以i-j+1
		for(int j = 1; j < len; j++) {
			if( i - j + 1 < 0 || i + j >= len || s[i-j+1] != s[i+j] )
				break;
			tmp += 2;
		}
		max1 = max(tmp, max1);
	}
	cout << max1;
}
