#include<bits/stdc++.h>
using namespace std;
void work(){
	int x,y,a,b;scanf("%d%d%d%d",&x,&y,&a,&b);
	if(x>y)swap(x,y);if(2*a<b)b=2*a;
	printf("%lld\n",1ll*(y-x)*a+1ll*x*b);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
