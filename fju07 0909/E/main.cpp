#include <iostream>
#include <algorithm>
#include <cmath>
#define lchild rt << 1, l, m
#define rchild rt << 1 | 1, m + 1, r
using namespace std;
int array[1<<20];    // �ƦC

struct Node
{

    int mi;    // ��U�Ҧ��𸭪��϶��̤p��

} node[1<<21];  // �ΰ}�C�����G����

// �ΰ}�C�����G����G���p�ġB�k�p��
int LC(int i) {return i*2;}
int RC(int i) {return i*2+1;}

//int sum[1<<10];   // ��²�K���g�k

void build(int L, int R, int i)
{
    if (L == R)
    {
        // �]�w�𸭪��ƭ�
        node[i].mi = array[L];
        return;
    }

    int M = (L + R) / 2;
    build(L  , M, LC(i));   // ���j�إߥ��l��
    build(M+1, R, RC(i));   // ���j�إߥk�l��

    // �^���ɶ��K�p���`�M
    node[i].mi = min(node[LC(i)].mi,node[RC(i)].mi);
}
int x1, x2, ans;  // �d�߽d��[x1,x2]�åB�֭p�`�M
void query(int L, int R, int i)
{
    if (x1 <= L && R <= x2)
    {
        ans=min(ans,node[i].mi);
        return;
    }

    int M = (L + R) / 2;
    if (x1 <= M) query(L  , M, LC(i));  // ���j�d�ߥ��l��
    if (x2 >  M) query(M+1, R, RC(i));  // ���j�d�ߥk�l��
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
