#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
	int x,l;
	bool operator < (const Node &b)const{
		if(l!=b.l)return l>b.l;
		return x<b.x;
	} 
}a[N];
int si,ans[N];
void op(int l,int r){
	if(r<l)return;
	int x=(l+r)/2;
	a[si++]={x,r-l+1};
	op(l,x-1),op(x+1,r);
}
void work(){
	int n;scanf("%d",&n);
	si=0;op(1,n);
	sort(a,a+n);
	for(int i=0;i<n;i++)ans[a[i].x]=i+1;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
