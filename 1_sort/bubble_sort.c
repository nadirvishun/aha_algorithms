/**
 * 冒泡排序
 */
#include <stdio.h>
struct student
{
	char name[21];
	char score;
};
int main()
{
	struct student a[100],t;
	int i,j,n,flag;
	printf("please input total number:");
	//输入个数
	scanf("%d",&n);
	//赋值
	for(i=1;i<=n;i++){
		printf("please input name and score:");
		scanf("%s %d",a[i].name,&a[i].score);
	}
	//排序(从高到低)
	for(i=1;i<=n-1;i++){
		flag=1;//优化
		for(j=1;j<=n-i;j++){
			if(a[j].score<a[j+1].score){
				t=a[j];a[j]=a[j+1];a[j+1]=t;
				flag=0;
			}
		}
		if(flag==1){
			break;
		}
	}
	//输出名字及分数
	for(i=1;i<=n;i++){
		printf("%s %d\n",a[i].name,a[i].score);
	}
	getchar();getchar();
	return 0;
}