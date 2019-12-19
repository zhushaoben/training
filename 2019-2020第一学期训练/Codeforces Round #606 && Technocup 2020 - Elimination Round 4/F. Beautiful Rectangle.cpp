#include<bits/stdc++.h>
using namespace std;
#define maxn 400005
struct Node{
	int x,w;
	bool operator < (const Node &b)const{
		return w>b.w;
	}
}b[maxn];
int a[maxn],si,c[maxn],d[maxn],ans,row,col;
int *A[1000];
void add(int w,int w1){
	int x=w%row,y=(w/row+w%row)%col;
	A[x][y]=w1;
}
int main(){
	int n,w=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	for(int i=0;i<n;i++){
		w++;if(a[i]!=a[i+1])b[si++]={a[i],w},c[w]++,d[w]+=w,w=0;
	}
	for(int i=1;i<=n;i++)d[i]+=d[i-1];
	for(int i=n;i;i--)d[i]+=i*c[i+1],c[i]+=c[i+1];
	for(int i=1;;i++){
		int r=d[i]/i;if(r<i)break;
		if(r*i>ans)ans=r*i,row=i,col=r;
	}
	w=0;sort(b,b+si);
	for(int i=0;i<row;i++)A[i]=new int[col]();
	for(int i=0;i<si&&w<ans;i++){
		b[i].w=min(b[i].w,row);for(int j=0;j<b[i].w&&w<ans;j++)add(w++,b[i].x);
	}
	printf("%d\n%d %d\n",ans,row,col);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)printf("%d ",A[i][j]);
		puts("");
	}
	return 0;
}
