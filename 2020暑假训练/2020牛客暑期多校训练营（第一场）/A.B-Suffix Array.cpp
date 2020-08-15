#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int rk[N],sa[N],height[N],n,m,c[N<<1],x[N],y[N],s[N];
char s1[N];
void get_sa(){//求sa数组 
	memset(c,0,sizeof(int)*(m+1));
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
void get_height(){//求rk和height 
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){
		if(k)--k;//h[i]>=h[i-1]+1,其中h[i]=height[rk[i]]
		if(rk[i]==1)continue;
		int j=sa[rk[i]-1];
		while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k])k++;
		height[rk[i]]=k;
	}
}
void work(){
	int a=0,b=0;m=n+2;
	for(int i=n-1;~i;i--){
		if(s1[i]=='a')s[i+1]=(a?a:i+n)-i,a=i;
		else s[i+1]=(b?b:i+n)-i,b=i;
	}
	s[++n]=n+1;
	get_sa();
	for(int i=n-1;i>=1;i--)printf("%d ",sa[i]);
	puts("");
}
int main(){
	while(~scanf("%d%s",&n,s1))work();
	return 0;
}
