#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,s;scanf("%d%d%d",&n,&k,&s);
	if(s==1e9){
		for(int i=0;i<k;i++)printf("%d ",s);
		for(int i=k;i<n;i++)printf("%d ",s-1);
		return 0;
	}
	for(int i=0;i<k;i++)printf("%d ",s);
	for(int i=k;i<n;i++)printf("%d ",s+1);
	return 0;
} 
