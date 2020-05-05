#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int main(){
	scanf("%s",s);
	int a=0,b=1e9,c=0,d=0,l=strlen(s),x;
	for(l--;~l;l--){
		x=s[l]-'0';
		c=min(a+x,b+x+1);
		d=min(a+10-x,b+10-x-1);
		a=c,b=d;
	}
	printf("%d",min(a,b+1));
	return 0;
}
