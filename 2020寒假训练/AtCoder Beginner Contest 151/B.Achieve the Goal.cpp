#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,m,sum=0,x;scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<n;i++)scanf("%d",&x),sum+=x;
	sum=n*m-sum;
	printf("%d",sum>k?-1:max(0,sum));
	return 0;
}
