#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int sa[N],n,m,c[N],x[N],y[N],fa[N];

void get_sa(){//ÇósaÊý×é 
	memset(c,0,sizeof(int)*(m+1));
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(int i=2;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	for(int k=0;(1<<k)+1<=n;k++){
		memset(c+1,0,m<<2);
		for(int i=1;i<=n;i++)c[x[fa[i]]]++;
		for(int i=1;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i;i--)y[c[x[fa[i]]]--]=i;
		
		memset(c+1,0,m<<2);
		for(int i=1;i<=n;i++)c[x[i]]++;
		for(int i=2;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i;i--)sa[c[x[y[i]]]--]=y[i];
		swap(x,y);
//		memcpy(x,y,sizeof(int)*(n+1));
		int num=x[sa[1]]=1;
		for(int i=2;i<=n;i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[fa[sa[i]]]==y[fa[sa[i-1]]])?num:++num;
		for(int i=n;i;i--)fa[i]=fa[fa[i]];
		if(num==n)break;
		m=num;
	}
}
void work(){
	scanf("%d%d",&n,&m),m=200;
	scanf("%s",s+1);
	for(int i=2;i<=n;i++)scanf("%d",fa+i);
	get_sa();
	for(int i=1;i<n;i++)printf("%d ",sa[i]);
	printf("%d\n",sa[n]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
