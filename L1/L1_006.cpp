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

ll n;
ll ans[maxn] = {0};

int main() {
    cin >> n;
    
    if( n == 1) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }

    int cnt = 0;
    for(ll i = 2; i * i <= n; i++) {
        if( (n%i) == 0) {
            ans[cnt++] = i;
            if( i != (n/i))
                ans[cnt++] = n/i;
        }   
    }
    ans[cnt++] = n; 
    sort(ans, ans+cnt);
    // for(int i = 0; i < cnt; i++) show(ans[i]);

    int max1 = 1;
    int ansl = 1, ansr = 1;

    for(int i = 1; i < cnt; i++){
        int j = i;
        // 少了一个条件，连续因子乘积要比本身小
        // 少了两个条件，n/连续因子乘积还是因子
        ll ans_ = ans[j] * ans[j-1];
        while( ans[j] - ans[j-1] == 1 && ans_ <= n && n%ans_ == 0) j++, ans_ *= ans[j];
        
        if( j - i + 1 > max1 ){
            ansl = i-1, ansr = j-1;
            // show4(i-1, j-1, ans[i-1], ans[j-1]);
            max1 = j - i + 1;
        }
    }

    
    if( max1 == 1){
        cout << 1 << endl << ans[0] << endl;
        return 0;
    }
    cout << max1 << endl;
    for(int i = ansl; i <= ansr; i++)
        if( i != ansr)
            cout << ans[i] << '*';
        else cout << ans[i];
    cout << endl;
}


