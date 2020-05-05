#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int n,m,sum=0,k=0;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i),sum+=a[i];
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++){
		if(a[i]*4*m<sum)break;
		k++;
	}
	if(k>=m)puts("Yes");
	else puts("No");
	return 0;
}
