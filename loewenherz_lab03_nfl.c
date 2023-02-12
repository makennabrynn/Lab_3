//makenna loewenherz
//eecs 348 lab 03
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int touchdown = 6;
    int field_goal = 3;
    int safety = 2;
    int touchdown_2fg = 8;
    int touchdown_1fg = 7;

    //calculating all possible scores
    int score;
    printf("enter a score: ");
    scanf("%d", &score);

    printf("all score combination possibilities: ");
    for (int td = 0; td < 100000; td++) {
    for (int fg; fg < 100000; fg++) {
    for (int s; s < 100000; s++) {
    for (int t2fg; t2fg < 100000; t2fg++) {
    for (int t1fg; t1fg < 100000; t1fg++) {
        int score_calculation = touchdown*td + field_goal*fg + safety*s + touchdown_2fg*t2fg + touchdown_1fg*t1fg;
        if (score == score_calculation) {
            printf("touchdowns: %d \n field goals: %d \n safeties: %d \n touchdown + 2 point fg: %d \n touchdown + 1 point fg: %d \n",
               td, fg, s, t2fg, t1fg);
        }
    }
    }
    }
    } 
    }

    return 0;
}