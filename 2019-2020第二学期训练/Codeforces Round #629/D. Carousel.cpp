#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
void work(){
	int n;scanf("%d",&n);
	bool fl=0,fl1=0;
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<n;i++){
		if(a[i]==a[(i+1)%n])fl=1;
		if(a[i]!=a[(i+1)%n])fl1=1;
	}
	if(!fl1){
		puts("1");
		for(int i=0;i<n;i++)printf("1 ");
		puts("");return;
	}
	if(fl||n%2==0){
		puts("2");bool g=0;
		for(int i=0;i<n;i++){
			printf("%d ",((i&1)^g)+1);
			if((n&1)&&a[i]==a[(i+1)%n])g=1;
		}
		puts("");return;
	}
	printf("3\n3 ");
	for(int i=1;i<n;i++)printf("%d ",(i&1)+1);
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
