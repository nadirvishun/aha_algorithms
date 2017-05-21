/**
 * 简单桶排序
 */
#include <stdio.h>
int main()
{
	int a[11],i,j,t;//需要注意个数为11，因为下标从0开始
	//初始值
	for(i=0;i<=10;i++){
		a[i]=0;
	}
	//循环输入5个数值不超过10的数字
	for(i=1;i<=5;i++){
		printf("please input number:");
		scanf("%d",&t);
		a[t]++;//计数
	}
	for(i=0;i<=10;i++){
		for(j=1;j<=a[i];j++){
			printf("%d ",i);
		}
	}
	getchar();getchar();
	return 0;
}
