#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
const int N=110,M=7e4+10;
#define pr pair<int,int>
#define FR first
#define SE second
pr a[N];int f[N][M];
bool cmp(pr a,pr b)
{
	if((a.SE>=0)!=(b.SE>=0)) return (a.SE>=0)>(b.SE>=0);
	if(a.SE>=0) return a.FR<b.FR; else return max(a.FR,b.FR-a.SE)<max(b.FR,a.FR-b.SE);
}
void chmax(int &x,int y){x=max(x,y);
}
int main()
{
	int n,now;scanf("%d%d",&n,&now);
	for(int i=1;i<=n;i++) {int x,y;scanf("%d%d",&x,&y);a[i]=make_pair(x,y);}
	sort(a+1,a+n+1,cmp);
//	printf("-----=%d\n",a[1].SE);
	memset(f,-63,sizeof f);
	f[0][now]=0;int mx=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=M-1;j>=0;j--) if(f[i-1][j]>=-100)
		{
			if(j==100)
			j=100;
//			printf("i=%d j=%d kk=%d\n",i,j,j>=a[i].FR and j+a[i].SE>=0);
			if(j>=a[i].FR and j+a[i].SE>=0) chmax(f[i][j+a[i].SE],f[i-1][j]+1),chmax(mx,f[i-1][j]+1);
			chmax(f[i][j],f[i-1][j]);chmax(mx,f[i-1][j]);
//			printf("f(%d,%d)=%d\n",i-1,j,f[i-1][j]);
		}
	}
//	if(mx==n) puts("YES"); else puts("NO");
	printf("%d",mx);
}
/*
3 10
10 0
10 -10
30 0
 
2
*/
