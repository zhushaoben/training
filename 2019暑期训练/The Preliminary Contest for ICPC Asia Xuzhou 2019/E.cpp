#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
struct Node{
	int w,x,ans;
	bool operator < (const Node &b)const{
		if(w!=b.w)return w>b.w;
		return x>b.x;
	}
}a[maxn];
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].w),a[i].x=i;
	int ma=0,l=1;sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(l<i&&a[l].w>=a[i].w+m)ma=max(ma,a[l].x),l++;
		a[i].ans=max(ma-a[i].x-1,-1);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		printf("%d ",a[i].ans);
	}
	printf("%d",a[n].ans);
	return 0;
}
