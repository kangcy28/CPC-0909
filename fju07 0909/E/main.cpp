#include <iostream>
#include <algorithm>
#include <cmath>
#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r
using namespace std;
int array[1<<20];    // 數列

struct Node
{

    int mi;    // 其下所有樹葉的區間最小值

} node[1<<21];  // 用陣列模擬二元樹

// 用陣列模擬二元樹：左小孩、右小孩
int LC(int i) {return i*2;}
int RC(int i) {return i*2+1;}

//int sum[1<<10];   // 更簡便的寫法

void build(int L, int R, int i)
{
    if (L == R)
    {
        // 設定樹葉的數值
        node[i].mi = array[L];
        return;
    }

    int M = (L + R) / 2;
    build(L  , M, LC(i));   // 遞迴建立左子樹
    build(M+1, R, RC(i));   // 遞迴建立右子樹

    // 回溯時順便計算總和
    node[i].mi = min(node[LC(i)].mi,node[RC(i)].mi);
}
int x1, x2, ans;  // 查詢範圍[x1,x2]並且累計總和
void query(int L, int R, int i)
{
    if (x1 <= L && R <= x2)
    {
        ans=min(ans,node[i].mi);
        return;
    }

    int M = (L + R) / 2;
    if (x1 <= M) query(L  , M, LC(i));  // 遞迴查詢左子樹
    if (x2 >  M) query(M+1, R, RC(i));  // 遞迴查詢右子樹
}


int main()
{
    int n;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>array[i];
    }
    build(1,n,1);
    for(int i=0;i<n;i++){
        cin>>x1>>x2;
        ans=1000000;
        query(1,n,1);
        cout<<ans<<'\n';
    }
    return 0;
}
