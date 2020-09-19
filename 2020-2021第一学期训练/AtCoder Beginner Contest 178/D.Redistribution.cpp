#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,mo=1e9+7;
int f[N];
int main(){
	int s;scanf("%d",&s);
	f[0]=1;
	for(int i=3;i<=s;i++)
		for(int j=i-3;~j;j--)(f[i]+=f[j])%=mo;
	printf("%d",f[s]);
	return 0;
}
