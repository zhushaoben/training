#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int a[maxn],b[maxn];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	for(int i=n-1;~i;i--){
		if(a[i]|b[i]){
			if(!a[i])puts("0/1");
			else if(!b[i])puts("1/0");
			else{
				int w=gcd(a[i],b[i]);
				printf("%d/%d\n",a[i]/w,b[i]/w);
			}
			return;
		}
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
