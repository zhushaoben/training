#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],ans[N],si;
void work(){
	int n;scanf("%d",&n);si=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]+=a[i-1];
	for(int i=3;i<=n;i+=3){
		if(a[i]-a[i-3]>=2)ans[si++]=1,ans[si++]=1;
		else ans[si++]=0,ans[si++]=0;
	}
	if(n%3==2){
		if(a[n]-a[n-2]>=2)ans[si++]=1,ans[si++]=1;
		else ans[si++]=0;
	}
	printf("%d\n",si);
	for(int i=0;i<si;i++)printf("%d ",ans[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
