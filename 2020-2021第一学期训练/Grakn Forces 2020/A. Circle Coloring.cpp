#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N],b[N],c[N],p[N];
void work(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	for(int i=0;i<n;i++)scanf("%d",c+i);
	p[0]=a[0];
	for(int i=1;i<n;i++){
		if(a[i]==p[i-1])p[i]=b[i];
		else p[i]=a[i];
	}
	if(a[n-1]!=p[n-2]&&a[n-1]!=p[0])p[n-1]=a[n-1];
	else if(b[n-1]!=p[n-2]&&b[n-1]!=p[0])p[n-1]=b[n-1];
	else p[n-1]=c[n-1];
	for(int i=0;i<n;i++)printf("%d ",p[i]);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
