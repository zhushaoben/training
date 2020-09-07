#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int a,b,c,k,k1=0;scanf("%d%d%d%d",&a,&b,&c,&k);
	while(b<=a)b<<=1,k1++;
	while(c<=b)c<<=1,k1++;
	if(k1<=k)puts("Yes");
	else puts("No");
	return 0;
}

