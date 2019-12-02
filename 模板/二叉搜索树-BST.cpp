#include<cstdio>
struct BSTnode{
	BSTnode *l,*r;//�ֱ�ָ�����ҽڵ�
	int val;//�ڵ�����ֵ
	BSTnode(int v){//���캯�� 
		l=r=NULL,val=v;
	}
};
BSTnode* root=new BSTnode(0);
BSTnode* search(int k){//��������������
	BSTnode* x=root;
	while(x!=NULL&&x->val!=k){
		if(x->val<k)x=x->r;
		else x=x->l;
	}
	return x;
}
void insert(int k){//�������������� 
	BSTnode *x=root,*y;
	while(x!=NULL&&x->val!=k){
		y=x;
		if(x->val<k)x=x->r;
		else x=x->l;
	}
	if(x!=NULL)return;//������ھ�ֱ���˳� 
	if(k<y->val)y->l=new BSTnode(k);
	else  y->r=new BSTnode(k);
}
void remove(int k){//����������ɾ�� 
	BSTnode *x=root,*y,*z;
	while(x!=NULL&&x->val!=k){
		y=x;
		if(x->val<k)x=x->r;
		else x=x->l;
	}
	if(x==NULL)return;//x������ 
	if(x->l==NULL&&x->r==NULL){//x���ӽڵ� 
		if(k<y->val)delete x,y->l=NULL;
		else delete x,y->r=NULL;
		return;
	}
	if(x->l==NULL||x->r==NULL){//xֻ��һ���ӽڵ�,���ӽڵ��滻x,������������Ȼ���� 
		if(x->l!=NULL){
			if(k < y->val){
				y->l=x->l,delete x;
			}
			else y->r=x->l,delete x;
		}
		else{
			if(k < y->val){
				y->l=x->r,delete x;
			}
			else y->r=x->r,delete x;
		}
		return ;
	}//x�������ӽڵ�,���ҵ������д��ڻ�С��k����ӽ���ֵ�滻
	z=x;
	y=x->r;while(y->l!=NULL)z=y,y=y->l;//�ô���k����ӽ���ֵ�滻 
	if(y->val>z->val)z->r=NULL;//һ��Ҫ�жϣ�������Ϊy��z����ڵ㣬��Ϊz������x�� 
	else z->l=NULL;
	x->val=y->val,delete y;
}
void mid_traversal(BSTnode* x){//���������������� 
	if(x==NULL)return;
	mid_traversal(x->l);
	printf("%d ",x->val);
	mid_traversal(x->r);
} 
int main(){
	int n,x;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insert(x);
	}
	mid_traversal(root);
	return 0;
}
