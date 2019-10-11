#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn];
void work(){
	int n,m,k,remain=0;
	scanf("%d%d%d",&n,&m,&k);remain=m;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n-1;i++){
		if(a[i]+remain<a[i+1]-k){
			puts("NO");return;
		}
		remain+=a[i]-max(0,a[i+1]-k);
	}
	puts("YES");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
