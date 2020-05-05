#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,sum=0,x;scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)scanf("%d",&x),sum+=x;
	printf("%d",max(-1,m-sum));
	return 0;
}
