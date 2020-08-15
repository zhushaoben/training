#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],n,now[N<<2][3],num[N<<2][3];
char ans[N];
void read(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[a[i]]=i;
}
void update(int x){
	for(int i=0;i<3;i++)now[x][i]=now[x<<1|1][now[x<<1][i]],
	num[x][i]=num[x<<1][i]+num[x<<1|1][now[x<<1][i]];
}
int w;
void build(int x,int l,int r){
	if(l==r){
		if(a[l]==w)for(int i=0;i<3;i++)num[x][i]=now[x][i]=0;
		else for(int i=0;i<3;i++)num[x][i]=i/2,now[x][i]=i%2+1;
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	update(x);
}
int L,R;
void change(int x,int l,int r){
	if(l==r){
		for(int i=0;i<3;i++)num[x][i]=0,now[x][i]=i-1;
		now[x][0]=0;
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)change(x<<1,l,mid);
	else change(x<<1|1,mid+1,r);
	update(x);
}
void query(int x,int l,int r,int &no,int &nu){
	if(L<=l&&R>=r){nu+=num[x][no],no=now[x][no];return;}
	int mid=(l+r)>>1;
	if(L<=mid)query(x<<1,l,mid,no,nu);
	if(R>mid)query(x<<1|1,mid+1,r,no,nu);
}
void work(){
	read();int n1=(n+1)/2,no,nu;
	w=1,build(1,1,n);
	for(int i=1;i<n1;i++){
		no=nu=0;L=1,R=b[i]-1;
		if(L<=R)query(1,1,n,no,nu);
		L=b[i]+1,R=n,no=0;
		if(L<=R)query(1,1,n,no,nu);
		if(nu>=abs(n1-i))ans[b[i]]='1';
		else ans[b[i]]='0';
		L=b[i],change(1,1,n);
	}
	ans[b[n1]]='1';
	w=n,build(1,1,n);
	for(int i=n;i>n1;i--){
		no=nu=0;L=1,R=b[i]-1;
		if(L<=R)query(1,1,n,no,nu);
		L=b[i]+1,R=n,no=0;
		if(L<=R)query(1,1,n,no,nu);
		if(nu>=abs(n1-i))ans[b[i]]='1';
		else ans[b[i]]='0';
		L=b[i],change(1,1,n);
	}
	ans[n+1]=0;
	puts(ans+1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
