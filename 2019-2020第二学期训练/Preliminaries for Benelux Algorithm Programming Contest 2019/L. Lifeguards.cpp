#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
typedef long long LL;
struct Node{
    LL x,y;
    bool operator < (const Node &b)const{
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
}a[maxn];
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
    sort(a,a+n);
    LL inf=1000000000000ll,x=(a[n>>1].x+a[(n-1)>>1].x),y=(a[n>>1].y+a[(n-1)>>1].y);
    printf("%lld %lld\n%lld %lld\n",(long long)floor(x/2.0)-inf,(long long)floor(y/2.0)-1,(long long)ceil(x/2.0)+inf,(long long)ceil(y/2.0)+1);
    return 0;
}
