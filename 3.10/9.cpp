#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);
  string s;
  getline(cin, s);
  int len = s.size();

  int pos, ed;

  if( len%n == 0)
    pos = (len/n-1)*n + 1, ed = len;// 能除尽时 修改起始pos的位置 
  else {
    pos = (len/n)*n + 1; // 起始位置 
    for(int j = len+1; ; j++) {
      s += ' '; // 末尾补空格
      if( j%n == 0)
       { ed = j; break;} // 能除尽时 更正末尾ed的位置 
    }
  }

  // show2(pos, ed);
  for(int i = pos; i <= ed ; i++) { // a 到 空格
    for(int j = 0; j < ed/n; j++) // 0 ~ 结尾/n 每行的个数
      cout << s[i-1 - j*n ];  // 依次往前j*n个
    cout << endl;
  }
}