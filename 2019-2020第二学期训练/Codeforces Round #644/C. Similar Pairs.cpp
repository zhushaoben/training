#include<bits/stdc++.h>
using namespace std;
int a[100];
void work(){
	int n,sum=0;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i),sum+=a[i]&1;
	if(sum%2==0){puts("YES");return;}
	sort(a,a+n);
	for(int i=1;i<n;i++)if(a[i]==a[i-1]+1){puts("YES");return;}
	puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
