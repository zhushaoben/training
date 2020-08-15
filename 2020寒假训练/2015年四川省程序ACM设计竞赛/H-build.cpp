#include<bits/stdc++.h>
using namespace std;
#define LL long long
long long randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
const int N=50;
int a[N+5];
void work(){
	int n=randint(1,N),m1=(0,N-10),m2=(0,N-m1);
	printf("%d %d %d\n",n,m1,m2);
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=1000;i++){
		int l=randint(1,n),r=randint(1,n);
		swap(a[l],a[r]);
	}
	for(int i=0;i<m1;i++){
		int l=randint(1,n),r=randint(l,n),mi=N;
		for(int j=l;j<=r;j++)mi=min(mi,a[j]);
		printf("%d %d %d\n",l,r,mi);
	}
	for(int i=0;i<m2;i++){
		int l=randint(1,n),r=randint(l,n),ma=0;
		for(int j=l;j<=r;j++)ma=max(ma,a[j]);
		printf("%d %d %d\n",l,r,ma);
	}
}
int main(){
	srand(time(NULL));
	int t=randint(1,1);
//	printf("%d\n",t);
	while(t--)work();
	return 0;
}
