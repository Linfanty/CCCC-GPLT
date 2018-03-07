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

// 二维数组v存储关系
// v[i]表示编号为i的师傅所拥有的徒弟
// 徒弟个数等于0 得道者 v[i][0]保存放大的倍数
vector<vector<int> > v;
int n, k;

double result = 0.0;
bool vit[100010];

double z, r;


// 输出所有得道者的功力总值
// dfs向下找 直到是得道者
void dfs(int index, double power) {// ???? power 再减小
	if( vit[index] == true) {
		result += power * v[index][0];
		return;
	}

	for(int i = 0; i < v[index].size(); i++) // zhao tu di	
		dfs(v[index][i], power * (1 - r / 100) );
}


int main() {
	cin >> n >> z >> r;
    v.resize(n);

    for (int i = 0; i < n; i++) {
    	cin >> k;

    	int tmp;
    	if( k == 0) {
    		cin >> tmp;
    		v[i].push_back(tmp);
    		vit[i] = true; // ** 
    	}
    	else {
    		for(int j =  0; j < k; j++) {
    			cin >> tmp;
    			v[i].push_back(tmp);
    		}
    	}
    }
   	dfs(0, z);  
   	cout << (int)result;
}
