#include<bits/stdc++.h>
using namespace std;
char s[1005];
void work(){
	int n,a,b,c,d,a1,b1,c1,d1,ma=0,mi=0;scanf("%d%d%d%d%d%s",&n,&a,&b,&c,&d,s),a1=a,b1=b,c1=c,d1=d;
	for(int i=0;s[i];i++){
		if(s[i]=='1'){
			if(c1+d1){
				if(c1)c1--,ma++;
				else d1--,c1++;
			}
			else if(a1+b1){
				if(a1)a1--,ma++;
				else b1--,a1++;
			}
		}
		else{
			if(c1+d1){if(d1)d1--,c1++;}
			else if(b1)b1--,a1++;
		}
	}
	a1=a,b1=b,c1=c,d1=d;
	for(int i=0;s[i];i++){
		if(s[i]=='1'){
			if(c1+d1){
				if(d1)d1--,c1++;
				else c1--,mi++;
			}
			else if(a1+b1){
				if(b1)b1--,a1++;
				else a1--,mi++;
			}
		}
		else{
			if(c1+d1){if(!c1&&d1)d1--,c1++;}
			else if(!a1&&b1)b1--,a1++;
		}
	}
	printf("%d %d\n",ma,mi);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
