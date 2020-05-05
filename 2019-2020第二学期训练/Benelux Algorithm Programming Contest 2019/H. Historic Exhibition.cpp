#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct Node{
	int x,y,id;
	bool operator < (const Node &b){return x+y<b.x+b.y;}
}a[N],b[N];
int ans[N];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i+1;
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
	}sort(a,a+n);
	for(int i=0;i<m;i++)scanf("%d",&b[i].x),b[i].id=i+1;
	sort(b,b+m);int l=0;
	for(int i=0;i<m;i++){
		while(l<n&&a[l].y<b[i].x)l++;
		if(a[l].x==b[i].x||a[l].y==b[i].x)ans[b[i].id]=a[l++].id;
		else return puts("impossible"),0;
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
} 
