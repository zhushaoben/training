#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
int work(){
	int n,w,p;scanf("%d",&n);
	long double ans=-1,w1;int ans1=0,fl=0,fl1=-1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w,&p);
		if(!p)if(w>fl1)fl=i;
		if((w1=(long double)w/p)>ans+eps)ans=w1,ans1=i;
	}
	printf("%d\n",fl?fl:ans1);
	return 0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
