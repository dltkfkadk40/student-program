#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SUBJECT 3
#define MAX 100
struct student_info{
    char name[10];
    int year;
    int number;
    int gender;
    int c;
    int java;
    int kotlin;
    int total;
    double avr;
    char grade;
};
typedef struct student_info STU;
char rank_grade(double avr);
void get_score(STU *student);
void output_score(STU *student, int c);
void search_score(STU *student);
void correction_score(student);
void removal_score(STU *student);
void range_score(STU *student);
int count = 0;

int main()
{
    int menu = 0;
    int flag = 0;
    STU student[MAX];

    printf("����� �Է� �Ͻʴϱ�? : ");
    scanf("%d",&count);

    while(!flag){
        system("cls");
        fflush(stdin);
        printf("---------------------------------------------------------------------\n");
        printf("1. �л� ���� �Է�(�ڵ�) ");
        printf("4. �л� ���� ����\t");
        printf("7. �л� ���� ����(�������� ����)\n");
        printf("---------------------------------------------------------------------\n");
        printf("2. �л� ���� ���\t");
        printf("5. �л� ���� ����       ");
        printf("8. ���� ���α׷� ����\n");
        printf("---------------------------------------------------------------------\n");
        printf("3. �л� ���� �˻� \t");
        printf("6. �л� ���� �Է� (����) \n");
        printf("---------------------------------------------------------------------\n");
        printf("�޴� ���� : ");
        scanf("%d",&menu);

        switch(menu){
            case 1:
                // STU student[MAX]; ����ü �迭�� (STU *)
                get_score(student);
                printf("�л������� �Է¿Ϸ�.(�޴��� �������� ���� ��������) ");
                getchar();
                getchar();
                break;
            case 2:
                printf("\n���� �̸�   �г�  ��ȣ  ���� ����� �ڹ� ��Ʋ�� ����  ���   ��� \n");
                output_score(student, count);
                printf("\n�л������� ��¿Ϸ�.(�޴��� �������� ���� ��������) ");
                getchar();
                getchar();
                break;
            case 3:
                search_score(student);
                getchar();
                getchar();
                break;
            case 4:
                correction_score(student);
                printf("\n �л����� �����Ϸ�(�޴��� �������� ���� ��������) ");
                getchar();
                getchar();
                break;
            case 5:
                removal_score(student);
                getchar();
                getchar();
                break;
            case 6:
                addition_score(student);
                printf("\n�л� ���� �Է¿Ϸ�.(�޴��� �������� ���� ��������) ");
                getchar();
                getchar();
                break;
            case 7:
                range_score(student);
                getchar();
                getchar();
                break;
            case 8:
                flag = 1;
                printf("�������α׷��� ����Ǿ����ϴ�. ");
                break;
            default : printf("�ٽ� �Է����ּ��� \n");
        }

    }
    return 0;
}
// STU student[MAX]; ����ü �迭�� (STU (*~~~))
void get_score(STU *student){
    int i = 0;
    // ���� �ʱ�ȭ
    srand(time(NULL));
    for(i = 0;i<count;i++){
        // �̸� ������ ����(�빮�ڷ� �ڵ� �Է�)
        student[i].name[0] = rand()%(25-0+1)+0+'A';
        student[i].name[1] = rand()%(25-0+1)+0+'A';
        student[i].name[2] = rand()%(25-0+1)+0+'A';
        student[i].name[3] = 0;
        // �г�(1~4)
        student[i].year = rand()%(4-1+1)+1;
        // ��ȣ (1~100)
        student[i].number = rand()%(100-1+1)+1;
        // ����(0 = ��, 1 = ��)
        student[i].gender = rand()%(1-0+1)+0;
        // ���� (0~100)
        student[i].c = rand()%(100-0+1)+0;
        student[i].java = rand()%(100-0+1)+0;
        student[i].kotlin = rand()%(100-0+1)+0;
        // ���� ���
        student[i].total = student[i].c + student[i].java + student[i].kotlin;
        // ��� ���
        student[i].avr = student[i].total / (double)SUBJECT;
        // ��� ��� (90���̻�: A, 80���̻�: B, 70���̻�: C, 60���̻�: D, 60�� �̸�: F
        student[i].grade = rank_grade(student[i].avr);
    }

    return;
}
// �л� ���� �������� ��� �ű�� �Լ�
char rank_grade(double avr){
    char grade = 0;

    if(avr > 90.0){
        grade = 'A';
    }else if(avr > 80.0){
        grade = 'B';
    }else if(avr > 70.0){
        grade = 'C';
    }else if(avr > 60.0){
        grade = 'D';
    }else{
        grade = 'F';
    }

    return grade;
}
// �л� ���� ��� �Լ�
void output_score(STU *student, int c){
    int  i = 0;

    for(i = 0;i < c;i++){
        printf("%3d %5s %5d %5d %5s %5d %5d %5d %5d %6.2lf %5c \n",
               i+1, &student[i].name[0], student[i].year, student[i].number,
               student[i].gender == 1?"��":"��", student[i].c, student[i].java, student[i].kotlin,
               student[i]. total, student[i].avr, student[i].grade);
    }
    return;
}
// �л� ���� �˻� �Լ�
void search_score(STU *student){

    char name[10] = {0,};
    int  i = 0;
    int search_flag = 0;

    printf("�˻��� �л��� �̸���(3����) : ");
    scanf("%s",&name[0]);

    // ���ڿ� �� int strcmpi(const char *string1, const char *string2);
    // �ٸ���� (strcmpi(&name[0], &student[i].name[0]) ==0 )
    for(i = 0; i < count; i++){
        if(strcmpi(&name[0], &student[i].name[0]) ==0){
            output_score(&student[i], 1);
            search_flag = 1;
            printf("\n�л������� �˻��Ϸ�.(�޴��� �������� ���� ��������) ");
        }
    }
    if(search_flag == 0){
        printf("�˻��� %s �л��� �����ϴ�. \n", &name[0]);
    }
    return;
}
// �л� ���� ���� �Լ�
void correction_score(STU *student){

    char name[10] = {0,};
    int  i = 0;
    int correction_flag = 0;

    printf("������ �л��� �̸���(3����) : ");
    scanf("%s",&name[0]);

    // ���ڿ� �� int strcmpi(const char *string1, const char *string2);
    // �ٸ���� (!strcmpi(&name[0], &student[i].name[0]) ==0 )
    for(i = 0; i < count; i++){
        if(strcmpi(&name[0], &student[i].name[0]) == 0){
            printf("���� c��� ���� %d ������ ���� �Է�(3����) : ",student[i].c);
            scanf("%d",&student[i].c);

            printf("���� java��� ���� %d ������ ���� �Է�(3����) : ",student[i].java);
            scanf("%d",&student[i].java);

            printf("���� c��� ���� %d ������ ���� �Է�(3����) : ",student[i].kotlin);
            scanf("%d",&student[i].kotlin);

            student[i].total = student[i].c + student[i].java + student[i].kotlin;
            student[i].avr = student[i].total / (double)SUBJECT;
            student[i].grade = rank_grade(student[i].avr);

            correction_flag = 1;
        }
    }
    if(correction_flag == 0){
        printf("�˻��� %s �л��� �����ϴ�. \n", &name[0]);
    }

    return;
}
// �л� ���� ���� �Լ�
void removal_score(STU *student){

    char name[10] = {0,};
    int  i = 0;
    int removl_flag = 0;

    printf("������ �л��� �̸���(3����) : ");
    scanf("%s",&name[0]);

    // ���ڿ� �� int strcmpi(const char *string1, const char *string2);
    // �ٸ���� if(strcmpi(&name[0], &student[i].name[0]) ==0 )
    // if(strnicmp(���� �Է��� ���ڿ�, �������ִ� �̸��� ��,���̴� � ���ϴ°��ΰ�){}
    for(i = 0; i < count; i++){
        if(strcmpi(&name[0], &student[i].name[0]) ==0){
            strcpy(student[i].name,"___");
//          student[i].name[0] = '_';
//          student[i].name[1] = '_';
//          student[i].name[2] = '_';
            student[i].year = 0;
            student[i].number = 0;
            student[i].gender = 0;
            student[i].c = 0;
            student[i].java = 0;
            student[i].kotlin = 0;
            student[i].total = 0;
            student[i].avr = 0.0;
            student[i].grade = '_';

            printf("\n�л������� �����Ϸ�.(�޴��� �������� ���� ��������) ");

            removl_flag = 1;
        }
    }
    if(removl_flag == 0){
        printf("������ %s �л��� �����ϴ�. \n", &name[0]);
    }

    return;
}
// �л� ���� ���� �Է� �Լ�
void addition_score(STU *student){

        printf("�߰��� �̸� �Է�(3����) : ");
        scanf("%s",&student[count].name);

        printf("�߰��� �г� �Է�(1~4) : ");
        scanf("%d",&student[count].year);

        printf("�߰��� ��ȣ �Է�(1~100) : ");
        scanf("%d",&student[count].number);

        printf("�߰��� ���� �Է�(1 : �� 0 : ��) : ");
        scanf("%d",&student[count].gender);

        printf("�߰��� ���� �Է�(0~100) : ");
        scanf("%d",&student[count].c);

        printf("�߰��� ���� �Է�(0~100) : ");
        scanf("%d",&student[count].java);

        printf("�߰��� ���� �Է�(0~100) : ");
        scanf("%d",&student[count].kotlin);

        student[count].total = student[count].c + student[count].java + student[count].kotlin;
        student[count].avr = student[count].total / (double)SUBJECT;
        student[count].grade = rank_grade(student[count].avr);

        count++;



    return;
}

