#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
struct Node{
	int x,y;
}a[maxn*2],s,t;
int cha(Node a,Node b,Node c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int main(){
	int n,q;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d%d%d",&a[i<<1].x,&a[i<<1].y,&a[i<<1|1].x,&a[i<<1|1].y);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
		int w=0;
		for(int j=0;j<n;j++)if(1ll*cha(a[j<<1],a[j<<1|1],s)*cha(a[j<<1],a[j<<1|1],t)<0)w++;
		if(w&1)puts("different");
		else puts("same");
	}
	return 0;
}
