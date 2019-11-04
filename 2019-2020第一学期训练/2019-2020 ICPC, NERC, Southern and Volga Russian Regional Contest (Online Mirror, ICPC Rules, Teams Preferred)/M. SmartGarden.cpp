#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n);
	if(n>50){puts("-1");return 0;}
	if(n==2){printf("1\n1 1\n1 2\n");return 0;}
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		printf("%d",n-2+(i==n));
		for(int j=1;j<=n;j++){
			if(j==i||j==i+1)continue;
			printf(" %d",j);
		}
		printf("\n1 %d\n",i);
	}
	return 0;
} 
