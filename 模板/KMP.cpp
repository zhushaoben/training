#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool v[1234];
inline void Next(const char a[],int next[],int l){//aΪ�ַ�����lΪ�ַ������� ,nextΪǰ׺�������ͬǰ��׺����
	for(int i=1,k=0;i<l;i++){//i��ʾ��ǰ���㵽��i��ǰ׺��k��ʾ��һ�������ͬǰ��׺���� 
		while(k>0&&a[i]!=a[k]){//��һ�������ͬǰ��׺���Ȳ��Ҳ���� 
			k=next[k-1];
		}
		if(a[i]==a[k])k++;//��Ⱦ�Ϊ��һ�������ͬǰ��׺����+1������Ⱦ���0�� 
		next[i]=k;
	}
}
inline void kmp(const char a[],const char b[],int next[],int l1,int l2){//aΪ����,bΪҪ���ҵĴ���l1��a�ĳ���,l2��b�ĳ��� 
	for(int i=0,q=0;i<l1;i++){
		while(q>0&&b[q]!=a[i])q=next[q-1];//�������ȣ���b���Ƶ���һ����Ȼ��ƥ��ɹ�λ�ã��൱��b���ıȽ�λ��ǰ�Ƶ�next[q-1]+1,������Ϊ�Ǵ�0��ʼ���ԱȽ�λ��ǰ�Ƶ�next[q-1]�� 
		if(b[q]==a[i])q++;//��Ⱦ����Ƚ� 
		if(q==l2){//�ɹ�ƥ�� 
			v[i]=1;//iΪ�ɹ�ƥ���aĩβ��λ�ã����Խ����������� 
		}
	}
}
char a[]="ABCDABAB",b[]="ABCDABD";
int next[124];
int main(){
	int l1=strlen(a),l2=strlen(b);
	Next(b,next,l2);
	kmp(a,b,next,l1,l2);
	return 0;
}
