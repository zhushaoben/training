#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n);double ans=0;
	for(int i=1;i<=n;i++)ans+=1.0/i;
	printf("%.12lf",ans);
	return 0;
} 
