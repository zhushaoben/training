#include<cstdio>
#include<stack>
using namespace std;
struct node{
	int id;
	node *l=NULL,*r=NULL;
}a[100];
void PreOrderTraverse(node i){//�ݹ�������� 
	printf("%d ",i.id);//����� 
	if(i.l)PreOrderTraverse(*i.l);//���������� 
	if(i.r)PreOrderTraverse(*i.r);//���������� 
}
void InOrderTraverse(node i){//�ݹ�������� 
	if(i.l)InOrderTraverse(*i.l);//���������� 
	printf("%d ",i.id);//����� 
	if(i.r)InOrderTraverse(*i.r);//���������� 
}
void PostOrderTraverse(node i){//�ݹ������� 
	if(i.l)PostOrderTraverse(*i.l);//���������� 
	if(i.r)PostOrderTraverse(*i.r);//���������� 
	printf("%d ",i.id);//����� 
}
void PreOrderTraverse(node* i){//�ǵݹ�������� 
	stack<node>s;
	node x;
	while(i||!s.empty()){
		while(i){
			s.push(*i);
			printf("%d ",i->id);//����� 
			i=i->l;//���������� 
		}
		x=s.top();s.pop();
		i=x.r;//����������
		
	}
}
void InOrderTraverse(node* i){//�ǵݹ�������� 
	stack<node>s;
	node x;
	while(i||!s.empty()){
		while(i){
			s.push(*i);
			i=i->l;//���������� 
		}
		x=s.top();s.pop();
		printf("%d ",x.id);//����� 
		i=x.r;//����������
		
	}
}
void PostOrderTraverse(node* i){//�ǵݹ������� 
	stack<pair<node,bool> >s;
	pair<node,bool> x;
	while(i||!s.empty()){
		while(i){
			s.push(make_pair(*i,0));
			i=i->l;//���������� 
		}
		x=s.top();s.pop();
		if(x.second)printf("%d ",x.first.id);//����������������������
		else s.push(make_pair(x.first,1)),i=x.first.r;//���������û���������������
		
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
