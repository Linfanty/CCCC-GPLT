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

#include <cctype>

bool islegal(string s) {
    if(s.length() == 0)
        return false;
    for(int i = 0; i < s.length(); i++) {
        if(!isdigit(s[i])) {
            return false;
        }
    }
    int temp = stoi(s);
    if(temp < 1 || temp > 1000) {
        return false;
    }
    return true;
}

int main() {
    string a, b;
    string t;
    getline(cin, t);
    for(int i = 0; i < t.length(); i++) {
        if(t[i] == ' ') {
            a = t.substr(0, i);
            b = t.substr(i + 1, t.size()- i - 1);
            break;
        }
    }
    if(!islegal(a)) {
        a = "?";
    }
    if(!islegal(b)) {
        b = "?";
    }
    cout << a << " + " << b << " = ";
    if(a != "?" && b != "?") {
        int atemp = stoi(a);
        int btemp = stoi(b);
        cout << atemp + btemp;
    } else {
        cout << "?";
    }
    return 0;
}