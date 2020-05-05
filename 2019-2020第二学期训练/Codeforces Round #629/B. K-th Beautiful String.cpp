#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,k,a,b;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		if(k<=i-1){a=n-i+1,b=n-k+1;break;}
		else k-=i-1;
	}
	for(int i=1;i<=n;i++){
		if(i==a||i==b)putchar('b');
		else putchar('a');
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
