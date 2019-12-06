#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==0&&b==0&&d==c+1){
		puts("YES");
		while(c--)printf("3 2 ");
		return puts("3"),0;
	}
	if(c==0&&d==0&&a==b+1){
		puts("YES");
		while(b--)printf("0 1 ");
		return puts("0"),0;
	}
	if(b<a||c<d||abs(a+c-b-d)>1)return puts("NO"),0;
	puts("YES");
	if(a+c>b+d){
		while(a)a--,b--,printf("0 1 ");
		while(d)d--,c--,printf("2 3 ");
		while(b)c--,b--,printf("2 1 ");
		puts("2");
	}
	else{
		while(d)d--,c--,printf("3 2 ");
		while(a)a--,b--,printf("1 0 ");
		while(c)b--,c--,printf("1 2 ");
		if(b)puts("1");
	}
	return 0;
}
