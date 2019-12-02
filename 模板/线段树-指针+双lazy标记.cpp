#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
#define val(x) (x?x->val:0)
struct Node{
	LL val,lazy1,lazy2;//lazy1为区间加标记，lazy2为区间乘标记 
	Node *l,*r;
	Node(){
		memset(this,0,sizeof(Node)),lazy2=1;
	}
}*root;
int n,m,p;
void update(Node *x){
	x->val=val(x->l)+val(x->r);
}
void build(int l,int r,Node *&x){//建树
	x=new Node;
	if(l==r){scanf("%lld",&x->val);return;}
	int mid=(l+r)>>1;
	build(l,mid,x->l),build(mid+1,r,x->r);
	update(x);
}
void pushdown(Node *x,int s1,int s2){//标记下放 
	if(!(x->lazy1||x->lazy2!=1))return;
	x->l->lazy1=(x->lazy2*x->l->lazy1+x->lazy1)%p,x->r->lazy1=(x->lazy2*x->r->lazy1+x->lazy1)%p;
	(x->l->lazy2*=x->lazy2)%=p,(x->r->lazy2*=x->lazy2)%=p;
	(x->l->val*=x->lazy2)%=p,(x->l->val+=x->lazy1*s1)%=p,(x->r->val*=x->lazy2)%=p,(x->r->val+=x->lazy1*s2)%=p;
	x->lazy1=0,x->lazy2=1;
}
void modify1(int L,int R,Node *x,int l,int r,int w){//区间修改 
	if(L>=l&&R<=r){(x->lazy1+=w)%=p,(x->val+=(R-L+1)*w)%=p;return;}
	int mid=(L+R)>>1;
	pushdown(x,mid-L+1,R-mid);
	if(mid>=l)modify1(L,mid,x->l,l,r,w);
	if(mid<r)modify1(mid+1,R,x->r,l,r,w);
	update(x);
}
void modify2(int L,int R,Node *x,int l,int r,int w){//区间修改 
	if(L>=l&&R<=r){(x->lazy2*=w)%=p,(x->lazy1*=w)%=p,(x->val*=w)%=p;return;}
	int mid=(L+R)>>1;
	pushdown(x,mid-L+1,R-mid);
	if(mid>=l)modify2(L,mid,x->l,l,r,w);
	if(mid<r)modify2(mid+1,R,x->r,l,r,w);
	update(x);
}
void change(int L,int R,Node *x,int l,int w){//单点修改 
	if(L==R){x->val+=w;return;}
	int mid=(L+R)>>1;
	if(mid>=l)change(L,mid,x->l,l,w);
	else change(mid+1,R,x->r,l,w);
	x->val+=w;
} 
LL query(int L,int R,Node *x,int l,int r){//区间查询 
	if(L>=l&&R<=r){return x->val;}
	int mid=(L+R)>>1;
	long long ans=0;
	pushdown(x,mid-L+1,R-mid);
	if(mid>=l)ans+=query(L,mid,x->l,l,r);
	if(mid<r)ans+=query(mid+1,R,x->r,l,r);
	return ans%p;
}
int main(){
	return 0;
} 
