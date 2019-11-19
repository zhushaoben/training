/*
f[i] denote the answer for [1,i]
*/
#include<bits/stdc++.h>
using namespace std;
#define maxm 100000
struct Node{
	int x,s;
}a[100];
int f[maxm+5];
int main(){
	int n,m,x,s,w;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&s);a[i]={x,s};
		f[max(1,x-s)]++,f[min(m,x+s)+1]--;
	}
	for(int i=2;i<=m;i++)f[i]+=f[i-1];
	for(int i=1;i<=m;i++){
		if(f[i]){f[i]=f[i-1];continue;}
		f[i]=f[i-1]+1;
		for(int j=0;j<n;j++){
			if(a[j].x<i)w=max(0,i-a[j].x-a[j].s),f[i]=min(f[i],f[max(0,a[j].x-a[j].s-w-1)]+w);
		}
	}
	printf("%d",f[m]);
	return 0;
}
