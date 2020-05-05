#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,ma=1<<17;scanf("%d",&k);
	printf("3 3\n");
	printf("%d %d %d\n",ma*2-1,ma*2-1,ma);
	printf("%d %d %d\n",ma*2-1,k,ma*2-1);
	printf("%d %d %d\n",ma,ma*2-1,k);
	return 0;
}
