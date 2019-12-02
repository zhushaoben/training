#include<cstdio>
int main(){
	char *a="#include<cstdio>%cint main(){%c%cchar *a=%c%s%c;%c%cprintf(a,10,10,9,34,a,34,10,9,10);%c}";
	printf(a,10,10,9,34,a,34,10,9,10);
} 
