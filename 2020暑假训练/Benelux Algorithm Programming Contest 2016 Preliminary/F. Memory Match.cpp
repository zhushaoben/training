#include<bits/stdc++.h>
using namespace std;
const int N=1005;
bool vis[N];
map<string,int>mp;
string s,t;
int main(){
	int n,k,x,y,sum=0,w=0,w1=0;scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		cin>>x>>y>>s>>t;
		if(s==t){sum++;}
		if(!vis[x])vis[x]=1,mp[s]++;
		if(!vis[y])vis[y]=1,mp[t]++;
	}
	for(int i=1;i<=n;i++)w+=vis[i];
	for(auto x:mp)w1+=x.second==2;
	if(n-w<=n/2-w1||n-w==2){printf("%d",n/2-sum);}
	else printf("%d",w1-sum);
	return 0;
}
