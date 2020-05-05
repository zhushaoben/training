#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int sa[N],n,m,c[N],x[N*2],y[N];
//n为长度,m为关键字集大小 
//rk[i] 第i个后缀的排名 
//sa[i] 排名为i的后缀位置
//height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP 
//c为基数排序桶,x[i]为suf(i)的第一关键字(x使用是可能大于n)
//y[i]表示第二关键字排名为i的数，第一关键字的位置 

void get_sa(){//求sa数组 
	for(int i=1;i<=n;i++)c[x[i]=s[i]]++,x[i+n]=0;//suf(i)第一关键字初始为s[i] 
	for(int i=2;i<=m;i++)c[i]+=c[i-1];
	for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1){//k为当前关键字长度 
		int num=0;
		for(int i=n-k+1;i<=n;i++)y[++num]=i;//有k个后缀没有第二关键字
		for(int i=1;i<=n;i++)if(sa[i]>k)y[++num]=sa[i]-k;
		memset(c,0,sizeof(int)*(m+1));
		for(int i=1;i<=n;i++)++c[x[i]];
		for(int i=2;i<=m;i++)c[i]+=c[i-1];//c表示第一关键字<=i的后缀数量 
		for(int i=n;i;i--)sa[c[x[y[i]]]--]=y[i];//计算两个关键字决定的sa
		//下面y暂存关键字长度翻倍后的x数组 
		num=1;
		y[sa[1]]=1;
		//扩展第一关键字时合并相同的 
		for(int i=2;i<=n;i++)y[sa[i]]=(x[sa[i]]==x[sa[i-1]]&&x[sa[i]+k]==x[sa[i-1]+k])?num:++num;
		if(num==n)break;//已排好 
		m=num;//更新关键字集大小
		memcpy(x,y,sizeof(int)*(n+1));
	}
}
void work(){
	scanf("%s",s+1);
	n=strlen(s+1),m=122;
	get_sa();
	for(int i=1;i<=n;i++)printf("%d ",sa[i]);
}
int main(){
	work();
	return 0;
}
