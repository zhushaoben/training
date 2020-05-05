#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,k;scanf("%d%d%d",&a,&b,&k);
	printf("%lld\n",1ll*(a-b)*(k/2)+((k&1)?a:0));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
