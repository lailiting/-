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

    int good;          //���ȼ�

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
    printf("\nid ����  ���ȼ� ��ʼʱ�� ִ��ʱ��\n");
    while(i < n){
        p = (linklist *)malloc(sizeof(linklist));
        scanf("%d %s %d %d:%d %d", &p->id, p->name, &p->good, &p->arrive.hour, &p->arrive.min, &p->zx);
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



void print(linklist *head, int n){
    linklist *p;
    int i = 0;
    p = head->next;
    printf("\nid\t���� ���ȼ�\t����ʱ�� \tִ��ʱ�� ��ʼʱ�� \t ����ʱ�� \t ��תʱ�� ��Ȩ��תʱ�� :\n");
    while(i < n && p!=NULL){
        printf("%d\t%s\t%d \t %d:%d\t\t   %d  \t  %d:%d \t\t %d:%d  \t        %d\t   %.2f\n", p->id, p->name, p->good, p->arrive.hour, p->arrive.min, p->zx, p->start.hour, p->start.min, p->finish.hour, p->finish.min, p->zz, p->zzxs);
        p = p->next;
        i = i+1;
    }
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

void good(linklist *head, linklist *p){
    //����ƶ�
    linklist *q, *pre;
    pre = head;
    q = pre->next;
    //���ѽ������̵���һ����㿪ʼ��
    while(q != p){
        if(q->good < p->good){
            if(p->next == NULL){
                pre->next = p;
                p->next = q;
                q->next->next = NULL;
            }else{
                pre->next = p;
            q->next = p->next;
            p->next = q;
            }
            break;
        }
        pre = q;
        q = q->next;
    }
}



//�������ȼ���������
void goodsort(linklist *q){
    linklist *p, *pre;
    p = q->next;
    while(p){
        if(p->arrive.hour*60 + p->arrive.min < q->finish.hour*60 + q->finish.min){
            pre = p->next;
            good(q, p);
            p = pre;
        }else{
            p = p->next;
        }
    }
}

//���ȼ������㷨
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
            if(p->start.min + p->zx >= 60){
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
                if(p->start.min + p->zx >= 60){
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
                if(p->start.min + p->zx >= 60){
                    p->finish.hour = p->start.hour + 1;
                    p->finish.min = p->start.min + p->zx -60;
                }else{
                    p->finish.hour = p->start.hour;
                    p->finish.min = p->start.min + p->zx;
                }
            }
        }
        pre = p;

        //��һ�������Ҫ�������ȼ����½�������
        goodsort(pre);
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
    print(head, n);
    printf("\nϵͳ��תʱ��:%d  \nϵͳ��Ȩ��תʱ��%.2f\n", allzz/j, allzzxs/j);
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
        printf("��������� 1(���̵���) 0(��������):");
        scanf("%d", & i);
    }
    printf("\n��������");
    return 0;
}
