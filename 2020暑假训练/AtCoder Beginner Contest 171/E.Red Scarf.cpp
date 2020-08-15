#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	int n,sum=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),sum^=a[i];
	for(int i=0;i<n;i++)printf("%d ",sum^a[i]);
	return 0;
}
