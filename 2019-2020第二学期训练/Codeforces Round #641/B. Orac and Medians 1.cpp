#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],n,k,s,ma;
void work(){
	scanf("%d%d",&n,&k);s=0;ma=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),s+=(a[i]==k);
	if(n==1&&k==a[1]){puts("yes");return;}a[n+1]=0;
	for(int i=1;i<=n;i++){if(a[i-1]>=a[i]||a[i+1]>=a[i])ma=max(ma,a[i]);}
	if(s&&ma>=k)puts("yes");
	else puts("no");
} 
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
