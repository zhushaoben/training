#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=200005;
const ll INF=1e18;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,q,a[N],b[N];
int main(){
	n=read(); q=read();
	for(int i=1; i<=n; i++){
		b[i]=read()%2+b[i-1];
	}
	for(int i=1; i<=n; i++){
		a[i]=read()%2+a[i-1];
	}
	for(int i=0;i<q;i++){
		int x1=read(),y1=read(),x2=read(),y2=read();
		if(x1>x2)swap(x1,x2);if(y1>y2)swap(y1,y2);
		if((b[x2]-b[x1-1]==x2-x1+1&&a[y2]-a[y1-1]==y2-y1+1)||(b[x2]-b[x1-1]==0&&a[y2]-a[y1-1]==0))puts("YES");
		else puts("NO");
	}
	
}
