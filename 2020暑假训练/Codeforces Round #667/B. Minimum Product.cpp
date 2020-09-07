#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void work(){
	int a,b,x,y,n;scanf("%d%d%d%d%d",&a,&b,&x,&y,&n);
	int a1=min(a-x,n),n1=n-a1,b1=min(b-y,n1);
	int b2=min(b-y,n),n2=n-b2,a2=min(a-x,n2);
	printf("%lld\n",min(1ll*(a-a1)*(b-b1),1ll*(a-a2)*(b-b2)));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
