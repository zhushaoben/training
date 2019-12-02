#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
int n,m,a[maxn],root[maxn],size,lazy[maxn*70],l[maxn*70],r[maxn*70],sum[maxn*70];//�Ƕ�̬������ڵ�Ҫ����n*logn*4 
int build(int L,int R){//���� 
	int k=size++;
	if(L==R){sum[k]=a[L-1];return k;}
	int mid=(L+R)>>1;
	l[k]=build(L,mid),r[k]=build(mid+1,R);
	sum[k]=sum[l[k]]+sum[r[k]];
	return k;
}
int modify(int history,int L,int R,int w,int l1,int r1){//�����޸�,history���ϸ��汾�ĵ�ǰ�ڵ�ı�ţ�L,RΪ��ǰ�ڵ㷶Χ��l1,l2ΪҪ�޸ĵķ�Χ 
	int k=size++;
	lazy[k]=lazy[history],sum[k]=sum[history]+1ll*(r1-l1+1)*w,l[k]=l[history],r[k]=r[history];//��¡�ڵ� 
	if(l1<=L&&r1>=R){//�������䶼Ҫ���޸ģ������Ƿ��� 
		lazy[k]+=w;return k;
	}
	int mid=(L+R)>>1;
	if(l1<=mid)l[k]=modify(l[history],L,mid,w,l1,min(mid,r1));
	if(r1>mid)r[k]=modify(r[history],mid+1,R,w,max(mid+1,l1),r1);
	return k;
}
int change(int history,int L,int R,int w,int x){//�����޸� 
	int k=size++;
	lazy[k]=lazy[history],sum[k]=sum[history]+w,l[k]=l[history],r[k]=r[history];//��¡�ڵ�
	if(L==R)return k;//�����Ҷ�ӽڵ��ֱ�ӷ��� 
	int mid=(L+R)>>1;
	if(x<=mid)l[k]=change(l[history],L,mid,w,x);
	else r[k]=change(r[history],mid+1,R,w,x);
	return k;
}
int query(int x,int L,int R,int l1,int r1){//ѯ�� 
	if(l1<=L&&r1>=R)return sum[x];
	int mid=(L+R)>>1;
	int ans=lazy[x]*(r1-l1+1);//��ǲ����·ţ���Ϊ�ӽڵ�Ҳ�ǹ��õ�,ֻ��ͳ�Ʊ����ɵ�Ӱ�� 
	if(l1<=mid)ans+=query(l[x],L,mid,l1,min(mid,r1));
	if(r1>mid)ans+=query(r[x],mid+1,R,max(mid+1,l1),r1);
	return ans;
}
int main(){
	return 0;
} 
