/*
kmp
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn],b[maxn],c[maxn*3],d[maxn*3];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	for(int i=0;i<n;i++)c[i]=a[i]^a[(i+1)%n],c[i+n*2]=c[i+n]=b[i]^b[(i+1)%n];
	int j;d[0]=c[n]=j=-1;
	for(int i=0;i<3*n;d[++i]=++j)while(j>=0&&c[i]!=c[j])j=d[j];
	for(int i=0;i<n;i++){
		if(d[n*3-i]==n)printf("%d %d\n",i,a[i]^b[0]);
	}
	return 0;
} 
