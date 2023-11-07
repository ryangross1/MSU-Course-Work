#include <stdio.h>
#include <math.h>

//read from a file to grade an n question test from multiple students

int * calcGrade(char ca[], char sa[], int m[], int l);           //declare functions
void printMissed(int m[], int l);

int main(void){                                         
    FILE* fptr = fopen("/public/lab3/exam.txt", "r");       //open file
    if (fptr == NULL){
        printf("ERROR file not found");     //file not found exception
        return(1);
    }
    printf("Question\t1 2 3 4 5 6 7\n");
    printf("Answer\t\tc c d d a b c\n");
    int length;
    fscanf(fptr, "%d", &length);            //determines length of test
    //int missed[7] = {0}; 
    int missed[length]; 
    for (int i = 0; i < length; i++){
        missed[i] = 0;                     //inits missed[] to {0} bc cannot init arr of var length
    }
    char correctAnswer[length];
    char ans;

    for (int i = 0; i < length+1; i++){     //makes array of correct answers
        fscanf(fptr, "%c", &ans);
        correctAnswer[i] = ans;
    }
   /* 
    for (int i = 0; i < length+1; i++){
        printf("%c", correctAnswer[i]);
    }
    */
    int id;
    char studentAnswer[length];
    printf("ID\tGrade(%%)\n");
    //while (! feof(fptr)){         was reading an extra time w this 
    for (int i = 0; i < 5; i++){
        fscanf(fptr, "%d", &id);        //reads student id
        for (int i = 0; i < length+1; i++){
            fscanf(fptr, "%c", &ans);   //makes array of student answers
            studentAnswer[i] = ans; 
        }
        printf("%d\t", id); //will print id's in line w grades

        //for (int i = 0; i < length+1; i++){
            //printf("%c ", studentAnswer[i]);
        //}
        calcGrade(correctAnswer, studentAnswer, missed, length);
    }
    printf("Question\t1 2 3 4 5 6 7\n");
    printMissed(missed, length);
    
    return(0);
}

int * calcGrade(char ca[], char sa[], int m[], int l){
    double total = l;
    double max = l;                         //if current student grade ans != correct ans, missed++, total--
    for (int i = 0; i < l+1; ++i){
        if (ca[i] != sa[i]){
            m[i]++;
            total--;
        }
       //printf("%c ", sa[i]);
       //printf("%d ", m[i]);
    }
    double grade = (total/max)*100;
    printf("%.2lf\n", grade);           //divide correct ans by length * 100 to get percent grade
    return(m);
}

void printMissed(int m[], int l){ //reads in missed[] after returned from calcGrade
    printf("Missed by\t");
   for (int i = 1; i < l+1; i++){
        printf("%d ", m[i]);
      }
   printf("\n");   
}

