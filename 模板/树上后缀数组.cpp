#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];
int sa[N],n,m,c[N],x[N],y[N],fa[N];
//n为长度,m为关键字集大小 
//sa[i] 排名为i的后缀位置
//c为基数排序桶,x[i]为suf(i)的第一关键字
//y[i]表示第二关键字排名为i的数，第一关键字的位置 
void get_sa(){//求sa数组 
	memset(c,0,sizeof(int)*(m+1));
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
	for(int i=2;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	for(int k=0;(1<<k)+1<=n;k++){
		//与普通sa不同，这里处理y也需要借助c数组 
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
