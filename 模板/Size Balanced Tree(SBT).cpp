#include<cstdio>
#include<cstring>
using namespace std;
#define size(x) (x?x->size:0)
struct SBT{
	int key,size,num;
	SBT *son[2];
	SBT(){
		memset(this,0,sizeof(SBT));
	}
	SBT(int x){
		num=size=1,key=x,son[0]=son[1]=0;
	}
}*root;
void rotate(SBT *&x,int d){//旋转操作，d=0表示左旋，d=1表示右旋
	SBT *y=x->son[d^1];//y指向要旋转到父节点的子节点 
	x->son[d^1]=y->son[d],y->son[d]=x;//更新指向关系 
	y->size=x->size;//更新size值
	x->size=size(x->son[0])+size(x->son[1])+x->num;
	x=y;//别忘了将进入子树的指针指到y上 
}
void maintain(SBT *&x,int d){//平衡操作,检查(x->son[d]的子树是否比x->son[d^1]大)
	if(x->son[d]==NULL)return;
	if(size(x->son[d^1])<size(x->son[d]->son[d^1]))rotate(x->son[d],d),rotate(x,d^1);
	else if(size(x->son[d^1])<size(x->son[d]->son[d]))rotate(x,d^1);
	else return;
	maintain(x->son[0],0),maintain(x->son[1],1),maintain(x,0),maintain(x,1);//平衡子树后再平衡一次x 
}
void insert(SBT *&x,int key){
	if(!x){x=new SBT(key);return;}
	x->size++;
	if(x->key==key){x->num++;return;}
	int d=key>x->key;
	insert(x->son[d],key);
	maintain(x,d);//插入后平衡一遍 
}
void del(SBT *&x,int key){
	if(x->key!=key){
		del(x->son[key>x->key],key);
		x->size=size(x->son[0])+size(x->son[1])+x->num; 
		return;
	}
	x->size--;
	if(x->num>1){x->num--;return;}//num>1直接num-1即可 
	SBT *p=x;
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
int query_id(SBT *x,int key){//求数列中比key小的有几个 
	if(!x)return 0;
	if(x->key>key)return query_id(x->son[0],key);
	if(x->key==key)return size(x->son[0]);
	return query_id(x->son[1],key)+size(x->son[0])+x->num;
}
int query_k(SBT *x,int k){//求排第k的数 
	if(!x)return 0;
	if(size(x->son[0])>=k)return query_k(x->son[0],k);
	if(size(x->son[0])+x->num>=k)return x->key;
	return query_k(x->son[1],k-size(x->son[0])-x->num);
}
int ans;
void pre(SBT *x,int num){//求num的前驱(即小于num的最大的数)，并存在ans里 
	if(!x)return;
	if(x->key<num)ans=x->key,pre(x->son[1],num);
	else pre(x->son[0],num);
}
void suc(SBT *x,int num){//求后继 
	if(!x)return;
	if(x->key>num)ans=x->key,suc(x->son[0],num);
	else suc(x->son[1],num);
}
void mid_traversal(SBT *x){//中序遍历
	if(x->son[0])mid_traversal(x->son[0]);
	printf("%d ",x->key);
	if(x->son[1])mid_traversal(x->son[1]);
}
bool f=0;
void check(SBT *x){
	if(!x)return;
	check(x->son[0]);
	check(x->son[1]);
	if(x->size!=size(x->son[0])+size(x->son[1])+1)printf("woring");
}
int main(){
	return 0;
}
