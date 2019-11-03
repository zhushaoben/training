#include<bits/stdc++.h>
using namespace std;
#define maxn 300000
int a[maxn+5],ans[maxn+5];
int main(){
	int n,x;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&x),a[x]++;
	sort(a+1,a+n+1,greater<int>());a[0]=maxn*2;
	int remain=0,l=n;
	for(int i=n;i;i--){
		l=min(l,i);
		do{
			if(a[l]==a[l-1])l--;
			if(remain>=i-l+1){
				int x=min(remain/(i-l+1),a[l-1]-a[l]);
				remain-=x*(i-l+1),a[l]+=x;
			}
		}while(a[l]==a[l-1]);
		remain+=(ans[i]=a[l]);
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
} 
