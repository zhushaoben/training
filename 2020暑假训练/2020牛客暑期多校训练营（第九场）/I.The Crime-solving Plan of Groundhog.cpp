#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],num[10];
void work(){
	int n,x,w,si=0;scanf("%d",&n);
	for(int i=0;i<10;i++)num[i]=0;
	for(int i=0;i<n;i++)scanf("%d",&x),num[x]++;
	for(int i=1;i<10;i++)if(num[i]){w=i,num[i]--;break;}
	for(int i=1;i<10;i++)if(num[i]){a[si++]=i,num[i]--;break;}
	for(int i=0;i<10;i++)
		for(int j=0;j<num[i];j++)a[si++]=i;
	x=0;
	for(int i=n-2;~i;i--){
		a[i]=a[i]*w+x;
		x=a[i]/10,a[i]%=10;
	}
	if(x)putchar(x+'0');
	for(int i=0;i<n-1;i++)putchar(a[i]+'0');
}
int main(){
	int t;scanf("%d",&t);
	t--,work();
	while(t--)puts(""),work();
	return 0;
}
