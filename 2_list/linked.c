/**
* 单向链表（无头结点）
* 链表头指针式一定要有的，但还有个叫头结点的东西：
* 带头结点的好处是插入删除不需要额外对第一个结点进行判断，统一了操作，但需要用二维指针来实现（不太懂）
* 参考：
* http://blog.csdn.net/lzm18064126848/article/details/50819574
* http://bbs.csdn.net/topics/390281682
* 与书中的不同：
* 1、增加插入第一个结点位置时的判定（因为没有头结点，需要额外判定）
* 2、增加删除结点
* 3、增加释放动态空间
* todo:
* 1、封装成函数
* 2、用头结点方式实现
*/
#include <stdio.h>
#include <stdlib.h>

//结点结构体
struct node{
    int data;//数据
    struct node *next;//指向下个结点
};

int main(){
    struct node *head,*p,*q,*t,*f;
    int i,n,a;
    printf("%s","please input node number:");
    scanf("%d",&n);
    head=NULL;//头指针初始为空
    printf("%s","please input number order by asc:");
    for(i=1;i<=n;i++){
        scanf("%d",&a);//数据为整数
        p=(struct node *)malloc(sizeof(struct node));
        p->data=a;
        p->next=NULL;
        if(head==NULL){//如果是第一个结点
            head=p;//将头指针指向这个结点
        }else{//否则的话
            q->next=p;//将上一个结点的后继指针指向当前结点
        }
        //这里自己感觉挺绕的，如果是php的变量来理解，感觉q被p代替了，q原有的值没有了，但这里q是指针，所以原有的q指向的内容还存在：
        //头指针->结点1->结点2（当前q指向）->结点3（新增的，目前是p），执行q=p后变成
        //头指针->结点1->结点2（目前没有指向这个的，要想访问只能从头直至开始向后访问）->结点3（目前p，q都指向这个结点）
        q=p;//指针q同样指向这个结点，方便下次继续指向
    }

    //插入结点（前方要求输入从小到大的，此时插入的数也需按照顺序排序）
    printf("%s","please insert a number:");
    scanf("%d",&a);
    t=head;
    while(t!=NULL){
        //如果第一个结点都大于输入的，那需要替代第一个结点，书中只考虑插入中间和末尾的情况，没有考虑插入首位的情况
        if(t->data > a){
            p=(struct node *)malloc(sizeof(struct node));
            p->data=a;
            p->next=t;//p的下个结点指向当前t
            head=p;//head指向p
            break;
        }
        //如果当前结点是最后一个结点，或当前结点的下个结点的值大于当前阶段，则插入
        if(t->next==NULL || t->next->data >a){
            p=(struct node *)malloc(sizeof(struct node));
            p->data=a;
            p->next=t->next;//p的下个结点指向当前t的下结点
            t->next=p;//当前t的下个结点指向p
            break;
        }
        t=t->next;
    }

    //输出所有数据
    t=head;
    printf("%s","current nodes：");
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;//继续向下寻找
    }
    //删除结点(目前是根据值删除，只删除第一个符合的)
    printf("\n%s","please delete a number:");
    scanf("%d",&a);
    t=head;
    while(t!=NULL){
        if(t->next==NULL){
            printf("%s\n","no this delete number");
            break;
        }
        if(t->data == a){//此时只能是第一个结点才会出现的情况
            head=t->next;//head指向t下个结点
            free(t);//释放掉
            break;
        }
        if(t->next->data == a){
            if(t->next->next==NULL){//如果t->next是尾结点
                f=t->next;//f指向尾结点
                free(f);//释放掉尾结点
                t->next=NULL;//当前t的下个结点置为null
                break;
            }else{//如果t->next是中间的结点
                f=t->next;
                t->next=t->next->next;
                free(f);
                break;
            }
        }
        t=t->next;//继续循环
    }

    //输出所有数据
    t=head;
    printf("%s","current nodes：");
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;//继续向下寻找
    }
    //释放空间
    f=head;
    while(f!=NULL){
        t=f->next;//先用一个临时变量来存储下一个
        free(f);//释放当前的
        f=t;//再将临时变量赋值给f
    }

    getchar();
    getchar();
    return 0;
}