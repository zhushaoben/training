#include<bits/stdc++.h>
using namespace std;
const int N=5005;
typedef long long LL;
int d[N];
int main(){
	int k,q,n,n1,m,x,w;LL sum;scanf("%d%d",&k,&q);
	for(int i=0;i<k;i++)scanf("%d",d+i);
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&n,&x,&m),n--;
		x%=m,sum=w=0,n1=n/k;//w is the number of j that satisfy (aj mod m)=(aj+1 mod m)
		for(int j=0;j<k;j++){
			sum+=d[j]%m;
			if(d[j]%m==0)w+=n1;
		}
		sum*=n1,n1=n,n%=k;
		for(int j=0;j<n;j++){
			if(d[j]%m==0)w++;
			sum+=d[j]%m;
		}
		sum+=x;
		printf("%d\n",n1-sum/m-w);//sum/m is the number of j that satisfy (aj mod m)>(aj+1 mod m)
	}
	return 0;
}
