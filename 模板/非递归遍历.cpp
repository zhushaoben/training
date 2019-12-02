#include<cstdio>
#include<stack>
using namespace std;
struct node{
	int id;
	node *l=NULL,*r=NULL;
}a[100];
void PreOrderTraverse(node i){//递归先序遍历 
	printf("%d ",i.id);//输出根 
	if(i.l)PreOrderTraverse(*i.l);//遍历左子树 
	if(i.r)PreOrderTraverse(*i.r);//遍历右子树 
}
void InOrderTraverse(node i){//递归中序遍历 
	if(i.l)InOrderTraverse(*i.l);//遍历左子树 
	printf("%d ",i.id);//输出根 
	if(i.r)InOrderTraverse(*i.r);//遍历右子树 
}
void PostOrderTraverse(node i){//递归后序遍历 
	if(i.l)PostOrderTraverse(*i.l);//遍历左子树 
	if(i.r)PostOrderTraverse(*i.r);//遍历右子树 
	printf("%d ",i.id);//输出根 
}
void PreOrderTraverse(node* i){//非递归先序遍历 
	stack<node>s;
	node x;
	while(i||!s.empty()){
		while(i){
			s.push(*i);
			printf("%d ",i->id);//输出根 
			i=i->l;//遍历左子树 
		}
		x=s.top();s.pop();
		i=x.r;//遍历右子树
		
	}
}
void InOrderTraverse(node* i){//非递归中序遍历 
	stack<node>s;
	node x;
	while(i||!s.empty()){
		while(i){
			s.push(*i);
			i=i->l;//遍历左子树 
		}
		x=s.top();s.pop();
		printf("%d ",x.id);//输出根 
		i=x.r;//遍历右子树
		
	}
}
void PostOrderTraverse(node* i){//非递归后序遍历 
	stack<pair<node,bool> >s;
	pair<node,bool> x;
	while(i||!s.empty()){
		while(i){
			s.push(make_pair(*i,0));
			i=i->l;//遍历左子树 
		}
		x=s.top();s.pop();
		if(x.second)printf("%d ",x.first.id);//如果右子树遍历过则输出根
		else s.push(make_pair(x.first,1)),i=x.first.r;//如果右子树没遍历则遍历右子树
		
	}
}
int main(){
	for(int i=1;i<99;i++){
		a[i].id=i;
		if(i%2)a[i>>1].r=&a[i];
		else a[i>>1].l=&a[i];
	}
	InOrderTraverse(a[1]);printf("\n");
	InOrderTraverse(&a[1]);printf("\n");
	PreOrderTraverse(a[1]);printf("\n");
	PreOrderTraverse(&a[1]);printf("\n");
	PostOrderTraverse(a[1]);printf("\n");
	PostOrderTraverse(&a[1]);printf("\n");
	return 0;
}
