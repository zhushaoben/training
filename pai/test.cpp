#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+10,N=2e5+5;
struct SBT{
    int key,num,mi,w,l,son[2],si1;
}a[N*10];
int root,si;
void update(int x){
	a[x].si1=a[a[x].son[0]].si1+a[a[x].son[1]].si1+1;
	a[x].mi=min(a[a[x].son[0]].mi,min(a[a[x].son[1]].mi,a[x].w));
	a[x].l=min(a[a[x].son[0]].l,a[x].key);
}
void rotate(int &x,int d){
    int y=a[x].son[d^1];
    a[x].son[d^1]=a[y].son[d],a[y].son[d]=x;
    update(x);update(x=y);
}
void maintain(int &x,int d){
    if(!a[x].son[d])return;
    if(a[a[x].son[d^1]].si1<a[a[a[x].son[d]].son[d^1]].si1)rotate(a[x].son[d],d),rotate(x,d^1);
    else if(a[a[x].son[d^1]].si1<a[a[a[x].son[d]].son[d]].si1)rotate(x,d^1);
    else return;
    maintain(a[x].son[0],0),maintain(a[x].son[1],1),maintain(x,0),maintain(x,1);
}
int ans,ans1;
void pre(int x,int num){//求num的前驱
    if(!x)return;
    if(a[x].key<num)ans=x,pre(a[x].son[1],num);
    else pre(a[x].son[0],num);
}
void suc(int x,int num){//求后继 
    if(!x)return;
    if(a[x].key>num)ans1=x,suc(a[x].son[0],num);
    else suc(a[x].son[1],num);
}
void insert(int &x,int key){
    if(!x){
		pre(root,key),suc(root,key);
		a[x=++si]={key,1,0,0,key,0,0,1};
		a[x].w=a[x].mi=key-a[ans].key;
		if(a[ans1].num==1)
			a[ans1].w=a[ans1].key-key,update(ans1);
		return;
	}
    if(a[x].key==key){a[x].num++,a[x].w=a[x].mi=0;return;}
    int d=key>a[x].key;
    insert(a[x].son[d],key);
    update(x);
    maintain(x,d);//插入后平衡一遍 
}
void del1(int &x,int key){
    if(a[x].key==key){x=a[x].son[1];return;}
    del1(a[x].son[key>a[x].key],key);
    update(x);
}
void del(int &x,int key){
    if(a[x].key!=key){
        del(a[x].son[key>a[x].key],key);
        update(x);return;
    }
    if(a[x].num>1){
		if((--a[x].num)==1)pre(root,key),a[x].w=key-a[ans].key;
		update(x);return;
	}
    pre(root,key),suc(root,key);
    if(a[ans1].num==1)a[ans1].w=a[ans1].key-a[ans].key,update(ans1);
    if(!a[x].son[0])x=a[x].son[1];
    else if(!a[x].son[1])x=a[x].son[0];
    else{
    	int p=a[x].son[1];
        while(a[p].son[0])p=a[p].son[0];
        a[x].key=a[p].key,a[x].num=a[p].num,a[x].w=a[p].w;del1(a[x].son[1],a[p].key);
        update(x);
    }
}
int tmp;
void query(int x,int key){
    if(!x)return;
    if(a[x].l>=key){tmp=min(tmp,a[x].mi);return;}
    if(a[x].key>=key)tmp=min(tmp,a[x].w);
	if(a[x].key>key)query(a[x].son[0],key);
	query(a[x].son[1],key);
}
int main(){
	int q,op,x;scanf("%d",&q);
	a[0].mi=inf;
	a[si=root=1]={-1,1,inf,inf,-1,0,2,1};
	a[++si]={inf*2,1,inf,inf,inf*2,0,0,1};
	while(q--){
		scanf("%d%d",&op,&x);
		if(op==1)insert(root,x);
		else if(op==2)del(root,x);
		else if(op==3){
			int p,p1=-inf;
			pre(root,x),p=a[ans].key;
			if(p*2>x&&a[ans].num>1){puts("Yes");continue;}
			if(p>0)pre(root,p),p1=a[ans].key;
			if(p+p1>x){puts("Yes");continue;}
			tmp=inf;query(root,x);
			if(tmp<x)puts("Yes");
			else puts("No");
		}
	}
	return 0;
} 
