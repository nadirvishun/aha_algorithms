/**
 * 队列
 */
#include <stdio.h>
#include <string.h>
//简单的方法
// int main(){
// 	int data[100]={6,3,1,7,5,8,9,2,4},head,tail;
// 	head=0;
// 	tail=9;
// 	while(head<tail){
// 		//打印第一个
// 		printf("%d",data[head]);
// 		//头部后移，将第二个赋值给尾部
// 		head++;
// 		data[tail]=data[head];
// 		//尾部再后移
// 		tail++;
// 		//同时头部后移
// 		head++;
// 	}
// 	getchar();getchar();
// 	return 0;
// }

//另一种方式,用结构体
int main(){
	struct queue{
		int data[100];
		int head;
		int tail;
	};
	//直接初始化赋值，否则数组赋值有点麻烦，书中是让用户输入
	struct queue q={
		{6,3,1,7,5,8,9,2,4},
		0,
		9
	};

	//不在初始化时赋值,相当于复制一个数组
	// struct queue q;
	// int tmp[100]={6,3,1,7,5,8,9,2,4};
	// memcpy(q.data,tmp,sizeof(int)*9);//需要引入string.h头文件
	// q.head=0;
	// q.tail=9;

	while(q.head < q.tail){
		printf("%d",q.data[q.head]);
		q.head++;

		q.data[q.tail]=q.data[q.head];
		q.tail++;
		q.head++;
	}

	getchar();
	return 0;
}