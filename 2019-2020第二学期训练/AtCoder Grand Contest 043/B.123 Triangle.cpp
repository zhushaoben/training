#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[100][100];
int main(){
	int n;scanf("%d%s",&n,s);
	for(int i=1;i<=n;i++)a[1][i]=s[i-1]-'0';
	for(int i=2;i<=n;i++)for(int j=1;j<=n-i+1;j++)a[i][j]=abs(a[i-1][j]-a[i-1][j+1]);
	printf("%d",a[n][1]);
	return 0;
}
