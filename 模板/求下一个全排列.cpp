#include<cstdio>
#include<algorithm>
using namespace std; 
void nextpermutation(int a[],int k){//��һ��ȫ���� 
	for(int i=k-2;i>=0;i--){
		if(a[i]<a[i+1]){//�ҵ����һ���ǽ����ֵ 
			int j;
			for(j=k-1;j>i;j--){
				if(a[i]<a[j])break;
			}
			a[i]^=a[j],a[j]^=a[i],a[i]^=a[j];//�����һ���ǽ������������һ���������������� 
			reverse(a+i+1,a+k);//�������������������,����Ϊ�ǽ���,���Է�תһ�¾����� 
			return;
		}
	}
}
int main(){
	return 0;
}
