#include<bits/stdc++.h>
using namespace std;
int n,sum,x;
void work(){
	sum=0;for(int i=0;i<n;i++){
		scanf("%*lld.%d",&x);
		x=x%10;
		if(x>=5)sum+=10-x;
		else sum-=x;
	}
	printf("%.3lf\n",sum/1000.0);
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
}
