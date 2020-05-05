#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n);
	while(n){
		if(n%10==7)return puts("Yes"),0;
		n/=10;
	}
	puts("No");
	return 0;
} 
