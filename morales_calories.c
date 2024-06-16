//Antonio Morales
//N01551618
//March 11th, 2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void LogFood();
void PrintByDay();
void PrintMostCalories();
void ResetLog();
int main()
{
    int userInput;
    printf("\tCALORIE COUNTER AND TRACKER\n");
    while(1)
    {
        printf("What function would you like to use?\n1 = Log Food\n2 = Print Calories by Day\n3 = Print Food with Most Calories\n4 = Reset Log\n-1 = QUIT\n");
        scanf("%d", &userInput);
        if(userInput == -1)
            break;
        switch(userInput)
        {
        case 1:
            LogFood();
            break;
        case 2:
            PrintByDay();
            break;
        case 3:
            PrintMostCalories();
            break;
        case 4:
            ResetLog();
            break;
        default:
            break;
        }

    }
    return 0;
}

void LogFood()
{
    FILE * fp = fopen("calories.txt", "a");
    char foodName[50];
    //Collect data from console or terminal.
    int dayNumber, calorieIntake;
    printf("What food did you eat?\n");
    scanf("%s", foodName);
    printf("What day did you eat it? (1 = Monday; 7 = Sunday)\n");
    scanf("%d", &dayNumber);
    printf("How many calories did it have?\n");
    scanf("%d", &calorieIntake);
    //Print this data (append) to the file that has been opened.
    fprintf(fp, "%s %d %d\n", foodName, dayNumber, calorieIntake);
    //Close the file so future iterations of the loop can access it.
    fclose(fp);
}

void PrintByDay()
{
    FILE * fp = fopen("calories.txt", "r");
    int temp, dayOfWeek, args, monSum = 0, tuSum = 0, wedSum = 0, thurSum = 0, friSum = 0, satSum = 0, sunSum = 0;
    char garbageStr[50];
    //Infinite loop to sum up all elements in the file (temp being the calories of a given element and dayOfWeek allowing for grouping and sorting of these calories.
    while(1)
    {
        args = fscanf(fp, "%s %d %d", garbageStr, &dayOfWeek, &temp);
        if(args == -1)
            break;
        if(dayOfWeek == 1)
            monSum += temp;
        else if(dayOfWeek == 2)
            tuSum += temp;
        else if(dayOfWeek == 3)
            wedSum += temp;
        else if(dayOfWeek == 4)
            thurSum += temp;
        else if(dayOfWeek == 5)
            friSum += temp;
        else if(dayOfWeek == 6)
            satSum += temp;
        else
            sunSum += temp;
    }
    printf("Monday: %d\nTuesday: %d\nWednesday: %d\nThursday: %d\nFriday: %d\nSaturday: %d\nSunday: %d\n", monSum, tuSum, wedSum, thurSum, friSum, satSum, sunSum);
    fclose(fp);
}

void PrintMostCalories()
{
    FILE * fp = fopen("calories.txt", "r");
    int maxCalorie = 0, args, garbageValue, currentCalorie; //"garbageValue" refers to the day of week on a given line from the file, which is irrelevant to computation.
    char maxCalorieFood[50] = {}, currentCalorieFood[50] = {};
    while(1)
    {
        args = fscanf(fp, "%s %d %d", currentCalorieFood, &garbageValue, &currentCalorie);
        if(args == -1)
        {
            break;
        }
        if(currentCalorie > maxCalorie)
        {
            maxCalorie = currentCalorie;
            strcpy(maxCalorieFood, currentCalorieFood);
        }
    }
    printf("The Food with the most calories was: %s with %d calories.\n", maxCalorieFood, maxCalorie);
    fclose(fp);
}

void ResetLog()
{
    FILE * fp = fopen("calories.txt", "w");
    fclose(fp);
    printf("Calorie Log has successfully been cleared.\n");
}
