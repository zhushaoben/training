#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int a[maxn+5];
int work(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		if(i>a[i])return printf("%d\n",max(i-1,a[i])),0;
	}
	return printf("%d\n",n),0;
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
