/**
 * 栈
 * 检测输入的字符串是否为回文字符串（正序读倒序读都是同样的）
 */
#include <stdio.h>
#include <string.h>

int main(){
    char a[101],s[101];
    int i,len,mid,next,top,is;
    
    gets(a);//读入字符串
    len=strlen(a);//与php一样
    mid=len/2-1;

    //处理mid之前的
    for(i=0;i<=mid;i++){
        s[i]=a[i];
    }

    //判定奇偶
    if(len%2==0){
        next=mid+1;
    }else{
        next=mid+2;
    }

    //匹配mid之后的
    top=mid;
    is=1;
    for(i=next;i<len;i++){
        if(a[i]!=s[top]){
            is=0;
            break;
        }
            top--;
    }
    //由于最后top又--了，所以这里是-1,直接用另一个参数is来判定好了
    // if(top==-1){
    if(is==1){
        printf("YES!");
    }else{
        printf("NO!");
    }
    getchar();
    return 0;
}