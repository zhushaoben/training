#include<bits/stdc++.h>
using namespace std;
#define maxn 105
char s[maxn];
void work(){
	int a,b,c,d,x;a=d=b=c=0;scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i]>='a')c++;
		else if(s[i]>='A')b++;
		else a++;
	}
	if(a)d++;if(b)d++;if(c)d++;
	if(d==3){puts(s);return;}
	else if(d==1){
		for(int i=0;i<2;i++){
			if(!a)a++,s[i]='1';
			else if(!b)b++,s[i]='A';
			else c++,s[i]='a';
		}
		puts(s);return;
	}
	for(int i=0;s[i];i++){
		if(s[i]>='a')x=c;
		else if(s[i]>='A')x=b;
		else x=a;
		if(x>=2){
			if(!a)a++,s[i]='1';
			else if(!b)b++,s[i]='A';
			else c++,s[i]='a';
			break;
		}
	}
	puts(s);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
