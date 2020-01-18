#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
char a[maxn],b[maxn],c[maxn];
int f[maxn][maxn];
int work(){
	int la=strlen(a+1),lb=strlen(b+1),lc=strlen(c+1);
	if(la+lb!=lc)return puts("No"),0;
	f[0][0]=1;
	for(int i=1;i<=lc;i++){
		for(int j=0;j<=i;j++){
			f[i][j]=(j?f[i-1][j-1]&&a[j]==c[i]:0)|(i-j?f[i-1][j]&&b[i-j]==c[i]:0);
		}
	}
	if(f[lc][la])puts("Yes");
	else puts("No");
	return 0;
}
int main(){
	while(~scanf("%s%s%s",a+1,b+1,c+1))work();
	return 0;
}
