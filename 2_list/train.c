/**
 * 纸牌游戏-小猫钓鱼
 * 用的book这个类似桶排序很巧妙啊：
 * 如果不用这样的话，要查找是否赢牌，需要先遍历查找位置，然后再依次收入手中
 * 但是如果用book的话，直接比较book[t]是否为1即能判定是否赢牌，但同样的也增加了桶置1置0等逻辑判定，但速度会快
 */
#include <stdio.h>
#include <string.h>

//定义队列结构体
struct queue{
    int data[1000];//存储牌
    int head;//存储队头
    int tail;//存储队尾
};
//定义栈结构体
struct stack{
    int data[10];//桌上的牌
    int top;//栈顶部
};
int main(){
    //初始化两位玩家和桌面
    struct queue q1,q2;
    struct stack s;
    int book[10];//桶排序
    int i,t;
    q1.head=0;
    q1.tail=0;
    q2.head=0;
    q2.tail=0;
    s.top=0;
    //初始化book
    for(i=1;i<=9;i++){
        book[i]=0;
    }

    //读入手牌
    printf("please input q1 card:");
    for(i=1;i<=6;i++){//q1
        scanf("%d",&q1.data[q1.tail]);//读入一个数到队尾
        q1.tail++;//然后依次向后移动
    }
    printf("please input q2 card:");
    for(i=1;i<=6;i++){//q2
        scanf("%d",&q2.data[q2.tail]);//读入一个数到队尾
        q2.tail++;//然后依次向后移动
    }

    while(q1.head<q1.tail && q2.head <q2.tail){
        //q1出牌
        t=q1.data[q1.head];
        //判定是否赢牌
        if(book[t]==0){//没有赢牌
            q1.head++;//q1牌出栈
            s.top++;//s.top从1开始
            s.data[s.top]=t;//桌面入站
            book[t]=1;//桶计数
        }else{//如果赢牌
            q1.head++;
            q1.data[q1.tail]=t;//将自己打出的牌先收回来
            q1.tail++;
            while(s.data[s.top]!=t){//依次回收桌上的牌
                book[s.data[s.top]]=0;//将回收过的牌的桶值变为0
                q1.data[q1.tail]=s.data[s.top];//依次放入队尾
                q1.tail++;
                s.top--;//这样才能依次回收
            }
            //当=t时
            book[s.data[s.top]]=0;
            q1.data[q1.tail]=s.data[s.top];//依次放入队尾
            q1.tail++;
            s.top--;
        }
        //由于下方还可能执行，所以这里先判定是否跳出
        if(q1.head==q1.tail){
            break;
        }
        //q2出牌
        t=q2.data[q2.head];
        //判定是否赢牌
        if(book[t]==0){//没有赢牌
            q2.head++;//q1牌出栈
            s.top++;
            s.data[s.top]=t;//桌面入站
            book[t]=1;//桶计数
        }else{//如果赢牌
            q2.head++;
            q2.data[q2.tail]=t;//将自己打出的牌先收回来
            q2.tail++;
            while(s.data[s.top]!=t){//依次回收桌上的牌
                book[s.data[s.top]]=0;//将回收过的牌的桶值变为0
                q2.data[q2.tail]=s.data[s.top];//依次放入队尾
                q2.tail++;
                s.top--;//这样才能依次回收
            }
            //当=t时
            book[s.data[s.top]]=0;
            q2.data[q2.tail]=s.data[s.top];//依次放入队尾
            q2.tail++;
            s.top--;
        }
    }
    //输出结果
    if(q2.head==q2.tail){
        printf("q1 win!\n");
        printf("q1 has cards:");
        for(i=q1.head;i<=q1.tail-1;i++){
            printf(" %d",q1.data[i]);
        }
    }else{
        printf("q2 win!\n");
        printf("q2 has cards:");
        for(i=q2.head;i<=q2.tail-1;i++){
            printf(" %d",q2.data[i]);
        }
    }
    // 桌面上的牌
    if(s.top>0){
        printf("\ndesk has cards:");
        for(i=1;i<=s.top;i++){
            printf(" %d",s.data[i]);
        }
    }else{
        printf("\n disk is empty!");
    }
    getchar();
    getchar();
    return 0;
}