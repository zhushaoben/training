#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdarg.h>
using namespace std;
#define inf 0x3fffffff
#define is_r(x) (x->fa?x->fa->son[1]==x:0)
struct Splay{
	int key,size,maxl,maxr,maxt,sum;//maxlΪ���������ֵ,maxrΪ���������ֵ, maxtΪ�������ֵ 
	bool rev,same;//��ת�͸�ֵ��� 
	Splay *son[2],*fa;
	Splay(){
		memset(this,0,sizeof(Splay));
	}
	Splay(int x,Splay *f){
		sum=maxl=maxr=maxt=key=x,size=1,rev=same=0,fa=f;
	}
}*root,*null=new Splay;
int a[500005];
//����ĺ���<stdarg.h>�ṩ���� 
//typedef char *  va_list;//ָ�� 
//#define _ADDRESSOF(n)   ( &reinterpret_cast<const char &>(n) ) //ȡn�ĵ�ַ��תΪchar* 
//#define _INTSIZEOF(n)  ((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1) ) //��sizeof(n)����ȡ��sizeof(int)��������,���ҵ����ϱ���*2���� 
//#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) ) //���һλ�ĵ�ַ����ap�� 
//#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) ) //ȡ��ap��ֵ������apָ����һ��λ��
//#define va_end(ap)      ( ap = (va_list)0 )  //�ÿ�ap 
int Max(int n,...){//��n������max 
    va_list arg_ptr;
    va_start(arg_ptr, n);
	int ans = -inf;
    for(int i=0; i < n; ++i){
        int temp = va_arg(arg_ptr,int);
        ans=max(ans,temp);
    }
    va_end(arg_ptr);
    return ans;
}
void push_down(Splay *x){//�·ű�� 
	if(x==null)return;
	if(x->rev){//���䷭ת 
		x->rev=0,x->son[0]->rev^=1,x->son[1]->rev^=1;
		swap(x->son[0],x->son[1]),swap(x->maxl,x->maxr);
	}
	if(x->same){//���丳ֵ 
		x->same=0,x->son[0]->key=x->son[1]->key=x->key;
		x->son[0]->same=x->son[1]->same=1;
		x->sum=x->key*x->size;
		x->maxl=x->maxr=x->maxt=(x->key>0?x->sum:x->key);
	}
}
void update(Splay *x){//���½ڵ� 
	if(x==null)return;
	push_down(x),push_down(x->son[0]),push_down(x->son[1]);//Ҫ�õ��ӽڵ��maxl,maxr����Ҫ�·��ӽڵ��� 
	x->size=x->son[0]->size+x->son[1]->size+1,//���½ڵ�洢��ֵ 
	x->sum=x->son[0]->sum+x->son[1]->sum+x->key,
	x->maxl=max(x->son[0]->maxl,x->son[0]->sum+x->key+max(0,x->son[1]->maxl)),
	x->maxr=max(x->son[1]->maxr,x->son[1]->sum+x->key+max(0,x->son[0]->maxr));
	x->maxt=Max(3,x->son[0]->maxt,x->son[1]->maxt,max(0,x->son[0]->maxr)+max(0,x->son[1]->maxl)+x->key);
}
void mid_traversal(Splay *x){//�������
	push_down(x);
	if(x->son[0]!=null)mid_traversal(x->son[0]);
	printf("%d %d\n",x->key,x->size);
	if(x->son[1]!=null)mid_traversal(x->son[1]);
}
void rotate(Splay *&x,int d){//��ת 
	Splay *p=x->son[!d];
	push_down(x),push_down(p);//���·ű�� 
	x->son[!d]=p->son[d];//����ָ���ϵ 
	if(p->son[d]!=null)p->son[d]->fa=x;
	p->son[d]=x,p->fa=x->fa,x->fa=p;
	update(x),update(p);//���½ڵ� 
	x=p;//xָ��pָ���λ��
}
void up(Splay *x){//��x��ת������үү�ڵ� 
	bool d=is_r(x);
	Splay *&a=x->fa->fa->fa?x->fa->fa->fa->son[is_r(x->fa->fa)]:root;//aΪָ��үү�ڵ��ָ�� 
	if(is_r(x->fa)!=d){//x�͸���λ�����Ǹ��׵���� 
		rotate(a->son[!d],!d),rotate(a,d);
	}
	else rotate(a,!d),rotate(a,!d);//x�͸���λ�����Ǹ��׵�ͬ�� 
}
void splay(Splay *x,Splay *&root){//��x�ڵ���ת��root�ڵ� 
	if(x==null)return;
	while(x->fa!=root&&x!=root){
		up(x);
	}
	if(x->fa==root)rotate(root,!is_r(x));
}
void build(Splay *&x,Splay *fa,int l,int r){//����һ��[l,r]������,xָ�������ĸ�,���ĸ���Ϊfa 
	if(l>r)return;
	int mid=(l+r)>>1;
	x=new Splay(a[mid],fa),x->son[0]=x->son[1]=null;//���ڵ�������е� 
	build(x->son[0],x,l,mid-1);
	build(x->son[1],x,mid+1,r);
	update(x);
}
Splay *Find(Splay *x,int k){//����x�����еĵ�k���� 
	if(x==null)return 0;
	update(x);
	if(x->son[0]->size>=k)return Find(x->son[0],k);
	if(x->son[0]->size+1==k)return x;
	return Find(x->son[1],k-x->son[0]->size-1);
}
void insert(int l,int s){//��l������볤Ϊs������ 
	for(int i=0;i<s;i++){
		scanf("%d",a+i);
	}
	splay(Find(root,l+1),root),splay(Find(root,l+2),root->son[1]);//��l��ת��root,��l+1��ת��root���Ҷ���,��ʱl+1û������� 
	build(root->son[1]->son[0],root->son[1],0,s-1),update(root),update(root->son[1]);//���������� 
}
void remove(Splay *x){//ɾ��x���� 
	if(x==null)return;
	remove(x->son[0]),remove(x->son[1]),delete x;
}
void del(int l,int r){//ɾ��[l,r] 
	splay(Find(root,l),root);//��l-1��ת��root 
	splay(Find(root,r+2),root->son[1]);//��r+1��ת��root���Ҷ���
	remove(root->son[1]->son[0]),root->son[1]->son[0]=null,update(root->son[1]),update(root);//r+1������Ӽ�Ϊ����[l,r]
}
void modify(int l,int r,int s){//��[l,r]����ֵΪs 
	splay(Find(root,l),root);//��l-1��ת��root 
	splay(Find(root,r+2),root->son[1]);//��r+1��ת��root���Ҷ��� 
	Splay *x=root->son[1]->son[0];//r+1������Ӽ�Ϊ����[l,r],���Ǹ��� 
	x->same=1,x->key=s,update(root->son[1]),update(root);splay(x,root);
}
void rev(int l,int r){//��[l,r]��ת 
	splay(Find(root,l),root);//��l-1��ת��root 
	splay(Find(root,r+2),root->son[1]);//��r+1��ת��root���Ҷ���
	root->son[1]->son[0]->rev=1;//r+1������Ӽ�Ϊ����[l,r],���Ǹ���
	update(root->son[1]),update(root);
}
int get_sum(int l,int r){//��[l,r]�ĺ� 
	splay(Find(root,l),root);
	splay(Find(root,r+2),root->son[1]);
	return root->son[1]->son[0]->sum; 
}
int max_sum(){//����������ֵ 
	update(root); 
	return root->maxt;
}
//ע������ʱ���������˶࿪�����սڵ㣬�����Խ�� 
int main(){
	return 0;
}
