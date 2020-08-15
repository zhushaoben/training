#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
void work(){
	int n,k,s=0;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i),s+=(a[i]==k);
	if(n==1&&a[1]==k){puts("yes");return;}
	if(!s){puts("no");return;}
	for(int i=1;i<=n;i++){
		int s=0;if(a[i]>=k)for(int j=i-1;j;j--){
			if(a[j]<k)s++;
			if(s<=(i-j)/2){puts("yes");return;}
			if(a[j]>=k)break;
		}
	}
	for(int i=1;i*2<=n;i++)swap(a[i],a[n-i+1]);
	for(int i=1;i<=n;i++){
		int s=0;if(a[i]>=k)for(int j=i-1;j;j--){
			if(a[j]<k)s++;
			if(s<=(i-j)/2){puts("yes");return;}
			if(a[j]>=k)break;
		}
	}
	puts("no");
} 
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
