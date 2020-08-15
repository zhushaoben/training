#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
int main(){
	int n,d,x;
	while(~scanf("%d%d",&n,&d)){
		double ans=0;
		for(int i=0;i<n;i++)scanf("%d",&x),ans+=sin(PI*x/180);
		printf("%.3lf\n",ans*d*d/2);
	}
	return 0;
}
