#include<bits/stdc++.h>
using namespace std;
bool check(int n,int m,int k){
	if(n>m)swap(n,m);
	if(n%(k+1)==0)return 1;
	if(n<k+1||k==1)return (n+m)&1;
	int w=n/(k+1);
	return ((n+m)&1)^(w&1);
}
void work(){
	int q,k,m,n;scanf("%d%d",&q,&k);
	for(int i=0;i<q;i++){
		scanf("%d%d",&n,&m);
		if(check(n,m,k))puts("Alice");
		else puts("Bob");
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
