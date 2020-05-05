#include<bits/stdc++.h>
using namespace std;
void work(int st,int n){
	if(n<=3){
		if(n==1)printf("%d",st);
		else if(n==2)printf("%d %d",st,st*2);
		else printf("%d %d %d",st,st,st*3);
		return;
	}
	for(int i=n-n/2;i;i--)printf("%d ",st);
	work(st*2,n/2);
}
int main(){
	int n;scanf("%d",&n);
	work(1,n);
	return 0;
}
