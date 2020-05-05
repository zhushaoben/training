#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x%2==0&&x%3&&x%5)return puts("DENIED"),0;
	}
	puts("APPROVED");
	return 0;
}
