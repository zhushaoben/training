#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
struct Node{
	int x,y,w,h;
}t[20];
int a[maxn][maxn],b[maxn][maxn],W,H;
int work(int x1,int y1,int x2,int y2,int w){
	int ans=0;x1=max(0,x1),y1=max(0,y1),x2=min(x2,H),y2=min(y2,W);
	for(int i=x1;i<=x2;i++)for(int j=y1;j<=y2;j++)a[i][j]=w;
	for(int i=x1;i<x2;i++)for(int j=y1;j<y2;j++)ans+=(b[i][j]!=w),b[i][j]=w;
	return ans;
}
int main(){
	int n,q,x,y;scanf("%d%d%d",&W,&H,&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d%d",&t[i].x,&t[i].y,&t[i].h,&t[i].w);
	for(int i=n;i;i--){
		work(t[i].x,t[i].y,t[i].x+t[i].w,t[i].y+t[i].h,i);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&x,&y);x=a[x][y];
		printf("%d\n",x?work(t[x].x,t[x].y,t[x].x+t[x].w,t[x].y+t[x].h,x):0);
	}
	return 0;
}
