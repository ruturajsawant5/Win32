#include "lib.h"
#include <stdio.h> 
#include <string.h> 

static struct student s_lib_copy; 

void get(struct student* p_student){
    if(p_student->mask & ST_ALL){
        memcpy(
                &p_student->i_roll, 
                &s_lib_copy.i_roll, 
                p_student->size - OFFSET_OF(struct student, i_roll)
        ); 
        return; 
    }

    if(p_student->mask & ST_ROLL)
        p_student->i_roll = s_lib_copy.i_roll; 

    if(p_student->mask & ST_ATTND)
        p_student->i_attnd = s_lib_copy.i_attnd; 

    if(p_student->mask & ST_MARKS)
        p_student->i_marks = s_lib_copy.i_marks; 
}

void set(struct student* p_student){
    if(p_student->mask & ST_ALL){
        memcpy(
            &s_lib_copy.i_roll, 
            &p_student->i_roll,
            p_student->size - OFFSET_OF(struct student, i_roll)
        ); 
        return; 
    }
    if(p_student->mask & ST_ROLL)
        s_lib_copy.i_roll= p_student->i_roll; 

    if(p_student->mask & ST_ATTND)
        s_lib_copy.i_attnd= p_student->i_attnd; 

    if(p_student->mask & ST_MARKS)
        s_lib_copy.i_marks = p_student->i_marks; 
}

void show(struct student* p_student){
    if(p_student->mask == ST_ALL){
        printf("roll=%d, attnd=%d, marks=%d\n", 
                p_student->i_roll, p_student->i_attnd, p_student->i_marks); 
    }

    if(p_student->mask & ST_ROLL)
        printf("roll=%d\n", p_student->i_roll); 
    if(p_student->mask & ST_ATTND)
        printf("attnd=%d\n", p_student->i_attnd); 
    if(p_student->mask & ST_MARKS)
        printf("marks=%d\n", p_student->i_marks); 
}