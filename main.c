#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <Windows.h>
    #include <zconf.h>
#else
    #include <unistd.h>
#endif

const int WIDTH = 80;
const int HEIGHT = 15;
const int FPS = 1;

double ball_x = WIDTH/2;
double ball_y = HEIGHT/2;
double ball_vel_x;
double ball_vel_y;

int player1; // schläger links
int player2; // schläger rechts

void render();
void tick();
int main() {
    system(" ");
    system("cls");
    srand(23434);

    ball_vel_x = ((float)rand())/RAND_MAX;
    ball_vel_y = ((float)rand())/RAND_MAX;

    printf("velx = %f\n",ball_vel_y);
    printf("vely = %f\n",ball_vel_x);

    //game loop
    int running = 1;
    while(running){
        running ++;

        tick();
        render();

        sleep(1.0/FPS);//time in seconds
        if(running == 90){
            running = 0;
        }
    }
    return 0;
}
void tick(){
    ball_x = ball_x + ball_vel_x;
    ball_y = ball_y + ball_vel_y;

    if(ball_y <= 0 || ball_y >= WIDTH-3){ //bildschirmrand
        ball_vel_y = -ball_vel_y;
    }

}

void render(){
    for(int y = 0; y < HEIGHT; y++) {
        printf("\033A");
    }

    for(int x = 0;x < WIDTH; x++) {
        printf("-");
    }
    printf("\n");
    for(int y = 1; y < HEIGHT-1; y++){
        printf("|");
        for(int x = 1;x < WIDTH-1; x++){
            if((int)ball_y == y && (int)ball_x == x){
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    for(int x = 0;x < WIDTH; x++) {
        printf("-");
    }
    printf("\n");
}