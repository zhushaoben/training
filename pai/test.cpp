#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c[N];
void work(){
	int n,l,k,k1;scanf("%d%d%d",&n,&l,&k),k1=l-k+1;
	for(int i=0;i<n;i++)scanf("%d",c+i);
	sort(c,c+n);
	long long ans1=0,ans2=0;
	if(1){
		int w=n-l+1,w1;
		for(int i=k-1;w&&i<n;i++){
			if(i%l==k-1)w1=min(w,l-k+1);
			else w1=1;
			ans1+=1ll*c[n-i-1]*w1;
			w-=w1;
		}
	}
	if(1){
		int w=n-l+1,w1;
		for(int i=k1-1;w&&i<n;i++){
			if(i%l==k1-1)w1=min(w,l-k1+1);
			else w1=1;
			ans2+=1ll*c[i]*w1;
			w-=w1;
		}
	}
	printf("%lld\n%lld\n",ans1,ans2);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
