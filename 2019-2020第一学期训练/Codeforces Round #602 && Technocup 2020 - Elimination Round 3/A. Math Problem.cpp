#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,l,r,maxl=0,minr=1e9;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&l,&r),minr=min(minr,r),maxl=max(maxl,l);
	printf("%d\n",max(0,maxl-minr));
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
