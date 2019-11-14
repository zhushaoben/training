/*
find some circles that contain all k boxes
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 5000
#define LL long long
unordered_map<long long,int> mp;
struct Node{
	int n,num[maxn+5];LL sum;
}a[15];
LL sum;int ans[15],ans1[15],k;
int cir(int x,int fi,int s){
	s|=(1<<x);ans[x]=fi;
	LL w,now=fi,p=x;
	while(1){
		w=sum-a[p].sum+now;
		if(w==fi)return ans1[x]=p,s;
		if(mp.find(w)==mp.end())return 0;
		if(s&(1<<(p=mp[w])))return 0;
		s|=(1<<p);ans[p]=w,ans1[p]=mp[now],now=w;
	}
}
bool vis[1<<15];
void dfs(int x,int s){
	if(x>=k){
		puts("Yes");
		for(int i=0;i<k;i++)printf("%d %d\n",ans[i],ans1[i]+1);
		exit(0);
	}
	if(vis[s])return;
	if(s&(1<<x))dfs(x+1,s);
	else{
		for(int i=0;i<a[x].n;i++){
			int t=cir(x,a[x].num[i],s);
			if(t)dfs(x+1,t),vis[t]=1;
		}
	}
}
int main(){
	sum=0;scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",a+i);
		for(int j=0;j<a[i].n;j++)scanf("%d",a[i].num+j),a[i].sum+=a[i].num[j],mp[a[i].num[j]]=i;
		sum+=a[i].sum;
	}
	if(sum%k)return puts("No"),0;
	sum/=k;dfs(0,0);
	return puts("No"),0;
} 
