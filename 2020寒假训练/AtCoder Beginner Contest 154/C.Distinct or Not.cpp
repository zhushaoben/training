#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n);
	for(int i=0;i<n;i++)if(a[i]==a[i+1])return puts("NO"),0;
	puts("YES");
	return 0;
}
