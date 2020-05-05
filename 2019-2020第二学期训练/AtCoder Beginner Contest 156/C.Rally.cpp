#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,sum=0,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),sum+=x,ans+=x*x;
	int a=sum/n,b=a+1;
	printf("%d",ans+min(n*a*a-2*sum*a,n*b*b-2*sum*b));
	return 0;
}
