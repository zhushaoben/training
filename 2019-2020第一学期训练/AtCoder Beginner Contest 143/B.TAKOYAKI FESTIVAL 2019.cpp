#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum=0,ans=0,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),sum+=x,ans-=x*x;
	printf("%d",(ans+sum*sum)/2);
	return 0;
}
