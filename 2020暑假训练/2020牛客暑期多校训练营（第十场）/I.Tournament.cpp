#include<bits/stdc++.h>
using namespace std;
int st[10000],ed[10000];
void work(){
	int n,n1,t=0,ans=0,mi=1e9,ans1=0;scanf("%d",&n),n1=(n)/2;
	for(int i=1;i<=n;i++){
		n1=i;t=0;
		for(int i=1;i<=n1;i++){
			st[i]=t;
			t+=i-1;
		}
		for(int j=n1+1;j<=n;j++)st[j]=t++;
		ed[1]=t;
		for(int i=2;i<=n1;i++){t+=n-n1;ed[i]=t;}
		for(int i=n1+1;i<=n;i++){t+=n-i;ed[i]=t;}
		ans=0;for(int i=1;i<=n;i++)ans+=ed[i]-st[i];
		printf("%8d %8d\n",i,ans);
		if(mi>ans)mi=ans,ans1=i;
	}
	
	printf("%d %d\n",mi,ans1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
