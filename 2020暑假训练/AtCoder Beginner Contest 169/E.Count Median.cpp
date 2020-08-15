#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int a[N],b[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i);
	sort(a,a+n),sort(b,b+n);
	printf("%d",(b[n/2]+b[(n-1)/2]-a[n/2]-a[(n-1)/2])/(n%2?2:1)+1);
	return 0;
}
