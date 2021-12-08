#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int found(int a[], int size, int value) {
    int i;
    for(i = 0; i < size; i++) {
        if(a[i] == value)
            return 1;
    }
    return -1;
}

int uniqueRand(int a[], int size) {
    srand(time(0));

    int i;
    for(i = 0; i < size; i++) {
        
        int j;
        int val = 1 + rand () % 9;
        /*printf("Current Array: ");
        for(j = 0; j < i; j++){
            printf("%d ", a[j]);
        }
        printf("\nrandom value: %d\n", val);*/
        while(found(a, i, val) != -1) {
            val = 1 + rand () % 9;
            //printf("random value: %d\n", val);
        }

        a[i] = val;
    }
    return 0;
}

int main() {

//setting up the game
    int turns, size;
    long long int start,stop;
    while(1) {
        printf("------------------------------------\n");
            printf("Welcome to the MasterMind Game!\n");
            printf("\tVersion 0 \t\n");
            printf("   Release Date: march 26, 2021\n");
            printf("     programmer: mukesh reddy.\n");
            printf("------------------------------------\n");
            printf("* * * *\n");
            
            printf("You have %d remaining chance(s).\n", turns);
            printf("Give four numbers (enter 0 to exit): ");

        while(1){
            printf("Enter the number of digits (1-7): ");
            scanf("%d", &size);
            if(size < 1 || size > 7) {
                printf("Please Enter a valid size\n");
            } else {
                break;
            }
        }

        int N[size], temp;

        while(1) {
            printf("Enter the number of guess (1 to 100): ");
            scanf("%d", &turns);
            temp = turns;
            if(turns < 1 || turns > 100) {
                printf("Please Enter a valid number of guesses\n");
            } else {
                break;
            }
        }
        time(&start);
        int i;
        uniqueRand(N, size);
        for(i = 0; i < size; i++){
           // printf("%d ", N[i]);
        }
        printf("\n");
        //repeating until the user wants to stop
        while(1) {
            int guess[size];
            int  j, color = 0, location = 0;

            printf("You have %d remaining chance(s).\n\n", turns);
            printf("Give four numbers (enter 0 to exit): ");
            scanf("%d", &guess[0]);

            if(guess[0] != 0) {
                for(i = 1; i < size; i++) {
                    scanf("%d", &guess[i]);
                }
            } else{
                break;
            }

            for(i = 0; i < size; i++){
                if(N[i] == guess[i]) {
                    location ++;
                    continue;
                }
                for(j = 0; j < size; j++){
                    if(N[i] == guess[j]) {
                        color++;
                        break;
                    }
                }
            }

            turns --;
            printf("Correct Location & Number : %d, Correct Number: %d\n\n", location, color);
            time(&stop);
            long long int t = difftime(stop,start);
            //Checking if won(all 4 correct location and color)
            if(location == size)
            {
                printf("Excelent!! you solved it with %d guesses in %d seconds\n\n", temp - turns,t);
                break;
            }
            
            //Checking if chances are done
            if(turns == 0)
            {
                printf("Out Of Moves!\nThe numbers were: ");
                for(i = 0; i < size; i++){
                    printf("%d", N[i]);
                }
                printf("\n");
                break;
            }
        }
		//Asking the user if he wants to play again
        int repeat;
        printf("\nDo you want to play another game? (No: 0, Yes: 1): ");
        scanf("%d", &repeat);
        printf("\n");
        if(repeat == 0) {
            break;
        }

    }
    return 0;
}