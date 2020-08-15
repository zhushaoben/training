#include <bits/stdc++.h>
using namespace std;
int euclid_gcd(int x,int y)
{
    while(y)
    {
        int t=x%y; x=y; y=t;
    }
    return x;
}
int tmd=-1;
 
int n,m,k,q[5005][5005],head[5005],tail[5005],pos[5005][5005],f[5005];
int q2[5005],h2,t2,p2[5005];
 
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++) head[i]=1,tail[i]=0;
     
    long long ans=0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            int x=i*j/euclid_gcd(i, j);
            while(pos[j][head[j]] < i-k+1 && head[j]<=tail[j]) head[j]++;
            while(x>=q[j][tail[j]] && head[j]<=tail[j]) tail[j]--;
            pos[j][++tail[j]]=i;
            q[j][tail[j]]=x;
            f[j]=q[j][head[j]];
        }
        if(i<k) continue;
        h2=1,t2=0;
        for(int j=1; j<=n; j++) {
            int x=f[j];
            while(p2[h2] < j-k+1 && h2<=t2) h2++;
            while(x>=q2[t2] && h2<=t2) t2--;
            p2[++t2]=j;
            q2[t2]=x;
            if(j>=k) ans+=q2[h2];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
