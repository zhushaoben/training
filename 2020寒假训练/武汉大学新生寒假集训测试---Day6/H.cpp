#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n);
	if((n-2)%3)printf("%d %d %d\n",1,1,n-2);
	else printf("%d %d %d\n",1,2,n-3);
	return 0;
}
