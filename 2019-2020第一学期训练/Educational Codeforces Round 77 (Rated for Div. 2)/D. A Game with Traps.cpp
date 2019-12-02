#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define LL long long
struct Node{
	int l,r,d;
	bool operator < (const Node &b)const{
		return l<b.l;
	}
}b[maxn];
int a[maxn],k,n,t;
bool check(int x){
	int l=0,r=-1;LL w=0;
	for(int i=0;i<k;i++){
		if(b[i].d<=x)continue;
		if(b[i].l>r)w+=r-l+1,r=b[i].r,l=b[i].l;
		else r=max(r,b[i].r);
	}
	w+=r-l+1;
	return w*2+n+1<=t;
}
int main(){
	int m;scanf("%d%d%d%d",&m,&n,&k,&t);
	for(int i=0;i<m;i++)scanf("%d",a+i);
	for(int i=0;i<k;i++)scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].d);
	sort(b,b+k);sort(a,a+m);
	int l=0,r=m-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(a[mid]))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",m-l);
	return 0;
}
