#include<cstdio>
#include<cstring>
using namespace std;
#define size(x) (x?x->size:0)
#define is_r(x) (x->fa?x->fa->son[1]==x:0)
struct Splay{
	int key,size,num;
	Splay *son[2],*fa;
	Splay(){
		memset(this,0,sizeof(Splay));
	}
	Splay(int x){
		key=x,num=size=1,fa=son[0]=son[1]=0;
	}
}*root;
void rotate(Splay *&x,int d){
	Splay *p=x->son[!d];
	x->son[!d]=p->son[d];
	if(p->son[d])p->son[d]->fa=x;
	p->son[d]=x,p->fa=x->fa,x->fa=p;
	p->size=x->size,x->size=size(x->son[0])+size(x->son[1])+x->num;
	x=p;
}
void up(Splay *&x){//将x旋转到它的爷爷节点 
	bool d=is_r(x);
	Splay *&a=x->fa->fa->fa?x->fa->fa->fa->son[is_r(x->fa->fa)]:root;//a为指向爷爷节点的指针 
	if(is_r(x->fa)!=d){
		rotate(a->son[!d],!d),rotate(a,d);
	}
	else rotate(a,!d),rotate(a,!d);
}
void splay(Splay *x,Splay *&root){//将x节点旋转到root节点 
	while(x->fa!=root&&x!=root)up(x);
	if(x->fa==root)rotate(root,!is_r(x));
}
void insert(Splay *&x,Splay *fa,int key){
	if(!x){
		x=new Splay(key),x->fa=fa,splay(x,root);
		return;
	}
	x->size++;
	if(x->key==key){x->num++,splay(x,root);return;}
	int d=x->key<key;
	insert(x->son[d],x,key);
}
Splay* Max(Splay *x){
	while(x->son[1])x=x->son[1];
	return x;
}
Splay* Min(Splay *x){
	while(x->son[0])x=x->son[0];
	return x;
}
Splay* Find(Splay *x,int key){
	if(!x)return 0;
	if(x->key==key)return x;
	return Find(x->son[key>x->key],key);
}
void Merge(Splay *&x,Splay *&y){
	Splay *a=Max(x);
	splay(a,x);
	a->son[1]=y;
}
void del(Splay *&x,int key){
	Splay *a=Find(x,key);
	splay(a,x);
	if(a->num>1){a->num--;return;}
	x=a->son[0];
	Merge(a->son[0],a->son[1]),delete a;
}
int query_id(Splay *x,int key){//求数列中比key小的有几个 
	if(!x)return 0;
	if(x->key>key)return query_id(x->son[0],key);
	if(x->key==key)return size(x->son[0]);
	return query_id(x->son[1],key)+size(x->son[0])+x->num;
}
int query_k(Splay *x,int k){//求排第k的数 
	if(!x)return 0;
	if(size(x->son[0])>=k)return query_k(x->son[0],k);
	if(size(x->son[0])+x->num>=k)return x->key;
	return query_k(x->son[1],k-size(x->son[0])-x->num);
}
int ans;
void pre(Splay *x,int num){//求num的前驱(即小于num的最大的数)，并存在ans里 
	if(!x)return;
	if(x->key<num)ans=x->key,pre(x->son[1],num);
	else pre(x->son[0],num);
}
void suc(Splay *x,int num){//求后继 
	if(!x)return;
	if(x->key>num)ans=x->key,suc(x->son[0],num);
	else suc(x->son[1],num);
}
void mid_traversal(Splay *x){//中序遍历
	if(x->son[0])mid_traversal(x->son[0]);
	printf("%d ",x->key);
	if(x->son[1])mid_traversal(x->son[1]);
}
int main(){
	return 0;
}
