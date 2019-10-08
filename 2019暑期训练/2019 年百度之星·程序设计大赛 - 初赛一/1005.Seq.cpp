#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define LL long long
void work(){
	LL n;scanf("%I64d",&n);
	if(n%6==0||n%6==2)printf("%I64d\n",n/2);
	if(n%6==1)printf("%I64d\n",(n/6)*4+1);
	if(n%6==3||n%6==5)printf("%I64d\n",n/6);
	if(n%6==4)printf("%I64d\n",n-1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
