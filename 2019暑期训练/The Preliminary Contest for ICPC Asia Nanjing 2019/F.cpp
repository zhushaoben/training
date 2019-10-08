#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct Node{
	int l,r,num,fa,L,R;
}a[maxn*50];
int t[maxn],rt[maxn],se,f[maxn],p[maxn];
void add(int &x,int f,int l,int r,int w,int fa){
	x=++se,a[x]=a[f],a[x].fa=fa,a[x].R=r;
	a[x].num++;a[x].L=l;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(w<=mid)add(a[x].l,a[f].l,l,mid,w,x);
	else add(a[x].r,a[f].r,mid+1,r,w,x);
}
int x1,f1;
void query(int &f,int &x,int l,int r,int w,int fa,int fa1){
	if(a[f].fa!=fa)a[++se]=a[f],a[se].fa=fa,a[se].L=l,a[se].R=r,f=se;
	if(a[x].fa!=fa1)a[++se]=a[x],a[se].fa=fa1,a[se].L=l,a[se].R=r,x=se;
	if(l==r){
		f1=f,x1=x;return;
	}
	int mid=(l+r)>>1;
	if(w<=mid)query(a[f].l,a[x].l,l,mid,w,f,x);
	else query(a[f].r,a[x].r,mid+1,r,w,f,x);
}
int query1(){
	int f=f1,x=x1;
	while(f){
		if(a[a[f].fa].r==f){
			f=a[f].fa,x=a[x].fa;
			if(a[a[x].l].num-a[a[f].l].num){
				f=a[f].l,x=a[x].l;
				while(a[x].l||a[x].r){
					if(a[a[x].r].num-a[a[f].r].num)x=a[x].r,f=a[f].r;
					else x=a[x].l,f=a[f].l; 
				}
				return a[x].L;
			}
		}
		else{
			f=a[f].fa,x=a[x].fa;
		}
	}
	return 0;
}
void work(){
	memset(rt,0,sizeof(rt)),memset(f,0,sizeof(f)); 
	se=0;memset(a,0,sizeof(Node));
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",t+i),add(rt[i],rt[i-1],1,n,t[i],0),p[t[i]]=i;
	a[0].fa=1;
	for(int i=1;i<=n;i++){
		query(rt[max(p[i]-k-1,0)],rt[min(p[i]+k,n)],1,n,i,0,0);
		f[i]=f[query1()]+1;
		printf("%d ",f[i]);
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
/*
2
3 1
3 2 1
7 2
3 1 4 6 2 5 7
*/
