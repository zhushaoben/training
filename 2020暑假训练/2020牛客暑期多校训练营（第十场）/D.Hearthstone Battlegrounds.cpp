#include<bits/stdc++.h>
using namespace std;
void work(){
	int a5=0,a1,a2,a3,a4,b1,b2,b3,b4,b5=0;
	scanf("%d%d%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&b1,&b2,&b3,&b4);
	while(a1+a2+a3+a4&&b1+b2+b3+b4){
		if(a3+a4)b5=0;
		while(a5&&b1+b2){
			if(b1)b3++,b1--;
			else b4++,b2--;
			a5=0;
		}
		if(a3){
			a3--,a5++;
			if(b3)b3--,b5++;
			else if(b4)b4--;
			else if(b1)b1--,b3++;
			else b4++,b2--;
		}
		else if(a1){
			a1--,a3++;
			if(b3)b3--,b5++;
			else if(b4)b4--;
			else if(b1)b1--,b3++;
			else b4++,b2--;
		}
		else if(a2){
			a2--,a4++;
			if(b3)b3--,b5++;
			else if(b4)b4--;
			else if(b1)b1--,b3++;
			else b4++,b2--;
		}
		else{
			a4--;
			if(b3)b3--,b5++;
			else if(b4)b4--;
			else if(b1)b1--,b3++;
			else b4++,b2--;
		}
	}
	if(b1+b2+b3+b4)puts("No");
	else if(!(a1+a2+a3+a4)&&a5<=b5)puts("No");
	else puts("Yes");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
