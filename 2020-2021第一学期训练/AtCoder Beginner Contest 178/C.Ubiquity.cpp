#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
int main(){
	long long a=1,b=0,c=0,d=0;int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		d=(b+c+d*10)%mo;
		b=(b*9+a)%mo;
		c=(c*9+a)%mo;
		a=a*8%mo;
	}
	printf("%d",d);
	return 0;
}
