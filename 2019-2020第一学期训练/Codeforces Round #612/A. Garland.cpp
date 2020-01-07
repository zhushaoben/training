#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=105;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,a[N],cnt[2],f[N][N][2],num[N];
int main()
{
	n=read();
	for(int i=1; i<=n; i++){
		a[i]=read(); num[i]=num[i-1];
		if(a[i]) cnt[a[i]%2]++;
		else num[i]++;
	}
	cnt[0]=n/2-cnt[0]; cnt[1]=n/2+n%2-cnt[1];
	clr(f, 7); f[0][0][0]=f[0][0][1]=0;
	for(int i=1; i<=n; i++){
		int x=a[i],tot=min(cnt[0], num[i]);
		for(int j=0; j<=tot; j++){
			if(x) {f[i][j][x%2]=min(f[i-1][j][x%2], f[i-1][j][(x%2)^1]+1); continue;}
			if(j) f[i][j][0]=min(f[i-1][j-1][0], f[i-1][j-1][1]+1);
			if(num[i]-j<=cnt[1]) f[i][j][1]=min(f[i-1][j][0]+1, f[i-1][j][1]);
		}
	}
	int ans=min(f[n][cnt[0]][0], f[n][cnt[0]][1]);
	printf("%d\n",ans);
}
