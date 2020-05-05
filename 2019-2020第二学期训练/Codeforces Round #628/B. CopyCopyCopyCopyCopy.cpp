#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
void work(){
	int n,ans=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);a[n]=0;
	for(int i=0;i<n;i++)if(a[i]!=a[i+1])ans++;
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
