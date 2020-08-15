#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL calc(LL l,LL d,LL k){return (l+l+d*(k-1))*k/2;}
void work(){
	int n,w;scanf("%d",&n),w=n/2;
	printf("%lld\n",8ll*w*(w+1)*(2*w+1)/6);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
