#include<cstdio>
struct BSTnode{
	BSTnode *l,*r;//分别指向左右节点
	int val;//节点代表的值
	BSTnode(int v){//构造函数 
		l=r=NULL,val=v;
	}
};
BSTnode* root=new BSTnode(0);
BSTnode* search(int k){//二叉搜索树查找
	BSTnode* x=root;
	while(x!=NULL&&x->val!=k){
		if(x->val<k)x=x->r;
		else x=x->l;
	}
	return x;
}
void insert(int k){//二叉搜索树插入 
	BSTnode *x=root,*y;
	while(x!=NULL&&x->val!=k){
		y=x;
		if(x->val<k)x=x->r;
		else x=x->l;
	}
	if(x!=NULL)return;//如果存在就直接退出 
	if(k<y->val)y->l=new BSTnode(k);
	else  y->r=new BSTnode(k);
}
void remove(int k){//二叉搜索树删除 
	BSTnode *x=root,*y,*z;
	while(x!=NULL&&x->val!=k){
		y=x;
		if(x->val<k)x=x->r;
		else x=x->l;
	}
	if(x==NULL)return;//x不存在 
	if(x->l==NULL&&x->r==NULL){//x无子节点 
		if(k<y->val)delete x,y->l=NULL;
		else delete x,y->r=NULL;
		return;
	}
	if(x->l==NULL||x->r==NULL){//x只有一个子节点,用子节点替换x,二叉搜索树依然成立 
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
	}//x有两个子节点,则找到子树中大于或小于k的最接近的值替换
	z=x;
	y=x->r;while(y->l!=NULL)z=y,y=y->l;//用大于k的最接近的值替换 
	if(y->val>z->val)z->r=NULL;//一定要判断，不能认为y是z的左节点，因为z可以是x； 
	else z->l=NULL;
	x->val=y->val,delete y;
}
void mid_traversal(BSTnode* x){//中序遍历，有序输出 
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
