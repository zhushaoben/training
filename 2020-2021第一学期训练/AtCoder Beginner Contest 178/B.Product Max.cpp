#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%lld",max(1ll*b*c,max(1ll*b*d,max(1ll*a*c,1ll*a*d))));
	return 0;
}
