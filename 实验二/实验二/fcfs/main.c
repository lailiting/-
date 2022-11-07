#include <stdio.h>
#include <stdlib.h>

typedef struct  data

{
    int hour;

    int min;

}time;

typedef struct node

{

    int id;//���̱��

    char name[20];//������

    time arrive;//�����������ʱ��

    int zx;//ִ��ʱ��

    time start;//��ʼִ��ʱ��

    time finish;//ִ�����ʱ��

    int zz;//��תʱ��=ִ�����ʱ��-�����������ʱ��

    float zzxs;//��Ȩ��תʱ��=��תʱ��/ִ��ʱ��

    struct node* next;

}linklist;

//��ʼ��
void init(linklist *head){
    head = (linklist *) malloc(sizeof(linklist));
    head->next = NULL;
}

//����
void input(linklist *head, int n){
    linklist *p, *q;
    int i = 0;
    q = head;
       printf("\nid ���� ��ʼʱ�� ִ��ʱ��\n");
    while(i < n){
        p = (linklist *)malloc(sizeof(linklist));
        scanf("%d %s %d:%d %d", &p->id, p->name, &p->arrive.hour, &p->arrive.min, &p->zx);
        p->start.hour = 0;
        p->start.min = 0;
        p->finish.hour = 0;
        p->finish.min = 0;
        p->zz = 0;
        p->zzxs = 0;
        p->next = NULL;
        q->next = p;
        q = p;
        i= i+1;
    }
}

//���̹���
void run(linklist *head, int n){
    int i = 0, j = 0, allzz = 0;
    float allzzxs = 0;
    linklist *p, *pre;
    p = head->next;
    while(i < n && p!= NULL){
        if(i == 0){
            p->start.hour = p->arrive.hour;
            p->start.min = p->arrive.min;
            //���㿪ʼʱ�� ����ʱ��
            if(p->start.min + p->zx > 60){
                    p->finish.hour = p->start.hour + 1;
                    p->finish.min = p->start.min + p->zx - 60;
            }else{
                    p->finish.hour = p->start.hour;
                    p->finish.min = p->start.min + p->zx;
            }
        }else{
            if(p->arrive.hour*60 + p->arrive.min < pre->finish.hour*60 + pre->finish.min){
                p->start.hour = pre->finish.hour;
                p->start.min = pre->finish.min;
                //���㿪ʼʱ�� ����ʱ��
                if(p->start.min + p->zx > 60){
                    p->finish.hour = p->start.hour + 1;
                    p->finish.min = p->start.min + p->zx - 60;
                }else{
                    p->finish.hour = p->start.hour;
                    p->finish.min = p->start.min + p->zx;
                }
            }else{
                p->start.hour = p->arrive.hour;
                p->start.min = p->arrive.min;
                //���㿪ʼʱ�� ����ʱ��
                if(p->start.min + p->zx > 60){
                    p->finish.hour = p->start.hour + 1;
                    p->finish.min = p->start.min + p->zx -60;
                }else{
                    p->finish.hour = p->start.hour;
                    p->finish.min = p->start.min + p->zx;
                }
            }
        }
        pre = p;
        p = p->next;
        i = i+1;
    }

    //�����Ȩ
    i = 0;
    p = head->next;
    while(i < n){
        p->zz = p->finish.hour*60 + p->finish.min - p->arrive.hour*60 - p->arrive.min;
        p->zzxs = (float) p->zz/ (float) p->zx;
        p = p->next;
        i++;
        j++;
    }
    i = 0;
    p = head->next;
    while(i < n){
        allzz = allzz + p->zz;
        allzzxs = allzzxs + p->zzxs;
        p = p->next;
        i++;
    }
    printf("\nϵͳ��תʱ��:%d  ϵͳ��Ȩ��תʱ��%.2f", allzz/j, allzzxs/j);
}



//���ݽ���ʱ������
void sort(linklist *head){
    linklist *pre, *p, *q;
    //pre�����б�ĵ�һ����� p��¼λ�� qΪ����ĵ�һ�����
    q = head->next->next;
    head->next->next = NULL;
    p = q;
    while(p){
        q = p->next;//�ȼ�¼Ҫ����ĺ�һ�����
        pre = head;
        //�ҵ������λ��
        while(pre->next && pre->next->arrive.hour*60 + pre->next->arrive.min < p->arrive.hour*60 + p->arrive.min){
            pre = pre->next;
        }

        //����������Ľ��
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

void print(linklist *head, int n){
    linklist *p;
    int i = 0;
    p = head->next;
    printf("\n����Ϊid  ����   ����ʱ��  ִ��ʱ��  ��ʼʱ��   ����ʱ��    ��תʱ��  ��Ȩ��תʱ�� :\n");
    while(i < n && p!=NULL){
        printf("%d          %s      %d:%d        %d      %d:%d      %d:%d       %d        %.2f\n", p->id, p->name, p->arrive.hour, p->arrive.min, p->zx, p->start.hour, p->start.min, p->finish.hour, p->finish.min, p->zz, p->zzxs);
        p = p->next;
        i = i+1;
    }
}

int main()
{
    system("color f0");
    linklist head;
    int n, i;
    printf("��������� 1(���̵���) 0(��������):");
    scanf("%d", & i);
    while(i == 1){
        printf("��������̵�����:");
        scanf("%d", &n);
        init(&head);
        input(&head, n);
        sort(&head);
        printf("\nģ����̵���FCFS�㷨��ִ�н��:\n");
        run(&head, n);
        print(&head,n);
        printf("��������� 1(���̵���) 0(��������):");
        scanf("%d", & i);
    }
    printf("\n��������");
    return 0;
}
