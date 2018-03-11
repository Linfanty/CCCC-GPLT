#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i, j;
    int sex[50];
    char name[50][20];
    int arr[50] = {0};

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &sex[i]);
        scanf("%s", name[i]);
    }

    for(i = 0; i < n; i++)//从左边遍历
    {
        for(j = n-1; j >= 0; j--)//从右边找最靠右的、复合标准的人
        {
            if(arr[i] == 0 && arr[j] == 0 && sex[i] != sex[j])
            //找出符合条件的人，没被输出过，并且性别不同
            {
                printf("%s %s\n", name[i], name[j]);
                arr[i] = 1;
                arr[j] = 1;
            }
        }
    }
}