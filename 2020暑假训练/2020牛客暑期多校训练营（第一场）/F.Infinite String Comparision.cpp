#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char a[N],b[N];
int main(){
	while(~scanf("%s%s",a,b)){
		int x=0,y=0;
		for(int i=0,j=0;;){
			if(a[i]>b[j]){puts(">");break;}
			if(a[i]<b[j]){puts("<");break;}
			i++;j++;
			if(!a[i])x++,i=0;
			if(!b[j])y++,j=0;
			if(x>1&&y>1){puts("=");break;}
		}
	}
	return 0;
}
