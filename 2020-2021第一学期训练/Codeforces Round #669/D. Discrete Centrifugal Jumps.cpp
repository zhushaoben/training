#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,inf=1e9;
int h[N],f[N],q1[N],t1,q2[N],t2;
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",h+i);
	q1[t1++]=q2[t2++]=1;
	for(int i=2;i<=n;i++){
		f[i]=1e9;
		while(t1&&h[q1[t1-1]]>=h[i])f[i]=min(f[i],f[q1[--t1]]+1);
		if(t1&&h[q1[t1]]!=h[i])f[i]=min(f[i],f[q1[t1-1]]+1);
		while(t2&&h[q2[t2-1]]<=h[i])f[i]=min(f[i],f[q2[--t2]]+1);
		if(t2&&h[q2[t2]]!=h[i])f[i]=min(f[i],f[q2[t2-1]]+1);
		q1[t1++]=q2[t2++]=i;
	}
	printf("%d",f[n]);
	return 0;
}
/*
7
1 3 5 1 5 3 4
0 1 2 1 2 2 3
*/
