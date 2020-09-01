#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,a[N];
bool check(int x){
	int w=0;
	for(int i=0;i<n;i++)
		w+=(a[i]-1)/x;
	return w<=k;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	int l=1,r=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
