#include<bits/stdc++.h>
using namespace std;
int w[1005];
void work(){
	int n,a,d,mi=1e9,num=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&d);
		w[i]=99/a+1;w[i]=(w[i]-1)*d;
		mi=min(mi,w[i]);
	}
	for(int i=0;i<n;i++)if(mi==w[i])num++;
	double ans=0.5*num/n+1.0*(n-num)/n;
	printf("%.10lf\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
