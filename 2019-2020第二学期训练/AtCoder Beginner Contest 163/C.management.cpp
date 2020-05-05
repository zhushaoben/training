#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	int n,x;scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d",&x),a[x]++;
	for(int i=1;i<=n;i++)printf("%d\n",a[i]);
	return 0;
}
