#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int num[N];
int main(){
	int n,h;scanf("%d",&n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&h);
		if(h+i<n)num[h+i]++;
		if(i-h>1)ans+=num[i-h];
	}
	printf("%lld",ans);
	return 0;
}
