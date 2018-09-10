#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string m;

    while(cin>>m,m!="0"){
        int cnt=0;
        long long a=0,b=1,g;

        for(int i=0;i<m.size();i++){
            if(m[i]=='.'){
                cnt = m.size()-i-1;
                break;
            }
        }
       for(int i=0;i<cnt;i++){
            b=b*10;
       }
        for(int i=0;i<m.size();i++){
            if(m[i]=='.')
                continue;
            else{
                a+=(m[i]-'0');
                a*=10;
            }
        }
        a/=10;
        g = __gcd(a,b);
        a/=g;
        b/=g;
        cout<<a<<"/"<<b<<endl;
    }
    return 0;
}
