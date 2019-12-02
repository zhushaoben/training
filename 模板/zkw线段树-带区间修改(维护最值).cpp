#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1<<17
#define inf 0x3fffffff
int mi[maxn],M,s,a[maxn];
void build(int n){//���� 
	M=1;
	while((M<<=1)<n);
	M--;
	for(int i=0;i<n;i++){
		mi[i+M]=a[i];
	}
	for(int i=M;i;i--){
		mi[i]=min(mi[i<<1],mi[i<<1|1]);
		mi[i<<1]-=mi[i],mi[i<<1|1]-=mi[i];//�ڵ�洢�븸�ڵ�Ĳ�ֵ 
	}
}
void change(int x,int w){//�����޸� 
	x+=M;mi[x]+=w;
	int tmp;
	while(x>>=1){//�������ȵ�ֵ 
		tmp=min(mi[x<<1],mi[x<<1|1]);
		mi[x]+=tmp,mi[x<<1]-=tmp,mi[x<<1|1]-=tmp;
	}
}
void modify(int l,int r,int w){//�����޸�
	int tmp;
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
		if(~l&1)mi[l^1]+=w;//���Ϊ���Ϊ���ӽڵ㣬�����ӽڵ�һ��������,����ֵ 
		if(r&1)mi[r^1]+=w;//���Ϊ�Ҷ�Ϊ���ӽڵ�ͬ�� 
		tmp=min(mi[l],mi[l^1]),mi[l]-=tmp,mi[l^1]-=tmp,mi[l>>1]+=tmp;//�������Ҷ˸��ڵ��ֵ 
		tmp=min(mi[r],mi[r^1]),mi[r]-=tmp,mi[r^1]-=tmp,mi[r>>1]+=tmp; 
	}
	while(l>>=1){//���µ�����·����ֵ 
		tmp=min(mi[l<<1],mi[l<<1|1]),mi[l<<1]-=tmp,mi[l<<1|1]-=tmp,mi[l]+=tmp;
	}
}
int query_node(int x){//�����ѯ 
	x+=M;
	int ans=mi[x];
	while(x>>=1)ans+=mi[x];//��Ϊ���Ϊ�븸�ڵ�Ĳ���Դ�Ҫ��������·���ϵĵ��ֵ 
	return ans;
}
int query(int l,int r){//�����ѯ 
	if(l==r)return query_node(l);//���е����ѯ���������ѭ�� 
	int ans,L=0,R=0;
	for(l+=M,r+=M;l^r^1;l>>=1,r>>=1){
		L+=mi[l],R+=mi[r];//L,R��ʾ���Ҷ˵����ڽڵ��ʾ���������������佻������Сֵ 
		if(~l&1)L=min(L,mi[l^1]);//���Ϊ���Ϊ���ӽڵ㣬�����ӽڵ�һ��������,����ֵ
		if(r&1)R=min(R,mi[r^1]);//���Ϊ�Ҷ�Ϊ���ӽڵ�ͬ��
	}
	L+=mi[l],R+=mi[r],ans=min(L,R);//��Ҫ����·�������еĵ��ֵ
	while(l>>=1){
		ans+=mi[l];
	}
	return ans;
}
int main(){
	int n,m,l,r,w,x;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	build(n);
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		if(x==1){
			scanf("%d%d%d",&l,&r,&w);
			modify(l,r,w);
		}
		else{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r));
		}
	}
	return 0;
} 
