#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,pre=0,x;long long sum=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(pre>x){sum+=pre-x,x=pre;}
		pre=x;
	}
	printf("%lld",sum);
	return 0;
}
