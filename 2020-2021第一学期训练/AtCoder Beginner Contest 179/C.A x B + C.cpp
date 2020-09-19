#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,n1,ans=0;scanf("%d",&n),n1=sqrt(--n);
	for(int i=1;i<=n1;i++)
		ans+=(n/i)-i+1;
	printf("%d",ans*2-n1);
	return 0;
} 
