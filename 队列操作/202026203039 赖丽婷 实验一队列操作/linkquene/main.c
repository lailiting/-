#include "queue.h"

int main()
{
    system("color f0");
    linkQueue *stuqueue;
    stuqueue = (linkQueue*)malloc(sizeof(linkQueue));
    init(stuqueue);
    int x, choice;
    printf("��ʼ��ѧ����Ϣ:1���� 0����:");
    scanf("%d",&x);
    while(x == 1){
        addStu(stuqueue);
        printf("\n1���� 0����:");
        scanf("%d",&x);
    }
    printStu(stuqueue);
    x = 1;
    while(x == 1){
        printf("\nѧ����Ϣ���л������ܲ˵�\n");
        printf("========================================\n");
        printf("1.���ѧ����Ϣ(���)\n");
        printf("2.ɾ��ѧ����Ϣ(����)\n");
        printf("3.��ʾѧ����Ϣ(����)\n");
        printf("4.�޸�ѧ����Ϣ(�޸�)\n");
        printf("5/����ѧ����Ϣ(����)\n");
        printf("6.�˳�ѧ����Ϣ���в���\n");
        printf("========================================\n");
        printf("��ѡ����:");
        scanf("%d", &choice);
        if(choice == 1)
            addStu(stuqueue);
        else if(choice == 2)
            delStu(stuqueue);
        else if(choice == 3)
            printStu(stuqueue);
        else if(choice == 4)
            changeStu(stuqueue);
        else if(choice == 5)
            findStu(stuqueue);
        else if(choice == 6){
            break;
        }else{
            printf("��������ȷ:");
        }
    }
    return 0;
}
