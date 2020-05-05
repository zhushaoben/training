#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x,now=100;scanf("%lld",&x);
	for(int i=1;;i++){
		now+=now/100;
		if(now>=x)return printf("%d\n",i),0;
	}
	return 0;
}
