#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=1e9;
typedef long long LL;
int n,root,w[N];
struct Splay{
	int ch[2],fa,size,key,mi,rev;
	LL sum;
}a[N];
inline int get(int x){return a[a[x].fa].ch[1]==x;}
void update(int x){
	a[x].size=a[a[x].ch[0]].size+a[a[x].ch[1]].size+1;
	a[x].mi=min(a[a[x].ch[0]].mi,min(a[a[x].ch[1]].mi,a[x].key));
	a[x].sum=a[a[x].ch[0]].sum+a[a[x].ch[1]].sum+a[x].key;
}
void pushdown(int x){
    if (x&&a[x].rev){
    	a[a[x].ch[0]].rev^=1;
    	a[a[x].ch[1]].rev^=1;
    	swap(a[x].ch[1],a[x].ch[0]);
    	a[x].rev=0;
    }
}
int build(int l,int r,int fa){
    if (l>r) return 0;
    int mid=(l+r)>>1;
	a[mid].fa=fa;a[mid].key=w[mid];a[mid].size=1;
    a[mid].ch[0]=build(l,mid-1,mid);
    a[mid].ch[1]=build(mid+1,r,mid);
    update(mid);
    return mid;
}
void rotate(int x){
	pushdown(a[x].fa),pushdown(x);
	int old=a[x].fa,oldf=a[old].fa,wh=get(x);
	a[old].ch[wh]=a[x].ch[wh^1];
	if (a[old].ch[wh]) a[a[old].ch[wh]].fa=old;
	a[x].ch[wh^1]=old;
	a[old].fa=x;
	if (oldf) a[oldf].ch[a[oldf].ch[1]==old]=x;
	a[x].fa=oldf;
	update(old),update(x);
}
void splay(int x,int tar){
	for (int fa;(fa=a[x].fa)!=tar;rotate(x))
		if (a[fa].fa!=tar)rotate( (get(x)==get(fa))?fa:x );
	if (!tar) root=x;
}
void change(int x,int l,int w){
	if(l<=a[a[x].ch[0]].size){change(a[x].ch[0],l,w);}
	else if(l==a[a[x].ch[0]].size+1)a[x].key=w;
	else change(a[x].ch[1],l-a[a[x].ch[0]].size-1,w);
	update(x);
}
int find(int x){
	int now=root;
	while (1){
		pushdown(now);
		if (x<=a[a[now].ch[0]].size) now=a[now].ch[0];
		else{
			x-=a[a[now].ch[0]].size;
			if (x==1) return now;
			x-=1,now=a[now].ch[1];
		}
	}
}
int t;
void write(int x){
    pushdown(x);
    if (a[x].ch[0]) write(a[x].ch[0]);
    if(a[x].key!=inf)printf("%d%c",a[x].key,(++t)==n?'\n':' ');
    if (a[x].ch[1]) write(a[x].ch[1]);
}
int query1(int x,int w){
	if(a[x].mi>w)return -1;
	if(a[a[x].ch[1]].mi<w)return a[a[x].ch[0]].size+1+query1(a[x].ch[1],w);
	if(a[x].key<w)return a[a[x].ch[0]].size+1;
	return query1(a[x].ch[0],w);
}
int query(int l,int w){
	int aa=find(l);splay(aa,0);
	return query1(a[root].ch[0],w);
}
LL sum(int l,int r){
	int aa=find(l-1),bb=find(r+1);
	splay(aa,0),splay(bb,aa);
	return a[a[a[root].ch[1]].ch[0]].sum;
}
void reverse(int l,int r){
	int aa=find(l-1),bb=find(r+1);
	splay(aa,0),splay(bb,aa);
	a[a[a[root].ch[1]].ch[0]].rev^=1;
}
void work(){
	int q,op,x,y;scanf("%d%d",&n,&q);
	for(int i=2;i<=n+1;i++)scanf("%d",w+i);w[1]=w[n+2]=inf;
	root=build(1,n+2,0);
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y),x++;
			int w=find(x),l,w1,w2;
			if(a[w].key<y){puts("0");continue;}
			l=query(x,y);
			if(l==-1){puts("0");continue;}
			printf("%lld\n",sum(l+1,x)-1ll*(x-l)*(y-1));
			w1=a[find(l)].key,w2=a[find(l+1)].key;
			reverse(l,x),reverse(l,x-1);
			change(root,x,y-1),change(root,l,w1+w2-y+1);
		}
		else{
			scanf("%d",&x),x++;
			printf("%d\n",a[find(x)].key);
		}
	}
    t=0;write(root);
}
int main(){
	a[0].mi=inf;
    int t;scanf("%d",&t);
    while(t--)work();
    return 0;
}
