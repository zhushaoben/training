#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	if(n==1)return printf("%d",m/6*6+(m%6==4?2:(m%6==5)?4:0)),0;
	if(m<=2)return puts("0"),0;
	if(n==2&&(m==3||m==7))return printf("%d",1ll*n*m-2),0;
	if(n%2==0||m%2==0)return printf("%lld\n",1ll*n*m),0;
	else printf("%lld\n",1ll*n*m-1);
	return 0;
}
