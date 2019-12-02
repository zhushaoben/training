#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
#define LL long long
LL sum[maxn<<2],a[maxn],M,lazy[maxn<<2],k;
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
int main(){
	int n,q,x,l,r;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	build(n);
	for(int i=0;i<q;i++){
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d%lld",&l,&r,&k);
			modify(l,r,k);
		}
		else{
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(l,r));
		}
	}
	return 0;
} 
