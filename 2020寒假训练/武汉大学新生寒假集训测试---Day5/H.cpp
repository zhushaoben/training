#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
char a[maxn],b[maxn],c[maxn];
int f[maxn][maxn];
int work(){
	memset(f,0,sizeof(f));
	int la=strlen(a),lb=strlen(b),lc=strlen(c);
	f[0][0]=1;
	if(la+lb!=lc)return puts("No"),0;
	for(int i=0;i<=la;i++){
		for(int j=0;j<=lb;j++){
			if(a[i]==c[i+j])f[i+1][j]|=f[i][j];
			if(b[j]==c[i+j])f[i][j+1]|=f[i][j];
		}
	}
	if(f[la][lb])puts("Yes");
	else puts("No");
	return 0;
}
int main(){
	while(~scanf("%s%s%s",a,b,c))work();
	return 0;
}
