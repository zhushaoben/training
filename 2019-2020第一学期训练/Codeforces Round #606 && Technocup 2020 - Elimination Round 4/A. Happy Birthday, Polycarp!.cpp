#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,w=1,ans=0;scanf("%d",&n);
	while(n>=w){
		ans+=min(9,n/w);
		w=w*10+1;
	}
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
