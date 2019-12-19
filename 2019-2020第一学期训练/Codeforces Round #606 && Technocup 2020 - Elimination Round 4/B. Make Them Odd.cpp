#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
struct Node{
	int x,d;
	bool operator < (const Node &b)const{
		return x<b.x;
	}
}a[maxn];
void work(){
	int n,x,w;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x),w=0;
		while(!(x&1))x>>=1,w++;
		a[i]={x,w};
	}
	sort(a,a+n);a[n]={0,0};
	int ans=0;w=0;
	for(int i=0;i<n;i++){
		w=max(w,a[i].d);
		if(a[i].x!=a[i+1].x){
			ans+=w,w=0;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
