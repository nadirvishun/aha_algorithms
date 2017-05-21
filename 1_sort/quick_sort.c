/**
 * 快速排序
 */
#include <stdio.h>
int a[101],n;//定义全局变量，在子函数中有使用
/**
 * 排序算法
 * @param left  [description]
 * @param right [description]
 */
void quicksort(int left,int right){
	int i,j,t,temp;
	if(left>right){
		return;
	}
	temp=a[left];//基准
	i=left;
	j=right;
	while(i!=j){
		//先从右向左找
		while(a[j]>=temp && i<j){
			j--;
		}
		//再从左向右找
		while(a[i]<=temp && i<j){
			i++;
		}
		//交换两者位置
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	//将基准与ij相等的地方交换（归位）
	a[left]=a[i];
	a[i]=temp;
	//递归继续处理
	quicksort(left,i-1);
	quicksort(i+1,right);
}
int main()
{
	int i,j;
	printf("please input total number:");
	//输入个数
	scanf("%d",&n);
	//赋值
	for(i=1;i<=n;i++){
		printf("please input number:");
		scanf("%d",&a[i]);
	}
	//排序
	quicksort(1,n);
	//输出结果
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	getchar();getchar();
	return 0;
}
