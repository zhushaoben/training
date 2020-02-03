#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
double f[maxn],w[maxn];
int main(){
	int l;double p,q,q1=1;
	while(~scanf("%d%lf%lf",&l,&p,&q)){
		q1=1;
		for(int i=1;i<=l;i++){
			q1*=(1-q);
			w[i]=w[i-1]+2*q1;
		}
		for(int i=1;i<=l;i++){
			f[i]=(f[i-1]+1)+p*w[l-i+1]/(1-p);
		}
		printf("%.10lf\n",f[l]);
	}
	return 0;
}
