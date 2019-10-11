#include<bits/stdc++.h>
using namespace std;
#define maxn 300005
#define LL long long
char s[maxn];
int nex[maxn],la[50];
LL sum[maxn<<2],a[maxn],M,lazy[maxn<<2],k;
void build(int n){//建树 
	M=1;while((M<<=1)<n);
	M--;
	for(int i=1;i<=n;i++){
		sum[i+M]=a[i];
	} 
	for(int i=M;i>0;i--){
		sum[i]=sum[i<<1]+sum[i<<1|1]; 
	}
}
void change(int x,int y){//单点修改 
	x+=M;
	sum[x]+=y;
	while(x>>=1){
		sum[x]+=y;
	}
}
void modify(int l,int r,int w){//区间修改
	if(l>r)return;
	if(l==r){change(l,w);return;}
	int d=1;
	sum[l+M]+=w,sum[r+M]+=w;//注:下面的操作不会更新端点的值，所以提前将端点更新 
	for(l+=M,r+=M;l^r^1;l>>=1,r>>=1){
		if(~l&1)sum[l^1]+=w*d,lazy[l^1]+=w;//在对应的右子节点打个标记，更新sum的值 
		if(r&1)sum[r^1]+=w*d,lazy[r^1]+=w;//在对应的左子节点打个标记，更新sum的值 
		d<<=1;
		sum[l>>1]=sum[l]+sum[l^1]+lazy[l>>1]*d;//更新两个父节点的值,其中d表示父节点表示区间的长度 
		sum[r>>1]=sum[r]+sum[r^1]+lazy[r>>1]*d;
	}
	while(l>>=1)d<<=1,sum[l]=sum[l<<1]+sum[l<<1|1]+lazy[l]*d;//更新路径上节点的sum值 
}
int query_node(int l){//单点查询
	int x=l+M,ans=0;
	while(x>>=1){
		if(lazy[x])ans+=lazy[x];
	}
	return sum[l+M]+ans;
}
LL query(int l,int r){//区间查询 (区间和)
	if(l>r)return 0;
	if(l==r)return query_node(l);
	int L=0,R=0,d=1;//L，R分别记录所求区间中有多少个节点处于左右端点所在的节点中，d记录所在层次的节点代表的区间长度 
	LL ans=0;
	for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
		if(lazy[l])ans+=L*lazy[l];//计算lazy[l]影响的值 
		if(lazy[r])ans+=R*lazy[r];//计算lazy[r]影响的值 
		if(~l&1)ans+=sum[l^1],L+=d;//左端点所在的点是左子节点，则对应的右子节点处于区间中，更新L的值 
		if(r&1)ans+=sum[r^1],R+=d;
		d<<=1;
	}
	ans+=lazy[l]*L,ans+=lazy[r]*R,L+=R;
	while(l>>=1){//计算路径上的lazy造成的影响 
		if(lazy[l])ans+=lazy[l]*L;
	}
	return ans;
}
char s1[maxn*2];
int hw[maxn*2];
void manacher(char s[],int n)
{
    int maxright=0,mid;
    for(int i=1;i<n;i++)
    {
        if(i<maxright)
            hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        else
            hw[i]=1;
        for(;s[i+hw[i]]==s[i-hw[i]];++hw[i]);
        if(hw[i]+i>maxright)
        {
            maxright=hw[i]+i;
            mid=i;
        }
    }
}
int main(){
	scanf("%s",s+1);int n=strlen(s+1);
	for(int i=1;s[i];i++){
		int x=s[i]-'a';a[i]=a[i-1];
		if(!la[x])a[i]++;
		la[x]=nex[la[x]]=i;
		s1[(i<<1)-1]=s[i],s1[i<<1]='#';
	}
	for(int i=0;i<26;i++)nex[la[i]]=n+1;
	build(n);n*=2;
	manacher(s1,n);
	LL ans=0;int l,r;
	for(int i=1;i<=n;i++){
		if(s1[i]=='#'){
			l=i/2+1,r=(hw[i]+i)/2;
			ans+=query(l,r);
			r=nex[l-1]-1;
			modify(l,r,-1);
		}
		else{
			l=i/2+1,r=(hw[i]+i)/2;
			ans+=query(l,r);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
