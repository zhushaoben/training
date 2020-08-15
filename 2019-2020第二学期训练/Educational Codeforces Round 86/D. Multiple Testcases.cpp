#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int c[N],num[N],m[N];
int main(){
	int n,k,ans=0;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",m+i),num[m[i]]++;
	for(int i=1;i<=k;i++)scanf("%d",c+i);
	for(int i=k;i;i--)num[i]+=num[i+1],ans=max(ans,(num[i]-1)/c[i]+1);
	sort(m,m+n);
	printf("%d\n",ans);
	for(int i=0;i<ans;i++){
		printf("%d ",n/ans+(i<(n%ans)));
		for(int j=i;j<n;j+=ans)printf("%d ",m[j]);
		puts("");
	}
	return 0;
} 
