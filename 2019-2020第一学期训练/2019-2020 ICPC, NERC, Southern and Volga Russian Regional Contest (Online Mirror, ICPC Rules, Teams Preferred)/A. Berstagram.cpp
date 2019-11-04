#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=100005;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[N],b[N],mi[N],ma[N],x,y,n,m;
int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++)(a[i]=b[i]=mi[i]=ma[i]=i);
	for(int i=1;i<=m;i++){
		x=read();if(a[x]==1)continue;
		swap(a[x],a[y=b[a[x]-1]]),swap(b[a[x]],b[a[y]]);
		mi[x]=min(mi[x],a[x]),ma[y]=max(ma[y],a[y]);
	}
	for(int i=1;i<=n;i++){
		printf("%d %d\n",mi[i],ma[i]);
	}
	return 0;
}
