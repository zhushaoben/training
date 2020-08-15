#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char s[2000];
void P(int l,int r){
	int l1=-1,r1=-1,num,sum=0;
	for(int i=l;i<=r;i++){
		if(s[i]=='['){l1=i,num=s[i-1]-'0';break;}
	}
	for(int i=l;i<=r;i++){
		if(s[i]=='[')sum++;
		else if(s[i]==']'){
			sum--;
			if(!sum){r1=i;break;}
		}
	}
	if(l1==-1){
		for(int i=l;i<=r;i++)putchar(s[i]);
		return;
	}
	for(int i=l;i<l1-1;i++)putchar(s[i]);
	for(int i=0;i<num;i++)P(l1+1,r1-1);
	P(r1+1,r);
}
void work(){
	int l=strlen(s);
	P(0,l-1);
	puts("");
}
int main(){
	while(~scanf("%s",s))work();
	return 0;
} 
