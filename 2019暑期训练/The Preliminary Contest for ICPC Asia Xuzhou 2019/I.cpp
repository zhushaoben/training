#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define LL long long
int a[maxn],p[maxn];
vector<int>v[maxn];
LL sum[maxn<<2],M,lazy[maxn<<2],k;
void build(int n){//���� 
	M=1;while((M<<=1)<n);
	M--;
	for(int i=1;i<=n;i++){
		sum[i+M]=a[i];
	} 
	for(int i=M;i>0;i--){
		sum[i]=sum[i<<1]+sum[i<<1|1]; 
	}
}
void change(int x,int y){//�����޸� 
	x+=M;
	sum[x]+=y;
	while(x>>=1){
		sum[x]+=y;
	}
}
void modify(int l,int r,int w){//�����޸�
	if(l>r)return;
	if(l==r){change(l,w);return;}
	int d=1;
	sum[l+M]+=w,sum[r+M]+=w;//ע:����Ĳ���������¶˵��ֵ��������ǰ���˵���� 
	for(l+=M,r+=M;l^r^1;l>>=1,r>>=1){
		if(~l&1)sum[l^1]+=w*d,lazy[l^1]+=w;//�ڶ�Ӧ�����ӽڵ�����ǣ�����sum��ֵ 
		if(r&1)sum[r^1]+=w*d,lazy[r^1]+=w;//�ڶ�Ӧ�����ӽڵ�����ǣ�����sum��ֵ 
		d<<=1;
		sum[l>>1]=sum[l]+sum[l^1]+lazy[l>>1]*d;//�����������ڵ��ֵ,����d��ʾ���ڵ��ʾ����ĳ��� 
		sum[r>>1]=sum[r]+sum[r^1]+lazy[r>>1]*d;
	}
	while(l>>=1)d<<=1,sum[l]=sum[l<<1]+sum[l<<1|1]+lazy[l]*d;//����·���Ͻڵ��sumֵ 
}
int query_node(int l){//�����ѯ
	int x=l+M,ans=0;
	while(x>>=1){
		if(lazy[x])ans+=lazy[x];
	}
	return sum[l+M]+ans;
}
LL query(int l,int r){//�����ѯ (�����)
	if(l>r)return 0;
	if(l==r)return query_node(l);
	int L=0,R=0,d=1;//L��R�ֱ��¼�����������ж��ٸ��ڵ㴦�����Ҷ˵����ڵĽڵ��У�d��¼���ڲ�εĽڵ��������䳤�� 
	LL ans=0;
	for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
		if(lazy[l])ans+=L*lazy[l];//����lazy[l]Ӱ���ֵ 
		if(lazy[r])ans+=R*lazy[r];//����lazy[r]Ӱ���ֵ 
		if(~l&1)ans+=sum[l^1],L+=d;//��˵����ڵĵ������ӽڵ㣬���Ӧ�����ӽڵ㴦�������У�����L��ֵ 
		if(r&1)ans+=sum[r^1],R+=d;
		d<<=1;
	}
	ans+=lazy[l]*L,ans+=lazy[r]*R,L+=R;
	while(l>>=1){//����·���ϵ�lazy��ɵ�Ӱ�� 
		if(lazy[l])ans+=lazy[l]*L;
	}
	return ans;
}
struct Node{
	int l,r,k;LL ans;
	bool operator < (const Node &b)const{
		return r<b.r;
	}
}w[maxn];
bool cmp(Node a,Node b){
	return a.k<b.k;
}
int main(){
	int n,m;scanf("%d%d",&n,&m);build(n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),p[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i<<1;j<=n;j+=i){
			int l=p[i],r=p[j];if(l>r)swap(l,r);
			v[r].push_back(l);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&w[i].l,&w[i].r);w[i].k=i;
	}sort(w+1,w+m+1);
	int now=1;
	for(int i=1;i<=n;i++){
		for(auto j:v[i]){
			modify(1,j,1);
		}
		while(w[now].r==i){
			w[now].ans=query(w[now].l,w[now].l),now++;
		}
	}
	sort(w+1,w+m+1,cmp);
	for(int i=1;i<=m;i++)printf("%lld\n",w[i].ans);
	return 0;
}
