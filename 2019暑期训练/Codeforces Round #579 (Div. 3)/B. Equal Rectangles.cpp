#include<bits/stdc++.h>
using namespace std;
#define maxn 500
int a[maxn];
void work(){
	int n;scanf("%d",&n),n*=4;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}sort(a,a+n);
	int n1=n>>1,tmp=a[0]*a[n-1];
	bool fl=1;
	for(int i=1;i<n1;i++){
		if((i&1)&&(a[i]!=a[i-1]||a[n-i-1]!=a[n-i])){
			fl=0;break;
		}
		if(a[i]*a[n-i-1]!=tmp){
			fl=0;break;
		}
	}
	if(fl)puts("YES");
	else puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
