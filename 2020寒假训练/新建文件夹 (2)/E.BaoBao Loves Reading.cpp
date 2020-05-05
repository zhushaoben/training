#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int pre[maxn],c[maxn],ans[maxn],n;
int lowbit(int x){return x&(-x);}
void add(int x,int num){
    while(x<=n){
        c[x]+=num;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void work(){
	int x;scanf("%d",&n);
	for(int i=1;i<=n;i++)pre[i]=ans[i]=c[i]=0;
	ans[1]=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(pre[x]){
			add(pre[x],-1),add(i,1);
			ans[sum(i)-sum(pre[x])]--;
		}
		else add(i,1);
		pre[x]=i;
	}
	for(int i=1;i<n;i++)printf("%d ",ans[i]+=ans[i-1]);
	printf("%d\n",ans[n]+ans[n-1]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
