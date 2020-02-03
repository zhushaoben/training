#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
void work(){
	mp.clear();
	int n,s,k,x;scanf("%d%d%d",&n,&s,&k);
	for(int i=0;i<k;i++)scanf("%d",&x),mp[x]=1;
	for(int i=0;;i++)if((s-i>0&&!mp[s-i])||(s+i<=n&&!mp[s+i])){printf("%d\n",i);return;}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
