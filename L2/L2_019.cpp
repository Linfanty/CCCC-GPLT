#include <bits/stdc++.h>
using namespace std;  
/*题意： 
    记录被点赞的名单列表，统计所有点赞数并求平均数， 
    遍历点赞的名单列表， 
    如果该人的点赞数大于平均数且不在关注名单中， 
    则用set记录该人名。 用set自动实现字典序排列。 
*/    
struct node  
{  
   string s;  
   int num;  
}no[10005];        //记录名单  
map<string,int>mp; //记录关注的人  
set<string>se;     //记录答案  

int main()  
{  
   int n;  
   string s;  
   scanf("%d",&n);   
   for(int i=0;i<n;i++){  
      cin>>s;  
      mp[s]++;  
   }  

   scanf("%d",&n);  
   int sum = 0;  
   for(int i=0;i<n;i++){  
      cin>>no[i].s;  
      cin>>no[i].num;  
      sum += no[i].num;  
   }  

   double avg = sum * 1.0 / n;    //计算平均数  
   for(int i=0;i<n;i++){  
      if(mp[no[i].s]) continue;  //如果在关注名单中则跳过  
      if(no[i].num<avg) continue;//如果小于平均数则跳过  
      se.insert(no[i].s);        //符合要求的答案，插入set中  
   }  

   if(se.size()==0) printf("Bing Mei You"); //没有符合要求的人名  
   else{  
      set<string>::iterator it;             //输出set中记录的数据  
      for(it=se.begin(); it!=se.end();it++){  
         cout<<*it<<endl;                     
      }  
   }   
}  
