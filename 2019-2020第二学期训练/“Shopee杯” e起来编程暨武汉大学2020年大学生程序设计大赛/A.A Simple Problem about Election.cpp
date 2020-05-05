#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
void work(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	int x=a[0];sort(a,a+n),a[n]=1e9+5;
	int y=upper_bound(a,a+n+1,x-1)-a,z=upper_bound(a,a+n+1,x)-a,num=n-z+y;
	if(num>=m-1)printf("%d\n",n-z+1);
	else printf("%d\n",n-z+m-num);
}
int main(){
	int T=1;
	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
