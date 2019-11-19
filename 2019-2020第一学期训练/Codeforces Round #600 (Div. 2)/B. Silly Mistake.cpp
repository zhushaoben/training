#include<bits/stdc++.h>
using namespace std;
int a[1000005],ans[100000],si;
int main(){
	int n,x,num=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x>0)if(num++,a[x]>0||a[x]<-ans[si])return puts("-1"),0;else a[x]=1;
		else if(num--,x=-x,a[x]>0)a[x]=-i-1;else return puts("-1"),0;
		if(num==0)ans[++si]=i+1;
	}
	if(num)return puts("-1"),0;
	printf("%d\n",si);
	for(int i=1;i<=si;i++)printf("%d ",ans[i]-ans[i-1]);
	return 0;
} 
