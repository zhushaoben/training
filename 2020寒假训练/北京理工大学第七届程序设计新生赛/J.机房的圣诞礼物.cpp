#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL calc(LL l,LL r){
	return (r+l)*(r-l+1)/2;
}
LL work(int x){
	if(x<=1)return x;
	return calc(x/2+1,x)+work((x/2+2)/2-1);
}
int main(){
	int n;scanf("%d",&n);
	printf("%lld",work(n));
	return 0;
}
