#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*
分析：接收所有数据到数组v中，并且将所有数据的总和累加为sum，
然后对数组从小到大排序，计算前一半的总和为half，
那么外向的人的个数就为(n + 1) / 2，
【因为如果n是偶数就是n/2，如果n是奇数就是n/2 + 1，总的来说就是(n + 1) / 2】，
内向的人的个数就是n/2，
两者之间的差就是(sum – half) – half【即sum – 2 * half 】
*/

int main() {
    int n, sum = 0, half = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n / 2; i++)
        half += v[i];
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", (n + 1) / 2, n / 2, sum - 2 * half);
    return 0;
}