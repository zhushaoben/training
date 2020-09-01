#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
#define size(x) (x?x->size:0)
#define mi(x) (x?x->mi:inf) 
struct SBT{
    int key,size,num,mi,w,l;
    SBT *son[2];
    SBT(){memset(this,0,sizeof(SBT));}
    SBT(int x){num=size=1,l=key=x,son[0]=son[1]=0;}
}*root;
void update(SBT *x){
	x->size=size(x->son[0])+size(x->son[1])+1;
	x->mi=min(mi(x->son[0]),min(mi(x->son[1]),x->w));
	x->l=(x->son[0])?x->son[0]->l:x->key;
}
void rotate(SBT *&x,int d){
    SBT *y=x->son[d^1];
    x->son[d^1]=y->son[d],y->son[d]=x;
    update(x),update(y);x=y;
}
void maintain(SBT *&x,int d){
    if(x->son[d]==NULL)return;
    if(size(x->son[d^1])<size(x->son[d]->son[d^1]))rotate(x->son[d],d),rotate(x,d^1);
    else if(size(x->son[d^1])<size(x->son[d]->son[d]))rotate(x,d^1);
    else return;
    maintain(x->son[0],0),maintain(x->son[1],1),maintain(x,0),maintain(x,1);
}
SBT *ans,*ans1;
void pre(SBT *x,int num){//?num???
    if(!x)return;
    if(x->key<num)ans=x,pre(x->son[1],num);
    else pre(x->son[0],num);
}
void suc(SBT *x,int num){//??? 
    if(!x)return;
    if(x->key>num)ans1=x,suc(x->son[0],num);
    else suc(x->son[1],num);
}
void insert(SBT *&x,int key){
    if(!x){
		pre(root,key),suc(root,key);
		x=new SBT(key);
		x->w=x->mi=key-ans->key;
		if(ans1->num==1)
			ans1->w=ans1->key-key,ans1->mi=min(mi(ans1->son[0]),min(mi(ans1->son[1]),ans1->w));
		return;
	}
    if(x->key==key){x->num++,x->w=x->mi=0;return;}
    int d=key>x->key;
    insert(x->son[d],key);
    update(x);
    maintain(x,d);//??????? 
}
void del1(SBT *&x,int key){
    if(x->key==key){
    	x=x->son[1];
		return;
    }
    del1(x->son[key>x->key],key);
    update(x);
}
void del(SBT *&x,int key){
    if(x->key!=key){
        del(x->son[key>x->key],key);
        update(x);return;
    }
    if(x->num>1){
		if((--x->num)==1)pre(root,key),x->w=key-ans->key;
		update(x);return;
	}
    pre(root,key),suc(root,key);
    if(ans1->num==1)ans1->w=ans1->key-ans->key,
	ans1->mi=min(mi(ans1->son[0]),min(mi(ans1->son[1]),ans1->w));
    SBT *p=x;
    if(x->son[0]==NULL)x=x->son[1];
    else if(x->son[1]==NULL)x=x->son[0];
    else{
    	p=x->son[1];
        while(p->son[0])p=p->son[0];
        x->key=p->key,x->num=p->num,x->w=p->w;del1(x->son[1],p->key);
        update(x);
    }
}
int tmp;
void query(SBT *x,int key){
    if(!x)return;
    if(x->l>=key){tmp=min(tmp,x->mi);return;}
    if(x->key>=key)tmp=min(tmp,x->w);
	if(x->key>key)query(x->son[0],key);
	query(x->son[1],key);
}
int main(){
	int q,op,x;scanf("%d",&q);
	root=new SBT(-1);root->son[1]=new SBT(inf*2);root->son[1]->mi=root->son[1]->w=inf*2; 
	while(q--){
		scanf("%d%d",&op,&x);
		if(op==1)insert(root,x);
		else if(op==2)del(root,x);
		else if(op==3){
			int p,p1=-inf;
			pre(root,x),p=ans->key;
			if(p*2>x&&ans->num>1){puts("Yes");continue;}
			if(p>0)pre(root,p),p1=ans->key;
			if(p+p1>x){puts("Yes");continue;}
			tmp=inf;query(root,x);
			if(tmp<x)puts("Yes");
			else puts("No");
		}
	}
	return 0;
} 
