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
void reverse(Splay *x){//��תx���� 
	if(!x)return;
	swap(x->son[1],x->son[0]);
	x->rev^=1;
}
void pushdown(Splay *x){//�·ű�� 
	if(x->rev){
		x->rev=0;
		reverse(x->son[0]);
		reverse(x->son[1]);
	}
}
void push(Splay *x){//��x·���ϵı��ȫ���·ţ�Ϊx��������׼�� 
	if(!x->is_root)push(x->fa);
	pushdown(x);
}
void update(Splay *x){//����ά������Ϣ����Ϊģ����û��ά��ʲô������Ϊ�� 
}
/*
����������������ͨSplay�Ĳ���
ֻ���·ű�ǵķ�����ͬ 
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
	while(x){//���x��LCT�ĸ�����һ�����ϣ�ÿ�ν������ڵ�������������ϲ� 
		splay(x);
		if(x->son[1])x->son[1]->is_root=1;
		if(x->son[1]=y)y->is_root=0;
		update(x);
		x=(y=x)->fa;
	}
}
void mroot(Splay *x){//��x��Ϊ����LCT�ĸ� 
	access(x);
	splay(x);
	reverse(x);
}
void link(Splay *u,Splay *v){//�ϲ�u��v���ڵ�LCT 
	mroot(u);
	u->fa=v;
}
void cut(Splay *u,Splay *v){
	mroot(u);//��u��ɸ� 
	access(v);splay(v);//v��uŪ��ͬһ�����ϣ����ҷֱ�Ϊ���� 
	pushdown(v);
	if(v->son[0])v->son[0]->fa=v->fa,v->son[0]->is_root=1;//��v���������ϵĵ�ֿ� 
	v->son[0]=v->fa=0;
	update(v);
}
int main(){
	return 0;
}
