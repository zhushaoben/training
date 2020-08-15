#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
void work(){
	int n,x;scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n,greater<int>());
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum<1ll*x*(i+1)){printf("%d\n",i);return;}
	}
	printf("%d\n",n);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
