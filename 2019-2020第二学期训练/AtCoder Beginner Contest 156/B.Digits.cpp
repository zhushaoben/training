#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,ans=0;scanf("%d%d",&n,&k);
	while(n)n/=k,ans++;
	printf("%d",max(1,ans));
	return 0;
}
