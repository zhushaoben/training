#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
const int N=2e5+5;
int Pow[N];
int main(){
	int n;scanf("%d",&n);
	if(n==1)return puts("10"),0;
	Pow[0]=1;for(int i=1;i<n;i++)Pow[i]=10ll*Pow[i-1]%mo;
	for(int i=1;i<n-1;i++){
		printf("%d ",(810ll*(n-i-1)+2ll*900)%mo*Pow[n-i-2]%mo);
	}
	printf("180 10\n");
	return 0;
}
