학생 구조체

struct student{

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
    
typedef struct student STU

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

- get_score(student);

학생의 정보를 랜덤값을 이용해 저장

- compute_grade(double avr)

평균값을 이용해 등급을 계산한다



