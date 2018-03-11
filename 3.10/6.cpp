#include<iostream>
#include<map>
using namespace std;
map<string,string> a;
int main()
{
    a["ChuiZi"]="Bu";
    a["Bu"]="JianDao";
    a["JianDao"]="ChuiZi";

    int n; cin>>n;
    int sum=0;
    string s;

    while(cin>>s) {
        if(s[0]=='E')break;
        sum++;

        if(sum<=n)
            cout<<a[s]<<endl;
        else
            sum=0, cout<<s<<endl;
    }
}