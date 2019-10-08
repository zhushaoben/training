#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 20
LL randint(LL l,LL r){
	return l+1ll*rand()*rand()*rand()%(r-l+1);
}
int a[maxn+5];
void work(){
	int n=randint(1,maxn),k=randint(1,n);
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;i++)a[i]=i-1;
	for(int i=1;i<=n;i++){
		swap(a[randint(1,n)],a[randint(1,n)]);
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
}
int main(){
	srand(time(NULL));
	int t=randint(1,1);
//	printf("%d\n",t);
	while(t--)work();
	return 0;
}
