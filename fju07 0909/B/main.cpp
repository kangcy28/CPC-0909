#include <iostream>

using namespace std;

int main()
{
    unsigned long long n=0,m=0,ans=0,x,y;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(x>y)
            m=x;
        else if(x<y)
            m=y;
        else
            m=x;

        if(m%2){
            if(x > y)
                ans = (m - 1) * (m - 1) + y;
            else
                ans = m * m - x + 1;

        }else{
            if(y > x)
                ans = (m - 1) * (m - 1) + x;
            else
                ans = m * m - y + 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}

