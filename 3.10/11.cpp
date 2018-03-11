#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f
double a[10005][20];
double sum[10005];

int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&k,&m);
    memset(sum,0,sizeof(sum));
    for (int i=0;i<n;i++) {
        for(int j=0;j<k;j++) // 0 k
            scanf("%lf",&a[i][j]);
        sort(a[i],a[i]+k);
    }

    for (int i=0;i<n;i++) {
        for (int j=1;j<k-1;j++) // 1 k-1
            sum[i]+=a[i][j];
        sum[i]=sum[i]/(k-2);
    }

    sort(sum,sum+n);

    for (int i=n-m;i<n-1;i++)
        printf("%.3f ",sum[i]);
    printf("%.3f\n",sum[n-1]);
}
