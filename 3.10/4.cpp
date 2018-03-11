#include <iostream>  
#include <stdio.h> 
#include <math.h>  
typedef long long ll;  
using namespace std; 

int su(int n){  
    if(n==1){return 1;}  
    for (int i=2; i<=sqrt(n); i++) {  
        if(n%i==0){  
            return 1;  
        }  
    }  
    return 0;  
}  
int main(){  
    int n,t;  
    scanf("%d",&t);  
    while (t--) {  
        scanf("%d",&n);  
        if(su(n)){printf("No\n");}  
        else printf("Yes\n");  
    }  
    return 0;  
}  