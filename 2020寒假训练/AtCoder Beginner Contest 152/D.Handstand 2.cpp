#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL ans=0;int n;
int calc(int l,int r){
	if(l==0)return 0;
	int w=0,i,d,fi=n,la=n%10;
	while(fi/10)fi/=10;
	if(l==r&&n>=10)w++;
	for(i=2,d=100;d<=n;d*=10,i++)w+=d/100;
	if(fi>l)w+=d/100;
	else if(fi==l){
		w+=(n-fi*d/10)/10+(la>=r);
	}
	return w;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x=i;while(x/10)x/=10;
		ans+=calc(i%10,x);
	}
	printf("%lld\n",ans);
	return 0;
}
