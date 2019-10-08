#include<bits/stdc++.h>
using namespace std;
#define maxn 4000005
int a[maxn];
int main(){
	int n,i;scanf("%d%d",&n,&i);
	i=(i*8/n);
	i=i>30?1<<30:(1<<i);
	for(int j=0;j<n;j++){
		scanf("%d",a+j);
	}sort(a,a+n);
	int l=0,r=0,ans=1<<30,num=1;
	while(r<n){
		while(num>i){l++;if(a[l]!=a[l-1])num--;}
		ans=min(ans,n-(r-l+1));
		r++;if(a[r]!=a[r-1])num++;
	}
	printf("%d",ans);
	return 0;
} 
