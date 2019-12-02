#include<cstdio>
#include<cstring>
using namespace std;
#define size(x) (x!=NULL?x->size:0)
inline int random(){//��������� 
	static int seed=66;
	return seed=seed*48271LL%2147483647;//�ٶ���˵���[0,2147483646]������һ�鲻���ظ� 
}
struct Treap{
	int key,prio,size,num;//key�������������,prio��������,num��keyֵ����Ŀ,size��������num֮�� 
	Treap* son[2];
	Treap(){
		memset(this,0,sizeof(Treap));
	}
	Treap(int k){
		key=k,prio=random(),size=num=1,son[0]=son[1]=0;
	}
}*root;
void rotate(Treap *&x,int d){//��ת,dΪ��ת����,0Ϊ����,1Ϊ����
	Treap *y=x->son[d^1];//yָ��Ҫ��ת�����ڵ���ӽڵ� 
	x->son[d^1]=y->son[d],y->son[d]=x;//����ָ���ϵ 
	y->size=x->size;//����sizeֵ 
	x->size=size(x->son[0])+size(x->son[1])+x->num;
	x=y;//�����˽�����������ָ��ָ��y�� 
}
void insert(Treap *&x,int key){//����ڵ� 
	if(x==NULL){//�ڵ�Ϊ����ֱ�Ӵ���һ���ڵ� 
		x=new Treap(key);return;
	}
	x->size++;
	if(key==x->key){x->num++;return;}//Ȩֵ�Ѿ����ڣ���num++�� 
	int d=key>x->key;
	insert(x->son[d],key);//���뵽�ӽڵ� 
	if(x->prio < x->son[d]->prio)rotate(x,d^1);//��������ת������ѵ����� 
}
void del(Treap *&x,int key){//ɾ���ڵ� 
	if(x->key!=key){
		del(x->son[key>x->key],key);//�����ӽڵ���ȨֵΪkey�Ľڵ� 
		x->size--;//������һ 
		return;
	}
	//�ҵ��ڵ�� 
	if(x->num>1){//������벻ֹһ��,��num--���� 
		x->num--,x->size--;return;
	}
	Treap* p=x;
	if(x->son[0]==NULL)x=x->son[1],delete p;//���ӽڵ�Ϊ��,�����ӽڵ�(����ҲΪ��)����Լ�
	else if(x->son[1]==NULL)x=x->son[0],delete p;//���ӽڵ�Ϊ��,�����ӽڵ�����Լ� 
	else{
		int d=x->son[0]->prio > x->son[1]->prio;
		rotate(x,d);//��prioֵ�ϴ����ת������ 
		del(x,key);//����x�ڵ��������ٽ���ɾ�� 
	}
}
int query_id(Treap *x,int key){//�������б�keyС���м��� 
	if(x==NULL)return 0;
	if(x->key>key)return query_id(x->son[0],key);//��ǰ�ڵ��ֵ����key�������������е��������� 
	if(x->key==key)return size(x->son[0]);//��ǰ�ڵ��������key,������������С 
	else return size(x->son[0])+x->num+query_id(x->son[1],key);//����������,ֵҪ������������С�͵�ǰ�ڵ�Ĵ�С 
}
int query_key(Treap *x,int num){//���ŵ�num���� 
	if(x==NULL)return 0;
	if(size(x->son[0])>=num)return query_key(x->son[0],num);//��������С���ڵ���num����������������num�������� 
	if(size(x->son[0])+x->num>=num)return x->key;//�ŵ�num�����ǵ�ǰ�ڵ� 
	return query_key(x->son[1],num-size(x->son[0])-x->num);//������������num-(��������С+��ǰ�ڵ��С)�������� 
}
int ans;
void pre(Treap *x,int num){//��num��ǰ��(��С��num��������) 
	if(x==NULL)return;
	if(x->key<num)ans=x->key,pre(x->son[1],num);
	else pre(x->son[0],num);
}
void suc(Treap *x,int num){//���� 
	if(x==NULL)return;
	if(x->key>num)ans=x->key,suc(x->son[0],num);
	else suc(x->son[1],num);
}
void mid_traversal(Treap* x){//�������������������õ�˳����� 
	if(x->son[0])mid_traversal(x->son[0]);
	printf("%d ",x->key);
	if(x->son[1])mid_traversal(x->son[1]);
}
int main(){
	return 0;
}
