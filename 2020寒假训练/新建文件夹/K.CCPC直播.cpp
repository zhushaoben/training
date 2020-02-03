#include<bits/stdc++.h>
using namespace std;
char s[100];
void work(){
	int x,y;scanf("%d%s%d",&x,s,&y);
	printf("%3d|%-16s|%4d|",x,s,y);
	scanf("%s",s);
	if(s[1]=='u'){
		scanf("%d",&x);putchar('[');
		for(int i=0;i<x;i++)putchar('X');
		for(int i=0;i<10-x;i++)putchar(' ');
		puts("]");
	} 
	else if(s[0]=='F')puts("[    AC*   ]");
	else if(s[2])printf("[    %s   ]\n",s);
	else printf("[    %s    ]\n",s);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
} 
