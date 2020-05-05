#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn],ans[maxn],si;
int main(){
	int n,ma=0,ma1=0;long long sum=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);sum+=a[i];
		if(a[i]>ma)ma1=ma,ma=a[i];
		else if(a[i]>ma1)ma1=a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==ma){
			if(sum-ma-ma1==ma1)ans[si++]=i+1;
		}
		else{
			if(sum-ma-a[i]==ma)ans[si++]=i+1;
		}
	}
	printf("%d\n",si);
	for(int i=0;i<si;i++)printf("%d ",ans[i]);
	return 0;
}
