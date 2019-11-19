#include<bits/stdc++.h>
using namespace std;
#define maxn 100000
int a[maxn+5];
void work(){
	int n,x,ans=0,fl=1;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++){
		scanf("%d",&x),x-=a[i];
		if(x<0){fl=0;continue;}
		if(x)if(ans==x||ans==0)ans=x;else fl=0;
		else if(ans)ans=-1;
	}
	if(fl)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
