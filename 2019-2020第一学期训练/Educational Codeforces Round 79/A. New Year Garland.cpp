#include<bits/stdc++.h>
using namespace std;
void work(){
	int a,b,c,sum=0,ma;
	scanf("%d%d%d",&a,&b,&c),sum=a+b+c,ma=max(a,max(b,c));
	if(ma>sum-ma+1)puts("No");
	else puts("Yes");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	
	return 0;
}
