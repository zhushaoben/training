#include<bits/stdc++.h>
using namespace std;
long long cal(int n,int x,int y){
	int num=min(n-x+1,min(x,min(y,n-y+1)))-1;
	long long fi=(1ll*n*n-1ll*(n-2)*(n-2)*(n-2>0?1:0)),en=fi-7*(num-1),ans=(fi+en)*num/2;
	n-=num*2,x-=num,y-=num;
	if(x==n)return ans+(n-y+1);
	ans+=n-1;if(y==1)return ans+(n-x+1);
	ans+=n-1;if(x==1)return ans+y;
	ans+=n-1;return ans+x;
} 
int main(){
	int n,x,y;while(~scanf("%d%d%d",&n,&x,&y))
	printf("%lld\n",cal(n,x,y)); 
	return 0;
} 
