#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath>
using namespace std;
#define getheight(x) (x?x->height:0)
#define size(x) (x?x->size:0)
struct AVL{
	int key,height,num,size;//size只有在求排名和第k大时才需要,num在有重复加入时才需要,其它AVL中可以不用
	AVL *son[2];
	AVL(){
		memset(this,0,sizeof(AVL));
	}
	AVL(int x){
		key=x,size=height=num=1,son[0]=son[1]=0;
	}
}*root;
void rotate(AVL *&x,int d){
	AVL *p=x->son[d^1];
	x->son[d^1]=p->son[d],p->son[d]=x;//更新指向关系 
	x->height=max(getheight(x->son[0]),getheight(x->son[1]))+1,//更新高度和size 
	p->height=max(getheight(p->son[0]),getheight(p->son[1]))+1;
	p->size=x->size,x->size=x->num+size(x->son[0])+size(x->son[1]);
}
void maintain(AVL *&x){//平衡操作 
	if(abs(getheight(x->son[0])-getheight(x->son[1]))<2)return;
	int d=getheight(x->son[0])<getheight(x->son[1]);
	if(getheight(x->son[d]->son[d])>getheight(x->son[d]->son[d^1]))rotate(x,d^1);
	else rotate(x->son[d],d),rotate(x,d^1);
} 
void insert(AVL *&x,int key){//插入key 
	if(!x){
		x=new AVL(key);return;
	}
	x->size++;
	if(key==x->key){x->num++;return;}
	insert(x->son[key>x->key],key);
	maintain(x);
}
void del(AVL *&x,int key){//删除key 
	if(!x)return;
	if(x->key!=key){
		del(x->son[x->key<key],key);
		x->size=size(x->son[0])+size(x->son[1])+x->num,maintain(x);
		return;
	} 
	x->size--;
	if(x->num>1){x->num--;return;}
	AVL *p=x;
	if(x->son[0]==NULL)x=x->son[1],delete p;
	else if(x->son[1]==NULL)x=x->son[0],delete p;
	else{//用后继替换当前节点，删除后继 
		p=x->son[1];
		while(p->son[0]){
			p=p->son[0];
		}
		x->num=p->num,x->key=p->key,p->num=1,del(x->son[1],p->key);
	}
}
int query_id(AVL *x,int key){//求数列中比key小的有几个 
	if(!x)return 0;
	if(x->key>key)return query_id(x->son[0],key);
	if(x->key==key)return size(x->son[0]);
	return query_id(x->son[1],key)+size(x->son[0])+x->num;
}
int query_k(AVL *x,int k){//求排第k的数 
	if(!x)return 0;
	if(size(x->son[0])>=k)return query_k(x->son[0],k);
	if(size(x->son[0])+x->num>=k)return x->key;
	return query_k(x->son[1],k-size(x->son[0])-x->num);
}
int ans;
void pre(AVL *x,int num){//求num的前驱(即小于num的最大的数)，并存在ans里 
	if(!x)return;
	if(x->key<num)ans=x->key,pre(x->son[1],num);
	else pre(x->son[0],num);
}
void suc(AVL *x,int num){//求后继 
	if(!x)return;
	if(x->key>num)ans=x->key,suc(x->son[0],num);
	else suc(x->son[1],num);
}
void mid_traversal(AVL *x){//中序遍历
	if(x->son[0])mid_traversal(x->son[0]);
	printf("%d ",x->key);
	if(x->son[1])mid_traversal(x->son[1]);
}
int main(){
	return 0;
} 
