#include<bits/stdc++.h>
using namespace std;  
#define MAXN 1010  
int c[MAXN], f[MAXN];  
  
int find(int x)  {  
    return x == f[x] ? x : f[x] = find(f[x]);  
}  
  
void merge(int x, int y) {  
    x = find(x);  
    y = find(y);  
    if(x != y) f[x] = y;  
}  
  
int main()  
{  
    int n, v, t, tt;  
    scanf("%d", &n);  
    for(int i = 0; i < 1010; i++) f[i] = i;  

    for(int i = 0; i < n; i++) {  
        scanf("%d: ", &t);  
        scanf("%d", &tt);  // 题目保证每人至少有一个兴趣
        c[i] = tt;  // 第i人的第一个兴趣

        for(int j = 1; j < t; j++)   {  
            scanf("%d", &v);  
            merge(tt, v);  // 后续的每个兴趣个和第一个兴趣合并
        }  
    }

    int num[1010] = {0}, cnt = 0;  
    for(int i = 0; i < n; i++)  // 枚举每个人 的第一个兴趣编号
        //cout << i << ' ' << c[i] << ' ' << find(c[i]) << endl,
        num[find(c[i])]++;  //fd（c[i]） [10] [4] [3]

    for(int i = 0; i < 1010; i++)  
        if(num[i]) // 计算 几个集合
            cnt++;  

    sort(num, num + 1010, greater<int>());  
    printf("%d\n", cnt);  

    printf("%d", num[0]);  
    for(int i = 1; i < cnt; i++)  
        printf(" %d", num[i]);   
}  