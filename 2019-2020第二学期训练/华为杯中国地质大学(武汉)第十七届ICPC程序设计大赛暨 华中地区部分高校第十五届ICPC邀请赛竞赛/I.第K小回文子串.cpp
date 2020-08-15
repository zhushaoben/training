#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5,Si=10,mo=1e9+7;
struct palindromic_tree{
	int next[N][Si],fail[N],cnt[N],st[N],//首次出现位置 
	len[N],S[N],last,n,p;
	int newnode(int l){//新建节点 
		for(int i=0;i<Si;i++)next[p][i]=0;
		cnt[p]=0,len[p]=l;
		return p++;
	}
	void init(){
		p=n=last=0;
		newnode(0),newnode(-1);
		S[0]=-1,fail[0]=1;
	}
	int get_fail(int x){
		while(S[n-len[x]-1]!=S[n])x=fail[x];
		return x;
	}
	void add(int c){
		S[++n]=c;
		int cur=get_fail(last);
		if(!next[cur][c]){
			int now=newnode(len[cur]+2);
			fail[now]=next[get_fail(fail[cur])][c];
			next[cur][c]=now,st[now]=n-len[now]+1;
		}
		cnt[last=next[cur][c]]++;
	}
	void count(){//计算cnt 
		for(int i=p-1;i>=0;i--)cnt[fail[i]]+=cnt[i];
	}
}A;
char s[N];
int rk[N],sa[N],height[N],n,m=Si,c[N],x[N],y[N];

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
int b[N],w[N],mi[N][18],k1[N];
int lcp(int x,int y){
	if(x==y)return N;
	if(x>y)swap(x,y);
	int k=k1[y-x];
	return min(mi[x+1][k],mi[y-(1<<k)+1][k]);
}
struct Node{
	int st,l,num;
	bool operator < (const Node &b)const{
		int x=rk[st],y=rk[b.st],lc=lcp(x,y);
		if(l<=lc||b.l<=lc)return l<b.l;
		return x<y;
	}
}a[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*a*ans%mo;
		a=1ll*a*a%mo,b>>=1;
	}
	return ans;
}
int calc(int st,int la){return (w[la]-1ll*w[st-1]*qpow(10,la-st+1)%mo+mo)%mo;}
void ST_init(){
	for(int i=1;i<=n;i++)mi[i][0]=height[i];
	for(int i=0;i<17;i++)for(int j=1;j+(1<<i)<=n;j++)mi[j][i+1]=min(mi[j][i],mi[j+(1<<i)][i]);
	for(int i=0,j=0;i<18;i++)
		for(;j<=n&&j<=(1<<(i+1));j++)k1[j]=i;
}
void work(){
	scanf("%s",s+1),n=strlen(s+1);
	A.init();for(int i=1;s[i];i++)s[i]-='0',A.add(s[i]),w[i]=(10ll*w[i-1]+s[i])%mo;
	get_sa(),get_height(),ST_init();
	for(int i=A.p-1;i>=2;i--)A.cnt[A.fail[i]]+=A.cnt[i],a[i-1]={A.st[i],A.len[i],A.cnt[i]};
	int si=A.p-2,q,k,x;
	sort(a+1,a+si+1);
	for(int i=1;i<=si;i++)b[i]=a[i].num+b[i-1];
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&k);
		x=lower_bound(b+1,b+si+1,k)-b;
		printf("%d\n",calc(a[x].st,a[x].st+a[x].l-1));
	}
}
int main(){
	int t=1;
	scanf("%d",&t);
	while(t--)work();
	return 0;
} 
