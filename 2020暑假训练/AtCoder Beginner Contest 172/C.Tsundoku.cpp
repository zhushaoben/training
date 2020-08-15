#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int main(){
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	int ans=0,num=0,w=0,l,r;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<m;i++)scanf("%d",b+i);
	for(r=0;r<n&&w+a[r]<=k;r++)w+=a[r];
	for(l=0;l<m&&w+b[l]<=k;l++)w+=b[l];
	ans=r+l;
	for(r=r-1;r>=0;r--){
		w-=a[r];
		while(l<m&&w+b[l]<=k)w+=b[l++];
		ans=max(ans,r+l);
	}
	printf("%d",ans);
	return 0;
}
