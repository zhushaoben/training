#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int main(){
	int n,l=N,r=0,w=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=n;i;i--){
		scanf("%d",b+i);
		if(b[i]==a[i]){l=i;if(!r)r=i;}
	}
	for(int i=1;i<=n;i++)if(b[i]!=a[r]&&a[i]!=a[r])w++;
	if(w<r-l+1)return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=n;i++){
		if(l>r)break;
		if(b[i]!=a[r]&&a[i]!=a[r])swap(b[i],b[l++]);
	}
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}
