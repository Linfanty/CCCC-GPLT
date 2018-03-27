#include <bits/stdc++.h>
using namespace std;

// bool类型的choice[i][j]数组dp[i][j]是否选取
// 选取了就令choice为true
const int maxn = 10010;

int w[maxn];
int dp[maxn];
bool choice[maxn][maxn];


int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> w[i];
	sort(w + 1, w + 1 + n, greater<int>());
	for(int i = 1; i <= n; i++) {
		for(int j = m; j >= w[i]; j--){
			if( dp[j] <= dp[j - w[i]] + w[i])
				choice[i][j] = true,
				dp[j] = dp[j - w[i]] + w[i];
		} 
	}

	if( dp[m] != m ) cout << "No Solution\n";
	else {
		vector<int> arr;
		int v = m ,index = n;
		while( v > 0 ) {
			if( choice[index][v] )
				arr.push_back( w[index] ),
				v -= w[index];
			index--;
		}

		cout << arr[0];
		for(int i = 1; i < arr.size(); i++)
				cout << ' ' << arr[i];
	}

}