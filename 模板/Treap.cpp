#include<cstdio>
#include<cstring>
using namespace std;
#define size(x) (x!=NULL?x->size:0)
inline int random(){//生成随机数 
	static int seed=66;
	return seed=seed*48271LL%2147483647;//百度上说会把[0,2147483646]都生成一遍不会重复 
}
struct Treap{
	int key,prio,size,num;//key满足二叉搜索树,prio满足二叉堆,num是key值的数目,size是子树中num之和 
	Treap* son[2];
	Treap(){
		memset(this,0,sizeof(Treap));
	}
	Treap(int k){
		key=k,prio=random(),size=num=1,son[0]=son[1]=0;
	}
}*root;
void rotate(Treap *&x,int d){//旋转,d为旋转方向,0为左旋,1为右旋
	Treap *y=x->son[d^1];//y指向要旋转到父节点的子节点 
	x->son[d^1]=y->son[d],y->son[d]=x;//更新指向关系 
	y->size=x->size;//更新size值 
	x->size=size(x->son[0])+size(x->son[1])+x->num;
	x=y;//别忘了将进入子树的指针指到y上 
}
void insert(Treap *&x,int key){//插入节点 
	if(x==NULL){//节点为空则直接创建一个节点 
		x=new Treap(key);return;
	}
	x->size++;
	if(key==x->key){x->num++;return;}//权值已经存在，则num++； 
	int d=key>x->key;
	insert(x->son[d],key);//加入到子节点 
	if(x->prio < x->son[d]->prio)rotate(x,d^1);//别忘了旋转来满足堆的性质 
}
void del(Treap *&x,int key){//删除节点 
	if(x->key!=key){
		del(x->son[key>x->key],key);//进入子节点找权值为key的节点 
		x->size--;//总数减一 
		return;
	}
	//找到节点后 
	if(x->num>1){//如果插入不止一次,就num--即可 
		x->num--,x->size--;return;
	}
	Treap* p=x;
	if(x->son[0]==NULL)x=x->son[1],delete p;//左子节点为空,用右子节点(可能也为空)替代自己
	else if(x->son[1]==NULL)x=x->son[0],delete p;//右子节点为空,用左子节点替代自己 
	else{
		int d=x->son[0]->prio > x->son[1]->prio;
		rotate(x,d);//将prio值较大的旋转到上面 
		del(x,key);//进入x在的子树，再进行删除 
	}
}
int query_id(Treap *x,int key){//求数列中比key小的有几个 
	if(x==NULL)return 0;
	if(x->key>key)return query_id(x->son[0],key);//当前节点的值大于key，求在左子树中的排名即可 
	if(x->key==key)return size(x->son[0]);//当前节点个数等于key,返回左子树大小 
	else return size(x->son[0])+x->num+query_id(x->son[1],key);//在右子树找,值要加上左子树大小和当前节点的大小 
}
int query_key(Treap *x,int num){//求排第num的数 
	if(x==NULL)return 0;
	if(size(x->son[0])>=num)return query_key(x->son[0],num);//左子树大小大于等于num，在左子树中找排num的数即可 
	if(size(x->son[0])+x->num>=num)return x->key;//排第num的数是当前节点 
	return query_key(x->son[1],num-size(x->son[0])-x->num);//在右子树找排num-(左子树大小+当前节点大小)的数即可 
}
int ans;
void pre(Treap *x,int num){//求num的前驱(即小于num的最大的数) 
	if(x==NULL)return;
	if(x->key<num)ans=x->key,pre(x->son[1],num);
	else pre(x->son[0],num);
}
void suc(Treap *x,int num){//求后继 
	if(x==NULL)return;
	if(x->key>num)ans=x->key,suc(x->son[0],num);
	else suc(x->son[1],num);
}
void mid_traversal(Treap* x){//中序遍历，即按照排序好的顺序输出 
	if(x->son[0])mid_traversal(x->son[0]);
	printf("%d ",x->key);
	if(x->son[1])mid_traversal(x->son[1]);
}
int main(){
	return 0;
}
