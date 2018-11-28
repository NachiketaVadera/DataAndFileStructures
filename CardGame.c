#include<stdio.h>
#include<stdlib.h>

void start();

int n,b,r,*a;

int main() {
        int f;
        char m;
        printf("++++++++++   BETTING GAME   ++++++++++\n");
        printf("Instructions: \n");
        printf("[1] Find the Queen. Enter a number between 1 and 3 to guess.\n");
        printf("[2] You can play until you're out of cash.\n");
        printf("[3] Find the Queen and you get 3 times your bet amount!\n");
        printf("What is your initial balance: \n");
        scanf("%d",&n);

        f=n;
        printf("Let's Start!\n");

        printf("Ready? (y/n): \n");
        scanf("%c",&m);

        while(n!=0 && m !='n'){
                start();
                printf("Wanna try out your luck again?(y/n): \n");
                scanf("%c",&m);
        }

        printf("\nXXXXXXXXXX   Game Over   XXXXXXXXXX\n");
        printf("You came to play the game with: %d units\n",f);
        printf("Now you have: %d units\n",n);
        return 0;

}

void start() {
        //int a;
        //a=rand()%3;
        a = (int*)malloc(sizeof(int));
        a[0]=rand()%3;
        a[1]= rand()%3;
        a[2]= rand()%3;


        if(n>0){
                printf("Current Balance: %d units\n",n);
                printf("Enter the bet amount: \n");
                scanf("%d",&b);
                if(b<=n){
                        printf("Guess where the queen is [1/2/3]: ");
                        scanf("%d",&r);
                        if(a[r]==(r-1)){
                                printf("You found her! Congratulations.\n");
                                n=n-b+(3*b);
                                printf("You now own %d units!\n",n);
                        }
                        else {
                                printf("Hmmm. That didn't work out. Better luck next time.\n");
                                n=n-b;
                                printf("You are left with %d units.\n",n);
                        }
                }
                else {
                        printf("Hahaha. You can't bet higher that what you have!");
                }

        }
        else {
                printf("You can't play the game because you are broke.");
        }
        free(a);
}
