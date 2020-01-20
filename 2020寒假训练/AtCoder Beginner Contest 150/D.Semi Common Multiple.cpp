#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
int main(){
	int n,m,x,w=0,w1;scanf("%d%d%d",&n,&m,&x),x/=2;
	while(x%2==0)x>>=1,w++,m/=2;
	LL lcm=x;
	for(int i=1;i<n;i++){
		scanf("%d",&x),x/=2,w1=0;
		while(x%2==0)x>>=1,w1++;
		lcm=lcm*x/gcd(lcm,x);
		if(lcm>m||w1!=w)return puts("0"),0;
	}
	printf("%d",((m/lcm)+1)/2);
	return 0;
}
