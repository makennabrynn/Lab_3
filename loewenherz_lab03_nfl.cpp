//makenna loewenherz
//eecs 348 lab 03
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int running = 1;
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
    int combination_num = 0;
    int user_exit = 0;

    while (running) {
    for (int td = 0; td < 40; td++) {
    for (int fg = 0; fg < 40; fg++) {
    for (int s = 0; s < 40; s++) {
    for (int t2fg = 0; t2fg < 40; t2fg++) {
    for (int t1fg = 0; t1fg < 40; t1fg++) {
        int score_calculation = touchdown*td + field_goal*fg + safety*s + touchdown_2fg*t2fg + touchdown_1fg*t1fg;
        if (score == score_calculation) {
            printf("combination %d", combination_num++);
            printf("\ntouchdowns: %d \n field goals: %d \n safeties: %d \n touchdown + 2 point fg: %d \n touchdown + 1 point fg: %d \n",
               td, fg, s, t2fg, t1fg);
        }
    }
    }
    }
    } 
    }
    printf("Input 0 or 1 to exit, or enter a score to generate results.\n");
        scanf("%d",&user_exit); // keep running the program until the user exits
        if (user_exit == 0 || user_exit == 1) running = 0;
    }
    return 0;
}