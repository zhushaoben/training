#include<bits/stdc++.h>
using namespace std;
#define LL long long
int a[30];
void work(){
	LL x,ans=1,ans1=1,ans2=0,w=1;int i;scanf("%lld",&x);
	for(i=2;x;i++)a[i-2]=x%i,x/=i;
	sort(a,a+(----i),greater<int>());a[i]=30;
	for(int j=0;j<i;j++){
		if(a[j]==a[j+1])w++;
		else w=1;ans1*=w;
		ans*=i-max(0,a[j]-1)-j;
	}
	ans/=ans1;i--;
	if(a[i]==0&&(a[i]=30)&&(ans2=ans1=w=1))for(int j=0;j<i;j++){
		if(a[j]==a[j+1])w++;
		else w=1;ans1*=w;
		ans2*=i-max(0,a[j]-1)-j;
	}
	printf("%lld\n",ans-ans2/ans1-1);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
