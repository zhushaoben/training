#include<bits/stdc++.h>
using namespace std;
int n;
void work(){
	bool fl=1;int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(sqrt(x)*sqrt(x)!=x)fl=0;
	}
	if(fl)puts("Yes");
	else puts("No");
}
int main(){
	while(~scanf("%d",&n))work();
	return 0;
} 
