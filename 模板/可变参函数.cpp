#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdarg.h>//����ͷ�ļ� 
using namespace std;
//����ĺ���<stdarg.h>�ṩ���� 
//typedef char *  va_list;//ָ�� 
//#define _ADDRESSOF(n)   ( &reinterpret_cast<const char &>(n) ) //ȡn�ĵ�ַ��תΪchar* 
//#define _INTSIZEOF(n)  (((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1) )) //��sizeof(n)����ȡ��sizeof(int)��������,Ŀ����Ϊ�˵�ַ����,���ҷ������ҵ�����*2�Ŷ���,������ϲ���*2 
//#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) ) //���һλ�ĵ�ַ����ap�� 
//#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) ) //ȡ��ap��ֵ������apָ����һ��λ��
//#define va_end(ap)      ( ap = (va_list)0 )  //�ÿ�ap 
int Max(int n,...){
    va_list arg_ptr;//ָ��
    va_start(arg_ptr, n);//���һλ�ĵ�ַ����arg_ptr�� 
	int ans = 0;
    for(int i=0; i < n; ++i){
        int temp = va_arg(arg_ptr,int);//ȡ��arg_ptr��ֵ������arg_ptrָ����һ��λ��
        ans=max(ans,temp);
    }
    va_end(arg_ptr);//�ÿ�arg_ptr
    return ans;
}
int main(){
	return 0;
}
