#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL calc(int x){return 1ll*x*(x+1)/2;}
int main(){
	int n;scanf("%d",&n);
	printf("%lld",calc(n)-calc(n/3)*3-calc(n/5)*5+calc(n/15)*15);
	return 0;
}
