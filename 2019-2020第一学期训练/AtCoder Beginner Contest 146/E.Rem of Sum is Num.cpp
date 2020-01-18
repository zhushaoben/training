#include<bits/stdc++.h>
using namespace std;
#define LL long long 
#define maxn 200005
LL s[maxn],ans;
map<int,int>mp;
int main(){
	int n,x,k;scanf("%d%d",&n,&k);
	mp[0]++;
	for(int i=1;i<=n;i++){
		scanf("%d",&x),s[i]=s[i-1]+x;
		if(i>=k)mp[(s[i-k]-i+k)%k]--;
		ans+=mp[(s[i]-i)%k]++;
	}
	printf("%lld",ans);
	return 0;
}
