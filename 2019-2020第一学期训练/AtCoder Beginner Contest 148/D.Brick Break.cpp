#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,now=1;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),now+=(x==now);
	printf("%d",now!=1?n-now+1:-1);
	return 0;
}
