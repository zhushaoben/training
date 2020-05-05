#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e5+5;
char s[N];
int rk[N],sa[N],height[N],n,m,c[N],x[N*2],y[N];
//n为长度,m为关键字集大小 
//rk[i] 第i个后缀的排名 
//sa[i] 排名为i的后缀位置
//height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP 
//c为基数排序桶,x[i]为suf(i)的第一关键字(x使用是可能大于n)
//y[i]表示第二关键字排名为i的数，第一关键字的位置 

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
int f[N][18];
inline int query(int l1,int r1){
	int l=rk[l1],r=rk[r1];
	if(l>r)swap(l,r);l++;
	int k=log(r-l+1)/log(2.0);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
void ST(){
	int m=log(n)/log(2.0);
	for(int i=1;i<=n;i++)f[i][0]=height[i];
	for(int i=0;i<m;i++)
		for(int j=n-(1<<(i+1))+1;j>=0;j--)
			f[j][i+1]=min(f[j][i],f[j+(1<<i)][i]);
}
void work(){
	n=strlen(s+1),m=122;
	int ans=1,ans1=1,ans2=1;
	get_sa(),get_height();ST();
	for(int i=2;i<=n;i++)if(rk[i]<rk[ans1])ans1=i;
	for(int l=1;l<=n;l++){
		for(int i=1;i+l<=n;i+=l){
			int w=query(i,i+l),t=i-(l-w%l),w1=w/l+1;
			if(t>0&&query(t,t+l)>=(l-w%l))w1++;
			else t=i;
			if(w1>=ans)for(int j=t-1;j>i-l&&s[j]==s[j+l];j--)if(rk[j]<rk[t])t=j;
			if(w1>ans)ans=w1,ans1=t,ans2=l*w1;
			else if(w1==ans&&rk[t]<rk[ans1])ans1=t,ans2=l*w1;
		}
	}
	for(int i=0;i<ans2;i++)putchar(s[ans1+i]);
	puts("");
}
int main(){
	int T=0; 
	while(~scanf("%s",s+1)&&s[1]!='#')printf("Case %d: ",++T),work();
	return 0;
}
