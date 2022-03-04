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

    printf("몇명을 입력 하십니까? : ");
    scanf("%d",&count);

    while(!flag){
        system("cls");
        fflush(stdin);
        printf("---------------------------------------------------------------------\n");
        printf("1. 학생 성적 입력(자동) ");
        printf("4. 학생 성적 수정\t");
        printf("7. 학생 성적 정렬(오름내림 차순)\n");
        printf("---------------------------------------------------------------------\n");
        printf("2. 학생 성적 출력\t");
        printf("5. 학생 성적 삭제       ");
        printf("8. 성적 프로그램 종료\n");
        printf("---------------------------------------------------------------------\n");
        printf("3. 학생 성적 검색 \t");
        printf("6. 학생 성적 입력 (수동) \n");
        printf("---------------------------------------------------------------------\n");
        printf("메뉴 선택 : ");
        scanf("%d",&menu);

        switch(menu){
            case 1:
                // STU student[MAX]; 구조체 배열명 (STU *)
                get_score(student);
                printf("학생성적이 입력완료.(메뉴로 가기위해 엔터 누르세요) ");
                getchar();
                getchar();
                break;
            case 2:
                printf("\n순서 이름   학년  번호  성별 씨언어 자바 코틀린 총점  평균   등급 \n");
                output_score(student, count);
                printf("\n학생성적이 출력완료.(메뉴로 가기위해 엔터 누르세요) ");
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
                printf("\n 학생성적 수정완료(메뉴로 가기위해 엔터 누르세요) ");
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
                printf("\n학생 성적 입력완료.(메뉴로 가기위해 엔터 누르세요) ");
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
                printf("성적프로그램이 종료되었습니다. ");
                break;
            default : printf("다시 입력해주세요 \n");
        }

    }
    return 0;
}
// STU student[MAX]; 구조체 배열명 (STU (*~~~))
void get_score(STU *student){
    int i = 0;
    // 렌덤 초기화
    srand(time(NULL));
    for(i = 0;i<count;i++){
        // 이름 세글자 설정(대문자로 자동 입력)
        student[i].name[0] = rand()%(25-0+1)+0+'A';
        student[i].name[1] = rand()%(25-0+1)+0+'A';
        student[i].name[2] = rand()%(25-0+1)+0+'A';
        student[i].name[3] = 0;
        // 학년(1~4)
        student[i].year = rand()%(4-1+1)+1;
        // 번호 (1~100)
        student[i].number = rand()%(100-1+1)+1;
        // 성별(0 = 여, 1 = 남)
        student[i].gender = rand()%(1-0+1)+0;
        // 점수 (0~100)
        student[i].c = rand()%(100-0+1)+0;
        student[i].java = rand()%(100-0+1)+0;
        student[i].kotlin = rand()%(100-0+1)+0;
        // 총점 계산
        student[i].total = student[i].c + student[i].java + student[i].kotlin;
        // 평균 계산
        student[i].avr = student[i].total / (double)SUBJECT;
        // 등급 계산 (90점이상: A, 80점이상: B, 70점이상: C, 60점이상: D, 60점 미만: F
        student[i].grade = rank_grade(student[i].avr);
    }

    return;
}
// 학생 성적 총점으로 등급 매기는 함수
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
// 학생 성적 출력 함수
void output_score(STU *student, int c){
    int  i = 0;

    for(i = 0;i < c;i++){
        printf("%3d %5s %5d %5d %5s %5d %5d %5d %5d %6.2lf %5c \n",
               i+1, &student[i].name[0], student[i].year, student[i].number,
               student[i].gender == 1?"남":"여", student[i].c, student[i].java, student[i].kotlin,
               student[i]. total, student[i].avr, student[i].grade);
    }
    return;
}
// 학생 성적 검색 함수
void search_score(STU *student){

    char name[10] = {0,};
    int  i = 0;
    int search_flag = 0;

    printf("검색할 학생의 이름은(3글자) : ");
    scanf("%s",&name[0]);

    // 문자열 비교 int strcmpi(const char *string1, const char *string2);
    // 다른방법 (strcmpi(&name[0], &student[i].name[0]) ==0 )
    for(i = 0; i < count; i++){
        if(strcmpi(&name[0], &student[i].name[0]) ==0){
            output_score(&student[i], 1);
            search_flag = 1;
            printf("\n학생성적이 검색완료.(메뉴로 가기위해 엔터 누르세요) ");
        }
    }
    if(search_flag == 0){
        printf("검색한 %s 학생이 없습니다. \n", &name[0]);
    }
    return;
}
// 학생 성적 수정 함수
void correction_score(STU *student){

    char name[10] = {0,};
    int  i = 0;
    int correction_flag = 0;

    printf("수정할 학생의 이름은(3글자) : ");
    scanf("%s",&name[0]);

    // 문자열 비교 int strcmpi(const char *string1, const char *string2);
    // 다른방법 (!strcmpi(&name[0], &student[i].name[0]) ==0 )
    for(i = 0; i < count; i++){
        if(strcmpi(&name[0], &student[i].name[0]) == 0){
            printf("현재 c언어 점수 %d 수정할 점수 입력(3글자) : ",student[i].c);
            scanf("%d",&student[i].c);

            printf("현재 java언어 점수 %d 수정할 점수 입력(3글자) : ",student[i].java);
            scanf("%d",&student[i].java);

            printf("현재 c언어 점수 %d 수정할 점수 입력(3글자) : ",student[i].kotlin);
            scanf("%d",&student[i].kotlin);

            student[i].total = student[i].c + student[i].java + student[i].kotlin;
            student[i].avr = student[i].total / (double)SUBJECT;
            student[i].grade = rank_grade(student[i].avr);

            correction_flag = 1;
        }
    }
    if(correction_flag == 0){
        printf("검색한 %s 학생이 없습니다. \n", &name[0]);
    }

    return;
}
// 학생 성적 삭제 함수
void removal_score(STU *student){

    char name[10] = {0,};
    int  i = 0;
    int removl_flag = 0;

    printf("삭제할 학생의 이름은(3글자) : ");
    scanf("%s",&name[0]);

    // 문자열 비교 int strcmpi(const char *string1, const char *string2);
    // 다른방법 if(strcmpi(&name[0], &student[i].name[0]) ==0 )
    // if(strnicmp(비교할 입력한 문자와, 가지고있는 이름을 비교,길이는 몇개 비교하는것인가){}
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

            printf("\n학생성적이 삭제완료.(메뉴로 가기위해 엔터 누르세요) ");

            removl_flag = 1;
        }
    }
    if(removl_flag == 0){
        printf("삭제할 %s 학생이 없습니다. \n", &name[0]);
    }

    return;
}
// 학생 성적 수동 입력 함수
void addition_score(STU *student){

        printf("추가할 이름 입력(3글자) : ");
        scanf("%s",&student[count].name);

        printf("추가할 학년 입력(1~4) : ");
        scanf("%d",&student[count].year);

        printf("추가할 번호 입력(1~100) : ");
        scanf("%d",&student[count].number);

        printf("추가할 성별 입력(1 : 남 0 : 여) : ");
        scanf("%d",&student[count].gender);

        printf("추가할 점수 입력(0~100) : ");
        scanf("%d",&student[count].c);

        printf("추가할 점수 입력(0~100) : ");
        scanf("%d",&student[count].java);

        printf("추가할 점수 입력(0~100) : ");
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

    printf("오름 차순 : 1 내림차순 : 2 ");
    scanf("%d",&range_type);

    //원본 -> 사본으로 구조체 배열 복사 void *memcpy(void *_Dst, void const *_Src, size_t _Size);
    for(i=0;i<count;i++){
        memcpy(&copy_student[i], &student[i], sizeof(STU));
    }

    switch(range_type){
        case 1:
            // 오름차순정렬
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
            // 내림차순정렬
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
        default : puts("다시 입력 해주세요.");

    }
    return;
}
