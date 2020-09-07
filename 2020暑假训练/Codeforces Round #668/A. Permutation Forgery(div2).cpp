#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=n;i;i--)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}
