#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
const int maxn = 50005;
    int mx[maxn<<2], sum[maxn<<2];
    char op[10];
    int a, b, n, m, t, ww = 1;
        #define lson rt<<1, l, (l+r)>>1
        #define rson rt<<1| 1, ((l+r)>>1)+1, r

    void pushup(int rt){
        mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }

    void build(int rt, int l, int r)
    {
        if(l == r)
            {scanf("%d", &sum[rt]); return;}
        build(lson);
        build(rson);
        pushup(rt);
    }

    void update(int rt, int l, int r)
    {
        if(a < l || a > r) return;
        if( l == r)
            {sum[rt] += b;  return;}
        update(lson);
        update(rson);
        pushup(rt);
    }

    int query(int rt, int l, int r)
    {
        if(a <= l && b >= r )   return sum[rt];
        if(a > r || b < l) return 0;
        int ans = 0;

        ans += query(lson);
        ans += query(rson);
        return ans;
    }

int main()
{
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    printf("Case %d:\n",ww++);
		build(1, 1, n);

		while (1)
		{
			scanf("%s",op);
			if( op[0] == 'E') break;
                scanf("%d %d", &a, &b);
			if(op[0] == 'A')
                update(1, 1, n);
            else if(op[0] == 'S')
                b = -b, update(1, 1, n);
            else if(op[0] == 'Q')
                printf("%d\n", query(1, 1, n));
            else break;
		}
	}
    return 0;
}