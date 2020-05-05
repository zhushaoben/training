#include<bits/stdc++.h>
using namespace std;
const int N=18,inf=0x1f1f1f1f;
int a[N],b[N],f[1<<N][55];
//f[i][j] indicate the answer for Set i that the last number is less than j
int main(){
	int n,s;scanf("%d",&n),s=(1<<n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++)scanf("%d",b+i);
	memset(f,0x1f,sizeof(f));
	for(int i=0;i<=50;i++)f[0][i]=0;
	for(int i=1;i<s;i++){
		int w=0,w1=0;
		for(int j=0;j<n;j++)if(i&(1<<j))w++;
		for(int j=0;j<n;j++){
			if(!(i&(1<<j)))continue;
			if((w-j)&1)f[i][a[j]]=min(f[i][a[j]],f[i^(1<<j)][a[j]]+j-w1);
			else f[i][b[j]]=min(f[i][b[j]],f[i^(1<<j)][b[j]]+j-w1);
			w1++; 
		}
		for(int j=1;j<=50;j++)f[i][j]=min(f[i][j],f[i][j-1]);
	}
	printf("%d",f[s-1][50]==inf?-1:f[s-1][50]);
	return 0;
}
