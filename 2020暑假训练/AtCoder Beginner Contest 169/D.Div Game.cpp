#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[]={0,1,3,6,10,15,21,28,36,45,55};
int main(){
	LL n;scanf("%lld",&n);
	int ans=0;
	for(LL i=2;i*i<=n;i++){
		if(n%i==0){
			int w=0;
			while(n%i==0)w++,n/=i;
			for(int j=10;j;j--)if(w>=a[j]){ans+=j;break;}
		}
	}
	if(n>1)ans++;
	printf("%d",ans);
	return 0;
}
