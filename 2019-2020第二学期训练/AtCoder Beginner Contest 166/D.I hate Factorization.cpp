#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x;scanf("%lld",&x);
	for(int i=1;i<150;i++)
		for(int j=-150;j<150;j++)
			if(1ll*i*i*i*i*i-1ll*j*j*j*j*j==x)return printf("%d %d",i,j),0;
	return 0;
}
