#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=9;i++){
		if(n%i==0&&(n/i)<=9){puts("Yes");return 0;}
	}
	puts("No");
	return 0;
}
