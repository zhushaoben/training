#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,w=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		if(a==b&&(++w)>=3)return puts("Yes"),0;
		if(a!=b)w=0;
	}
	puts("No");
	return 0;
}
