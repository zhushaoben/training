#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL a,b;int d=0;scanf("%lld%lld",&a,&b);
	if(a<b)swap(a,b);
	while(1){
		if(a%b==0||a>=b<<1)break;
		a-=b,swap(a,b),d^=1;
	}
	if(d)puts("lose");
	else puts("win");
	return 0;
} 
