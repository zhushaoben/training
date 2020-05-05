#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
char s[N],t[N];
int work(int i,char s[]){
	if(i>=2&&s[i]=='a'&&s[i-1]=='r'&&s[i-2]=='o')return 1;
	if(i>=3&&s[i]=='a'&&s[i-1]=='d'&&s[i-2]=='u'&&s[i-3]=='m')return 2;
	if(i>=8&&s[i]=='o'&&s[i-1]=='u'&&s[i-2]=='d'&&s[i-3]=='u'&&s[i-4]=='l'
	&&s[i-5]=='a'&&s[i-6]=='w'&&s[i-7]=='a'&&s[i-8]=='z')return 3;
	return 0;
}
void work(){
	int n,h;scanf("%d%d%s%s",&n,&h,s,t);
	int h1=h,h2=h;
	for(int i=0;i<n;i++){
		if(work(i,t)==3){puts("Hinnjaku");return;}
		if(work(i,s)==3){puts("Wryyyyy");return;}
		if(work(i,t)==2)h1--;
		if(work(i,s)==1)h2--;
		if(!h1){
			if(!h2){puts("Kono Dio da");return;}
			puts("Hinnjaku");return;
		}
		if(!h2){puts("Wryyyyy");return;}
	}
	if(h1==h2){puts("Kono Dio da");return;}
	if(h1>h2){puts("Wryyyyy");return;}
	puts("Hinnjaku");
}
int main(){
	int T=1;
	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
