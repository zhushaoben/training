#include<bits/stdc++.h>
using namespace std;
void work(){
	long long b,x;scanf("%lld%lld",&b,&x);
	if(b%x==1)puts("T");
	else puts("F");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
