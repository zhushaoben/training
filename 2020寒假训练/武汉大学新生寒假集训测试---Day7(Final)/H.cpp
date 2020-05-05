#include<bits/stdc++.h>
using namespace std;
#define LL long long
map<LL,int>mp;
map<pair<LL,LL>,int>mp1;
int main(){
	int n,a,b;LL x,y,y1,ans=0;scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;i++){
		scanf("%*d%lld%lld",&x,&y);
		y1=y,y-=a*x;
		ans+=mp[y]-mp1[make_pair(x,y1)];
		mp[y]++,mp1[make_pair(x,y1)]++;
	}
	printf("%lld",ans*2);
	return 0;
}
