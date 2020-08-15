#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int c[N];
int main(){
	int n;scanf("%d",&n);
	double mi=1;
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		if(c[i]>i)return puts("-1"),0;
		mi=min(mi,(double)c[i]/i);
	}
	printf("%.10lf\n",mi);
	return 0;
}
