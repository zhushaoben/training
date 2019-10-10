#include<bits/stdc++.h>
using namespace std;
multiset<int> S;
int a[1<<18|3],t;
int main(){
//	freopen("1.in","r",stdin);
	int n,n1,s=1,x;scanf("%d",&n),n1=1<<n;
	for(int i=1;i<=n1;i++)scanf("%d",&x),S.insert(x);
	auto X=S.end();X--;
	a[t++]=(*X),S.erase(X);
	for(int i=0;i<n;i++){
		for(int i=t-1,j=a[i];~i;i--,j=a[i]){
			auto k=S.lower_bound(j);
			if (k==S.begin()){puts("No");return 0;}
			k--;a[t++]=*k,S.erase(k); 
		}
		s*=2;
	}
	puts("Yes");
	return 0;
} 

