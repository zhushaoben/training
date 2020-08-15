#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define L(x) node[(x)].ch[0] 
#define R(x) node[(x)].ch[1] 
using namespace std;
const int N=3e5+5;
struct Node{
	int fa,ch[2];
	bool rev;
	void init(){fa=ch[0]=ch[1]=0;}
}node[N];
int n,m;
inline bool isroot(int x)
{
	return (L(node[x].fa)!=x&&R(node[x].fa)!=x);
}
void down(int x)
{
	if(node[x].rev)
	{
		node[L(x)].rev^=1;
		node[R(x)].rev^=1;
		swap(L(x),R(x));
		node[x].rev=false;
	}
}
void rotate(int x,bool k)
{
	int y=node[x].fa;int z=node[y].fa;
	node[y].ch[!k]=node[x].ch[k];
	node[node[x].ch[k]].fa=y;
	if(!isroot(y)){
		if(L(z)==y)L(z)=x;
		else R(z)=x;
		
	}
	node[x].fa=z;
	
	node[x].ch[k]=y;
	node[y].fa=x;
	
}
int S[N],s_top;
void splay(int x)
{
	int i,y,z;
	s_top=0;
	S[0]=x;
	for(i=x;!isroot(i);i=node[i].fa)
	  S[++s_top]=node[i].fa;
	for(i=s_top;i>=0;i--)
	  down(S[i]);
	
	while(!isroot(x))
	{
		y=node[x].fa;z=node[y].fa;
		if(isroot(y)){
			if(L(y)==x)rotate(x,1);
			else if(R(y)==x)rotate(x,0);
		}
		else
		{
			if(L(y)==x&&L(z)==y){
				rotate(y,1);rotate(x,1);
			}
			else if(R(y)==x&&R(z)==y){
				rotate(y,0);rotate(x,0);
			}
			else if(L(y)==x&&R(z)==y){
				rotate(x,1);rotate(x,0);
			}
			else{
				rotate(x,0);rotate(x,1);
			}
		}
	}
}
void access(int x)
{
	int pre=0;
	while(x)
	{
		splay(x);
		R(x)=pre;
		pre=x;
		x=node[x].fa;
	}
}
void makeroot(int x)
{
	access(x);splay(x);
	node[x].rev^=1;
}
int find(int x)
{
	access(x);
	splay(x);
	while(L(x))x=L(x);
	return x;
}
void cut(int x,int y)
{
	makeroot(x);access(y);
	splay(y);//
	node[x].fa=L(y)=0;
}
void link(int x,int y)
{
	makeroot(x);
	node[x].fa=y;
}
int u[N],v[N],r[N];
int work(){
	int n,m,q,l;scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<=n;i++)node[i].init();
	for(int i=1;i<=m;i++)scanf("%d%d",u+i,v+i);
	l=1;
	for(int i=1;i<=m;i++){
		while(find(u[i])==find(v[i]))r[l]=i,cut(u[l],v[l]),l++;
		link(u[i],v[i]);
	}
	while(l<=m)r[l++]=m+1;
	int L,R,la=0;
	for(int i=0;i<q;i++){
		scanf("%d%d",&L,&R),L=(L^la)%m+1,R=(R^la)%m+1;
		if(L>R)swap(L,R);
		if(r[L]>R)la=0,puts("No");
		else la=1,puts("Yes");
	}
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
