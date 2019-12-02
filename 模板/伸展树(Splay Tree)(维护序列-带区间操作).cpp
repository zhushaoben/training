#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdarg.h>
using namespace std;
#define inf 0x3fffffff
#define is_r(x) (x->fa?x->fa->son[1]==x:0)
struct Splay{
	int key,size,maxl,maxr,maxt,sum;//maxl为左区间最大值,maxr为右区间最大值, maxt为区间最大值 
	bool rev,same;//翻转和赋值标记 
	Splay *son[2],*fa;
	Splay(){
		memset(this,0,sizeof(Splay));
	}
	Splay(int x,Splay *f){
		sum=maxl=maxr=maxt=key=x,size=1,rev=same=0,fa=f;
	}
}*root,*null=new Splay;
int a[500005];
//下面的宏在<stdarg.h>提供的有 
//typedef char *  va_list;//指针 
//#define _ADDRESSOF(n)   ( &reinterpret_cast<const char &>(n) ) //取n的地址并转为char* 
//#define _INTSIZEOF(n)  ((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1) ) //将sizeof(n)向上取至sizeof(int)的整数倍,在我电脑上必须*2才行 
//#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) ) //求第一位的地址存在ap中 
//#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) ) //取出ap的值，并将ap指向下一个位置
//#define va_end(ap)      ( ap = (va_list)0 )  //置空ap 
int Max(int n,...){//求n个数的max 
    va_list arg_ptr;
    va_start(arg_ptr, n);
	int ans = -inf;
    for(int i=0; i < n; ++i){
        int temp = va_arg(arg_ptr,int);
        ans=max(ans,temp);
    }
    va_end(arg_ptr);
    return ans;
}
void push_down(Splay *x){//下放标记 
	if(x==null)return;
	if(x->rev){//区间翻转 
		x->rev=0,x->son[0]->rev^=1,x->son[1]->rev^=1;
		swap(x->son[0],x->son[1]),swap(x->maxl,x->maxr);
	}
	if(x->same){//区间赋值 
		x->same=0,x->son[0]->key=x->son[1]->key=x->key;
		x->son[0]->same=x->son[1]->same=1;
		x->sum=x->key*x->size;
		x->maxl=x->maxr=x->maxt=(x->key>0?x->sum:x->key);
	}
}
void update(Splay *x){//更新节点 
	if(x==null)return;
	push_down(x),push_down(x->son[0]),push_down(x->son[1]);//要用到子节点的maxl,maxr所以要下放子节点标记 
	x->size=x->son[0]->size+x->son[1]->size+1,//更新节点存储的值 
	x->sum=x->son[0]->sum+x->son[1]->sum+x->key,
	x->maxl=max(x->son[0]->maxl,x->son[0]->sum+x->key+max(0,x->son[1]->maxl)),
	x->maxr=max(x->son[1]->maxr,x->son[1]->sum+x->key+max(0,x->son[0]->maxr));
	x->maxt=Max(3,x->son[0]->maxt,x->son[1]->maxt,max(0,x->son[0]->maxr)+max(0,x->son[1]->maxl)+x->key);
}
void mid_traversal(Splay *x){//中序遍历
	push_down(x);
	if(x->son[0]!=null)mid_traversal(x->son[0]);
	printf("%d %d\n",x->key,x->size);
	if(x->son[1]!=null)mid_traversal(x->son[1]);
}
void rotate(Splay *&x,int d){//旋转 
	Splay *p=x->son[!d];
	push_down(x),push_down(p);//先下放标记 
	x->son[!d]=p->son[d];//更新指向关系 
	if(p->son[d]!=null)p->son[d]->fa=x;
	p->son[d]=x,p->fa=x->fa,x->fa=p;
	update(x),update(p);//更新节点 
	x=p;//x指向p指向的位置
}
void up(Splay *x){//将x旋转到它的爷爷节点 
	bool d=is_r(x);
	Splay *&a=x->fa->fa->fa?x->fa->fa->fa->son[is_r(x->fa->fa)]:root;//a为指向爷爷节点的指针 
	if(is_r(x->fa)!=d){//x和父亲位于它们父亲的异侧 
		rotate(a->son[!d],!d),rotate(a,d);
	}
	else rotate(a,!d),rotate(a,!d);//x和父亲位于它们父亲的同侧 
}
void splay(Splay *x,Splay *&root){//将x节点旋转到root节点 
	if(x==null)return;
	while(x->fa!=root&&x!=root){
		up(x);
	}
	if(x->fa==root)rotate(root,!is_r(x));
}
void build(Splay *&x,Splay *fa,int l,int r){//建立一棵[l,r]的子树,x指向子树的根,根的父亲为fa 
	if(l>r)return;
	int mid=(l+r)>>1;
	x=new Splay(a[mid],fa),x->son[0]=x->son[1]=null;//根节点存区间中点 
	build(x->son[0],x,l,mid-1);
	build(x->son[1],x,mid+1,r);
	update(x);
}
Splay *Find(Splay *x,int k){//返回x子树中的第k个数 
	if(x==null)return 0;
	update(x);
	if(x->son[0]->size>=k)return Find(x->son[0],k);
	if(x->son[0]->size+1==k)return x;
	return Find(x->son[1],k-x->son[0]->size-1);
}
void insert(int l,int s){//在l后面插入长为s的区间 
	for(int i=0;i<s;i++){
		scanf("%d",a+i);
	}
	splay(Find(root,l+1),root),splay(Find(root,l+2),root->son[1]);//将l旋转到root,将l+1旋转到root的右儿子,这时l+1没有左儿子 
	build(root->son[1]->son[0],root->son[1],0,s-1),update(root),update(root->son[1]);//建树，更新 
}
void remove(Splay *x){//删除x子树 
	if(x==null)return;
	remove(x->son[0]),remove(x->son[1]),delete x;
}
void del(int l,int r){//删除[l,r] 
	splay(Find(root,l),root);//将l-1旋转到root 
	splay(Find(root,r+2),root->son[1]);//将r+1旋转到root的右儿子
	remove(root->son[1]->son[0]),root->son[1]->son[0]=null,update(root->son[1]),update(root);//r+1的左儿子即为区间[l,r]
}
void modify(int l,int r,int s){//将[l,r]都赋值为s 
	splay(Find(root,l),root);//将l-1旋转到root 
	splay(Find(root,r+2),root->son[1]);//将r+1旋转到root的右儿子 
	Splay *x=root->son[1]->son[0];//r+1的左儿子即为区间[l,r],打标记更新 
	x->same=1,x->key=s,update(root->son[1]),update(root);splay(x,root);
}
void rev(int l,int r){//将[l,r]翻转 
	splay(Find(root,l),root);//将l-1旋转到root 
	splay(Find(root,r+2),root->son[1]);//将r+1旋转到root的右儿子
	root->son[1]->son[0]->rev=1;//r+1的左儿子即为区间[l,r],打标记更新
	update(root->son[1]),update(root);
}
int get_sum(int l,int r){//求[l,r]的和 
	splay(Find(root,l),root);
	splay(Find(root,r+2),root->son[1]);
	return root->son[1]->son[0]->sum; 
}
int max_sum(){//求最大的区间值 
	update(root); 
	return root->maxt;
}
//注：建树时在区间两端多开两个空节点，否则会越界 
int main(){
	return 0;
}