void range_score(STU *student){
    int range_type =0;
    int  i = 0, j = 0;
    STU copy_student[count];
    STU student_buffer;

    printf("���� ���� : 1 �������� : 2 ");
    scanf("%d",&range_type);

    //���� -> �纻���� ����ü �迭 ���� void *memcpy(void *_Dst, void const *_Src, size_t _Size);
    for(i=0;i<count;i++){
        memcpy(&copy_student[i], &student[i], sizeof(STU));
    }

    switch(range_type){
        case 1:
            // ������������
            for(i=0;i <count-1;i++){
                for(j=i+1;j < count;j++){
                    if(copy_student[i].total > copy_student[j].total){
                        memcpy(&student_buffer, &copy_student[i], sizeof(STU));
                        memcpy(&copy_student[i], &copy_student[j], sizeof(STU));
                        memcpy(&copy_student[j], &student_buffer, sizeof(STU));
                    }
                }
            }//end of ofr
            output_score(copy_student, count);

            break;
        case 2:
            // ������������
            for(i=0;i <count-1;i++){
                for(j=i+1;j < count;j++){
                    if(copy_student[i].total < copy_student[j].total){
                        memcpy(&student_buffer, &copy_student[i], sizeof(STU));
                        memcpy(&copy_student[i], &copy_student[j], sizeof(STU));
                        memcpy(&copy_student[j], &student_buffer, sizeof(STU));
                    }
                }
            }//end of ofr
            output_score(copy_student, count);
            break;
        default : puts("�ٽ� �Է� ���ּ���.");

    }
    return;
}
