#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,c,sum,a,b;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&c,&sum);
		a=sum/c,b=sum%c;
		printf("%d\n",a*a*(c-b)+(a+1)*(a+1)*b);
	}
	return 0;
} 
