#include<bits/stdc++.h>
using namespace std;
int a[40],b[40];
void work(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	sort(a,a+n),sort(b,b+n);
	for(int i=0;i<k;i++)a[i]=max(a[i],b[n-i-1]);
	int ans=0;
	for(int i=0;i<n;i++)ans+=a[i];
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
