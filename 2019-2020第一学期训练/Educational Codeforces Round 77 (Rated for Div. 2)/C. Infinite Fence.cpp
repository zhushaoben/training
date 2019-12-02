#include<bits/stdc++.h>
using namespace std;
void work(){
	int r,b,k;scanf("%d%d%d",&r,&b,&k);
	if(r>b)swap(r,b);
	int g=__gcd(r,b);r/=g,b/=g;
	if(b>=1ll*(k-1)*r+2)puts("REBEL");
	else puts("OBEY");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
