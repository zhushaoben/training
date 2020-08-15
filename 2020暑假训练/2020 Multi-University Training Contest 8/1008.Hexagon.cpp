#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,l;scanf("%d",&n);
	if(n%2==1)l=3,printf("123534645156261312");
	else l=2,printf("245612");
	for(;l<n;l+=2){
		printf("12");
		for(int i=0;i<l;i++)printf("42");
		printf("4");
		for(int i=0;i<l;i++)printf("53");
		printf("5");
		for(int i=0;i<l;i++)printf("64");
		printf("6");
		for(int i=0;i<l;i++)printf("15");
		printf("1");
		for(int i=0;i<l;i++)printf("26");
		printf("2");
		for(int i=1;i<l;i++)printf("31");
		printf("2");
	}
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
