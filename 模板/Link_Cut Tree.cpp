#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;
#define maxn 50005
#define is_r(x) (x->fa?x->fa->son[1]==x:0)
struct Splay{
	Splay *fa,*son[2];
	bool is_root,rev;
	Splay(){
		memset(this,0,sizeof(Splay));is_root=1;
	}
}*null,*root[maxn];
void reverse(Splay *x){//翻转x子树 
	if(!x)return;
	swap(x->son[1],x->son[0]);
	x->rev^=1;
}
void pushdown(Splay *x){//下放标记 
	if(x->rev){
		x->rev=0;
		reverse(x->son[0]);
		reverse(x->son[1]);
	}
}
void push(Splay *x){//将x路径上的标记全部下放，为x旋到根做准备 
	if(!x->is_root)push(x->fa);
	pushdown(x);
}
void update(Splay *x){//更新维护的信息，因为模板中没有维护什么，所以为空 
}
/*
下面三个函数是普通Splay的操作
只是下放标记的方法不同 
*/ 
void rotate(Splay *&x,int d){
	Splay *p=x->son[!d];
	x->son[!d]=p->son[d],p->son[d]=x;
	p->fa=x->fa,x->fa=p;
	if(x->son[!d])x->son[!d]->fa=x;
	update(x),update(p);
	if(x->is_root)p->is_root=1,x->is_root=0;
	x=p;
}
void up(Splay *x){
	Splay *&p=!x->fa->fa->is_root?x->fa->fa->fa->son[is_r(x->fa->fa)]:null=x->fa->fa;
	int d=is_r(x);
	if(is_r(x->fa)==d)rotate(p,!d),rotate(p,!d);
	else rotate(p->son[!d],!d),rotate(p,d);
}
void splay(Splay *x){
	push(x);
	while(!x->is_root&&!x->fa->is_root)up(x);
	if(!x->is_root)rotate(null=x->fa,!is_r(x));
}
void access(Splay *x){
	Splay *y=0;
	while(x){//如果x和LCT的根不在一条链上，每次将它所在的链与上面的链合并 
		splay(x);
		if(x->son[1])x->son[1]->is_root=1;
		if(x->son[1]=y)y->is_root=0;
		update(x);
		x=(y=x)->fa;
	}
}
void mroot(Splay *x){//将x变为所在LCT的根 
	access(x);
	splay(x);
	reverse(x);
}
void link(Splay *u,Splay *v){//合并u和v所在的LCT 
	mroot(u);
	u->fa=v;
}
void cut(Splay *u,Splay *v){
	mroot(u);//将u变成根 
	access(v);splay(v);//v和u弄到同一条链上，并且分别为两端 
	pushdown(v);
	if(v->son[0])v->son[0]->fa=v->fa,v->son[0]->is_root=1;//将v子树和链上的点分开 
	v->son[0]=v->fa=0;
	update(v);
}
int main(){
	return 0;
}
