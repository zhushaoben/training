#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100005
struct Node{
	Node *l,*r;
	bool l1,r1;//��¼���������ǲ��ǵ�ǰ�ڵ㴴����,�����delete�Ͳ���Ҫ 
	int lazy,sum;
	Node(){
		memset(this,0,sizeof(Node));
	}
}root[maxn];
int n,m,a[maxn];
void build(Node &x,int L,int R){//���� 
	if(L==R){x.sum=a[L-1];return;}
	int mid=(L+R)>>1;
	build(*(x.l1=1,x.l=new Node),L,mid),build(*(x.r1=1,x.r=new Node),mid+1,R);
	x.sum=x.l->sum+x.r->sum;
}
void modify(Node &history,Node &x,int L,int R,int w,int l1,int r1){//�����޸� 
	x=history,x.sum+=(r1-l1+1)*w,x.r1=x.l1=0;
	if(l1<=L&&r1>=R){
		x.lazy+=w;return;
	}
	int mid=(L+R)>>1;
	if(l1<=mid)modify(*history.l,*(x.l1=1,x.l=new Node),L,mid,w,l1,min(mid,r1));
	if(r1>mid)modify(*history.r,*(x.r1=1,x.r=new Node),mid+1,R,w,max(mid+1,l1),r1);
}
void change(Node &history,Node &x,int L,int R,int w,int l1){//�����޸� 
	x=history,x.sum+=w,x.l1=x.r1=0;//��¡�ڵ�
	if(L==R)return;//�����Ҷ�ӽڵ��ֱ�ӷ��� 
	int mid=(L+R)>>1;
	if(l1<=mid)change(*history.l,*(x.l1=1,x.l=new Node),L,mid,w,l1);
	else change(*history.r,*(x.r1=1,x.r=new Node),mid+1,R,w,l1);
}
int query(Node &x,int L,int R,int l1,int r1){//�����ѯ 
	if(l1<=L&&r1>=R)return x.sum;
	int mid=(L+R)>>1,ans=x.lazy*(r1-l1+1);
	if(l1<=mid)ans+=query(*x.l,L,mid,l1,min(mid,r1));
	if(r1>mid)ans+=query(*x.r,mid+1,R,max(mid+1,l1),r1);
	return ans;
}
void remove_node(Node *x){//�ڵ�ռ��ͷ� 
	if(x->l1)remove_node(x->l);
	if(x->r1)remove_node(x->r);
	delete x;
}
void remove(int n){//�߶����ռ��ͷ� 
	for(int i=0;i<=n;i++){
		if(root[i].l1)remove_node(root[i].l);
		if(root[i].r1)remove_node(root[i].r);
	}
	memset(root,0,sizeof(root));
}
int main(){
	return 0;
} 
