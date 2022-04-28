#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
/*
This code will print the entire calendary of the year you decide to select.
There are a few things we have to consider: 
 - Leap years. Every 4 years is a leap year. 2020 was a leap year therefore, if the remainder of the year/4 is 0, it is a leap year.
 Also, every exact century needs to have 400 as a factor to be a leap year. Therefore, we need to make some calculations.               
*/

//Function to calculate how many Leap Years are from AC to the year entered.
int leapYears(int a){
    int year = a;
    int leaps = floor(year/4) - (floor(year/100)-floor(year/400));
    return leaps;
}

//Function to calculate the total days from AC to the start of the year entered
//It doesn't count January 1st
int totalDaysAC(int a){
    int year = a-1;
    int leaps = leapYears(year);
    int notLeaps = year - leaps;
    int AC = notLeaps*365 + leaps*366;
    return AC; 
}

//Function to calculate the day a date is.
//January 1st 2021 was friday, and we need to know what day was 737790 days before, on january 1st year 1. 737790 = 4 (mod 7) therefore it was lots of weeks ago plus 4 days. This means 
//january 1st year 1 was actually a monday. Therefore, if a year % 7 == 1, means the day is monday and == 0 sunday. This is why weeks start on sunday!!
int whatDayIsIt(int a){
    int day = a;
    int remainder = day % 7;
    char *dayOfTheWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("%s", dayOfTheWeek[remainder]);
    return 0;
}

//Function to check if the year entered is a Leap Year, Which will change the days on february in main()
bool isItALeapYear(int a){
    int year = a;
    bool answer = false;
    if (year % 4 == 0){
        answer = true;
        if (year % 100 == 0){
            answer = false;
            if(year % 400 == 0){
                answer = true;
            }
        }
    }
    return answer;
}

int main(){

    int year;
    int January1 = (totalDaysAC(year) + 1) % 7;

//Variables for the default lenght of months a year and days a month.
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Asks for the user to input a year
    printf("\n CALENDAR BOT > Hello! Welcome to the Calendar Bot, enter a year and I will print the entire calendar for it!\n");
    scanf("%d", &year);

//Changes february lenght if it is a leap year
    bool isItLeap = isItALeapYear(year);
    if (isItLeap == true) {
        days[1] = 29;
    }

//Prints the entire thing

    printf("\t  Calendary of %d\n\n", year); //Title
    for(int a = 0; a <= 11; a++){  
        printf("\t       %s\n", months[a]);  //Month title
        for(int b = 1; b <= days[a]; b++){
            
            if (b < 10) {
                printf(" %d ", b);
            } else {
                printf("%d ", b);
            }
            
//           whatDayIsIt(January1); //Remove commentary If you want to print what specific day a date is!!
            printf(" ");
            January1++;
            if (b % 10 == 0){
                printf("\n");
            }
        }
        printf("\n");
    }

    printf("\nCALENDAR BOT > I can also print the calendary with days! Wanna see?!\nPlease, enter YES or NO to continue\n");

    char answer[20];
    scanf("%s", answer);

    while (strcasecmp(answer, "no") != 0){
        if(strcasecmp(answer, "yes") == 0){
        
             January1 = (totalDaysAC(year) + 1) % 7;

                //Prints the entire thing agaaaain

             printf("\t  Calendary of %d\n\n", year); //Title
             for(int a = 0; a <= 11; a++){  
                 printf("\t       %s\n", months[a]);  //Month title
                 for(int b = 1; b <= days[a]; b++){           
                     if (b < 10) {
                         printf(" %d-", b);
                     } else {
                        printf("%d-", b);
                     }           
                     whatDayIsIt(January1);
                     printf(" ");
                     January1++;
                     if (b % 10 == 0){
                          printf("\n");
                     }
                 }
                 printf("\n");
             }
            break;


        } else {
            printf("Please enter YES or NO\n"); 
            scanf("%s", answer);
        }
    }    

    return 0;
}