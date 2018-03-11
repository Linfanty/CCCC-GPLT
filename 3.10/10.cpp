#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int a[10] = {0};
    for(int i = 0; i < 11; i++) a[s[i] - '0']++;

    vector<int> arr;
    for(int i = 9; i >= 0; i--) if(a[i] != 0)  arr.push_back(i); // 8,3,2,1,0
    
    vector<int> index;
    for(int i = 0; i < 11; i++) //遍历11位 s[0 1 2 3 4 5 6 7 8 9]
        for(int j = 0; j < arr.size(); j++) // 看每一位是arr的第几个
            if((s[i] - '0') == arr[j])
                index.push_back(j);

    cout << "int[] arr = new int[]{" << arr[0];
    for(int i = 1; i < arr.size(); i++) cout << "," << arr[i];

    cout << "};" << endl << "int[] index = new int[]{" << index[0];

    for(int i = 1; i < index.size(); i++) cout << "," << index[i];

    cout << "};";
}