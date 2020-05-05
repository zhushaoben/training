#include<bits/stdc++.h>
using namespace std;
const int N=5000;
double w[N],s[N];
double C(int n,int m){
	double ans=1;
	for(int i=n-m+1;i<=n;i++){
		ans*=(double)i/(i-n+m);
	}
	return ans;
}
double Pow(double a,int b){
	double ans=1;
	while(b){
		if(b&1)ans*=a;
		a*=a,b>>=1;
	}
	return ans;
}
int main(){
	int n,k;long double p,fp,ans=0,w2=1,w1=1;scanf("%d%d%Lf",&n,&k,&p),p=1-p,fp=1-p;
	for(int i=0;i<k;i++)w2*=p;
	for(int i=k;i<N;i++){
		w[i]=C(i-1,k-1)*w2*w1,w1*=fp;
		s[i]=s[i-1]+w[i];
		ans+=w[i]*Pow(s[i-1],n-1)*n;
	}
	printf("%.10Lf",1-ans);
	return 0;
} 
