#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXID 20
#define MAXNAME 30


//����ѧ���ṹ��
typedef struct{
    char stuId[MAXID];
    char stuName[MAXNAME];
    struct stuMessage *next;
}stuMessage;

//���нṹ��
typedef struct{
    stuMessage *front;
    stuMessage *rear;
}linkQueue;

//��ʼ������
void init(linkQueue *lq){
    lq->front = lq->rear = NULL;
}


//��Ӳ���
void addStu(linkQueue *lq){
    stuMessage *stu;
    stu = (stuMessage *)malloc(sizeof(stuMessage));
    printf("������ѧ��ѧ��:");
    scanf("%s",stu->stuId);
    printf("\n������ѧ������:");
    scanf("%s",stu->stuName);
    stu->next = NULL;
    if(lq->front == NULL){
        lq->front = lq->rear = stu;
    }else{
        lq->rear->next = stu;
        lq->rear = stu;

    }
    printf("\n��ӳɹ�");
}

//����ѧ������Ԫ��
void printStu(linkQueue *lq){
    stuMessage *p;
    if(lq->front==NULL && lq->rear==NULL){
        printf("����Ϊ��");
        exit(1);
    }
    p = lq->front;
    printf("ѧ����Ϣ��:\n");
    while(p != NULL){
        printf("ѧ����ѧ��Ϊ:%s��ѧ��������Ϊ:%s\n",p->stuId, p->stuName);
        p = p->next;
    }
    printf("�������");
}

//ɾ������
void delStu(linkQueue *lq){
    stuMessage *p;
    if(lq->front==NULL && lq->rear == NULL){
        printf("����Ϊ�ղ���ɾ��");
        exit;
    }
    p = lq->front;
    lq->front = lq->front->next;
    free(p);
    printf("ɾ��ѧ����Ϣ�ɹ�\n");
}

//����ѧ����Ϣ
void findStu(linkQueue *lq){
    stuMessage *p;
    char name[MAXNAME];
    printf("\n������ѧ������:");
    scanf("%s", name);
    if(lq->front == NULL && lq->rear == NULL){
        printf("\n����Ϊ��δ�ҵ�");
        exit(1);
    }
    p = lq->front;
    while(p != NULL && strcmp(p->stuName, name) != 0){
        p = p->next;
    }
    if(p == NULL){
        printf("δ�ҵ�");
    }else{
        printf("\n���ҳɹ�,%s��ѧ��Ϊ%s\n",p->stuName, p->stuId);
    }
}

//�޸�ѧ����Ϣ
void changeStu(linkQueue *lq){
    stuMessage *p;
    char name[MAXNAME];
    char id[MAXID];
    int x;
    printf("��Ҫ�޸�ѧ������������ѧ�� 0���� 1ѧ�� ");
    scanf("%d", &x);
    if(x == 0){
        printf("\n��Ҫ�޸ĵ�ѧ������");
        scanf("%s", name);
    }else{
        printf("\n��Ҫ�޸ĵ�ѧ��ѧ��");
        scanf("%s", id);
    }
    p = lq->front;
    if(lq->front == NULL && lq->rear == NULL){
        printf("\nѧ������Ϊ�գ��޷��޸�\n");
        exit(1);
    }
    if(x == 0){
        while(p != NULL && strcmp(p->stuName, name) != 0){
            p = p->next;
        }
        if(p != NULL){
            printf("\n������Ҫ�ĵ�����:");
            scanf("%s",p->stuName);
            printf("\n�޸ĳɹ�\n");
        }
    }else{
        while(p != NULL && strcmp(p->stuId, id) != 0){
            p = p->next;
        }
        if(p != NULL){
            printf("\n������Ҫ�ĵ�ѧ��:");
            scanf("%s",p->stuId);
            printf("\n�޸ĳɹ�\n");
        }
    }
}



