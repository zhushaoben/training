#include<bits/stdc++.h>
using namespace std;
char s[200];
int f[200][4],b[4]={1,9,81,729};
int c(int n,int m){
	if(m>n)return 0;
	int ans=1;
	for(int i=1;i<=m;i++)ans*=n-i+1;
	for(int i=1;i<=m;i++)ans/=i;
	return ans;
}
int main(){
	int k;scanf("%s%d",s,&k);
	int l=strlen(s);
	f[l][0]=1;
	for(int i=l-1;~i;i--){
		int x=s[i]-'0';
		f[i][0]=1;
		for(int j=1;j<=k;j++){
			if(x==0)f[i][j]=f[i+1][j];
			else f[i][j]=f[i+1][j-1]+(x-1)*c(l-i-1,j-1)*b[j-1]+c(l-i-1,j)*b[j];
		}
	}
	printf("%d",f[0][k]);
	return 0;
}
