#include<bits/stdc++.h>
using namespace std;
char s[50],t[50];
int a[300],b[300];long long f[100],f1[100];
void work(){
	int n;scanf("%s%s%d",s,t,&n);
	for(int i=0;s[i];i++)a[s[i]]++;
	for(int i=0;t[i];i++)b[t[i]]++;
	f[1]=1,f1[2]=1;
	for(int i=3;i<=n;i++)f[i]=f[i-1]+f[i-2],f1[i]=f1[i-1]+f1[i-2];
	for(int i=1;i<200;i++){
		if(a[i]*f[n]+b[i]*f1[n]){
			printf("%c: %lld\n",i,a[i]*f[n]+b[i]*f1[n]);
		}
	}
}
int main(){
	int T=1;
//	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
