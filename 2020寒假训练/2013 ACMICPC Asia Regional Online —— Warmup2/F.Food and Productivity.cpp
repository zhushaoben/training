#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
struct Node{
	int x,y;
	bool operator < (const Node &b)const{
		return x>b.x;
	}
}a[maxn],b[maxn];
int s[505][505],c[maxn],si,si1;
int calc(int x1,int y1,int x2,int y2){
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
void work(){
	int n,m,r,q;scanf("%d%d%d%d",&n,&m,&r,&q);
	si=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",s[i]+j);
			s[i][j]+=s[i][j-1];
		}
		for(int j=1;j<=m;j++)s[i][j]+=s[i-1][j];
	}
	for(int i=1+r*2;i<=n;i++){
		for(int j=1+r*2;j<=m;j++){
			a[si++].x=calc(i-2*r,j-2*r,i,j);
		}
	}
	si=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",s[i]+j);
			s[i][j]+=s[i][j-1];
		}
		for(int j=1;j<=m;j++)s[i][j]+=s[i-1][j];
	}
	for(int i=1+r*2;i<=n;i++){
		for(int j=1+r*2;j<=m;j++){
			a[si++].y=calc(i-2*r,j-2*r,i,j);
		}
	}
	sort(a,a+si);si1=0;
	for(int i=0;i<si;i++){
		while(si1&&a[i].x==b[si1-1].x&&a[i].y>b[si1-1].y)si1--;
		if(si1&&a[i].y<=b[si1-1].y)continue;
		b[si1]=a[i],c[si1++]=a[i].y-a[i].x;
	}
	int A,B,k,ans;
	b[si1]={0,0},c[si1++]=1e9;
	for(int i=0;i<q;i++){
		scanf("%d%d",&A,&B);
		k=lower_bound(c,c+si1,A-B)-c;
		ans=min(b[k].x+A,b[k].y+B);
		if(k)ans=max(ans,min(b[k-1].x+A,b[k-1].y+B));
		printf("%d\n",ans);
	}
}
int main(){
	int t,x;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d:\n",i);
		work();
		if(i!=t)puts("");
	}
	return 0;
} 
