#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int num[N];
int main(){
	int l=0,x,n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x),num[x]++;
		if(x==l)
			while(num[++l]);
		printf("%d\n",l);
	}
	return 0;
}
