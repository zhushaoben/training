#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	long long ans=n*1e9,sum,now;
	for(int q=1;;q++){
		sum=0,now=1;
		for(int i=0;i<n;i++){
			if(sum>=ans){sum=1e18;break;}
			sum+=abs(a[i]-now);
			now*=q;
		}
		if(sum>=ans)break;
		ans=sum;
	}
	printf("%lld\n",ans);
	return 0;
}
