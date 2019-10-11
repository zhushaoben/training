#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std; 
const int N=5e5+5,M=1e7+5;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,x[17],y[17],f[17][65539];
int calc(int x1,int y1,int x2,int y2)
{
	int x=abs(x1-x2),y=abs(y1-y2);
	if(x>y)swap(x,y);
	if(!x){
		if(y%4==0)return y;
		return y+2;
	}
	if(x>=2&&y>=2)return x+y;
	if((x%4)==0||(y%4)==0)return x+y;
	if(x==1&&y==1)return 6;
	return x+y+2;
}

void solve()
{
	n=read();
	for(int i=0;i<n;i++){
		x[i]=read(); y[i]=read();
	}
	clr(f, 60);
	for(int i=0;i<n;i++){
		f[i][1<<i]=calc(0, 0, x[i], y[i]);
	}
	for(int i=1; i<(1<<n); i++){
		for(int j=0; j<n; j++)if((1<<j)&i){
			int t=i^(1<<j);
			for(int k=0; k<n; k++)if((1<<k)&t){
				f[j][i]=min(f[j][i], f[k][t]+calc(x[j], y[j], x[k], y[k]));
			}
		}
	}
	int ans=1e9;
	for(int i=0;i<n;i++)
	  ans=min(ans, f[i][(1<<n)-1]);
	printf("%d\n",ans);
}
int main()
{
	int T=read();
	while(T--) solve();
}
