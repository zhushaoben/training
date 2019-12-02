#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
bool vis[maxn+5];int ans[maxn+5];
void work(){
	int n,l=1,pre=0,x;scanf("%d",&n);
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=0;i<n;i++,pre=x){
		scanf("%d",&x);
		if(x!=pre)vis[ans[i]=x]=1;
		else{
			while(vis[l])l++;
			vis[ans[i]=l]=1;
		}
		if(x<pre||ans[i]>x){for(int j=i+1;j<n;j++)scanf("%*d");puts("-1");return;}
	}
	for(int i=0;i<n;i++)printf("%d ",ans[i]);puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
