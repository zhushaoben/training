#include<bits/stdc++.h>
using namespace std;
int a[15],b[15];
int main(){
	for(int i=0;i<14;i++)scanf("%d",a+i);
	long long ans=0;
	for(int i=0;i<14;i++){
		for(int j=0;j<14;j++)b[j]=a[j];
		int x=b[i];long long w=0;b[i]=0;
		for(int j=0;j<14;j++){
			if(i!=j)b[j]+=ceil(((x-(j+14-i)%14)+1)/14.0);
			else b[j]=x/14;
			if(b[j]%2==0)w+=b[j];
		}
		ans=max(ans,w);
	}
	printf("%lld",ans);
	return 0;
}
