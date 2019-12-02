#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdarg.h>//所需头文件 
using namespace std;
//下面的宏在<stdarg.h>提供的有 
//typedef char *  va_list;//指针 
//#define _ADDRESSOF(n)   ( &reinterpret_cast<const char &>(n) ) //取n的地址并转为char* 
//#define _INTSIZEOF(n)  (((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1) )) //将sizeof(n)向上取至sizeof(int)的整数倍,目的是为了地址对齐,但我发现在我电脑上*2才对齐,评测机上不用*2 
//#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) ) //求第一位的地址存在ap中 
//#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) ) //取出ap的值，并将ap指向下一个位置
//#define va_end(ap)      ( ap = (va_list)0 )  //置空ap 
int Max(int n,...){
    va_list arg_ptr;//指针
    va_start(arg_ptr, n);//求第一位的地址存在arg_ptr中 
	int ans = 0;
    for(int i=0; i < n; ++i){
        int temp = va_arg(arg_ptr,int);//取出arg_ptr的值，并将arg_ptr指向下一个位置
        ans=max(ans,temp);
    }
    va_end(arg_ptr);//置空arg_ptr
    return ans;
}
int main(){
	return 0;
}
