학생 구조체

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
   
    }
    
typedef struct student_info STU

상수 

#define MAX 100

#define SUBJECT 3

- name

 학생 이름의 의미

10자리까지 입력

- year

 학생 학년의 의미

- number

 학생 학번의 의미

- gender

 학생 성별의 의미

- c , java , kotlin

 학생 과목점수의 의미

- total , avr , grade

 학생 총점, 평균. 등급을 의미

- get_score(STU *student)

 학생의 정보를 랜덤값을 이용해 저장

- rank_grade(double avr)

 평균값을 이용해 등급을 계산한다

- output_score(STU *student, int c)

 학생 정보를 출력
 
- search_score(STU *student)
 
 학생 이름을 키보드로 대/소문자 상관없이 입력하여 학생 정보를 출력한다

- correction_score(STU *student)

 학생 이름를 키보드로 입력하여 수정할 학생 정보를 수정한다
 
- removal_score(STU *student)

 학생이름을 키보드로 입력하여 학생의 정보를 삭제한다
 
- addition_score(STU *student)

 학생의 정보를 키보드로 입력하여 추가한다
 
- range_score(STU *student)

 학생 정보를 총점을 기준으로 오름차순/내림차순을 선택하여 보여준다 




