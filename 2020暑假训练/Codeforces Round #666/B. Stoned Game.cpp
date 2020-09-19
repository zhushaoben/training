#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,ma=0,sum=0,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),ma=max(ma,x),sum+=x;
	if(ma*2>sum||sum&1)puts("T");
	else puts("HL");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
