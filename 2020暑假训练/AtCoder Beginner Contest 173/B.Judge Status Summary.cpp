#include<bits/stdc++.h>
using namespace std;
char s[10];
int main(){
	int n,a=0,w=0,t=0,r=0;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		switch(s[0]){
			case 'A':a++;break;
			case 'T':t++;break;
			case 'W':w++;break;
			default:r++;
		}
	}
	printf("AC x %d\nWA x %d\nTLE x %d\nRE x %d",a,w,t,r);
	return 0;
}
