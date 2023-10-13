#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    //printf("Insert text file name: ");
    //char name;
    //scanf("%c", &name);
    //printf("%c \n", name);
    
    FILE *numFile = fopen("test.txt", "r");
    int size = 0;
    float stat = 0;
    float nums[12];
    char months[12][15] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    if (NULL == numFile) {
        printf("file can't be opened \n");
    } else {
        const unsigned maxLength = 256;
        char buffer[maxLength];
        
        while (fgets(buffer, maxLength, numFile)){
            //printf("%s", buffer);
            nums[size] = atof(buffer);
            size += 1;
        }
        int x;
        printf("Monthly sales report for 2022\n\n");
        printf("Sales \t\t Month\n\n");
        for (x = 0; x < 12; x++){
            printf("%.2f \t %s \n", nums[x], months[x]);
        }
        
        printf("\nSales summary:\n\n");
        float max = nums[0];
        int maxM = 0;
        float min = nums[0];
        int minM = 0;
        float ave = 0;
        for (x = 0; x < 12; x++){
            if(nums[x] < min){
                min = nums[x];
                minM = x;
            }
            if (nums[x] > max){
                max = nums[x];
                maxM = x;
           }
           ave += nums[x];
        }
        ave = ave/12;
        printf("Minimum sales: \t %.2f \t (%s) \n", min, months[minM]);
        printf("Maximum sales: \t %.2f \t (%s) \n", max, months[maxM]);
        printf("Average sales: \t %.2f\n\n", ave);
        
        float ave1;
        for (x = 0; x < 6; x++){
            ave1 += nums[x];
        }
        ave1 = ave1/6;
        
        float ave2;
        for (x = 1; x < 7; x++){
            ave2 += nums[x];
        }
        ave2 = ave2/6;
        
        float ave3;
        for (x = 2; x < 8; x++){
            ave3 += nums[x];
        }
        ave3 = ave3/6;
        
        float ave4;
        for (x = 3; x < 9; x++){
            ave4 += nums[x];
        }
        ave4 = ave4/6;
        
        float ave5;
        for (x = 4; x < 10; x++){
            ave5 += nums[x];
        }
        ave5 = ave5/6;
        
        float ave6;
        for (x = 5; x < 11; x++){
            ave6 += nums[x];
        }
        ave6 = ave6/6;
        
        float ave7;
        for (x = 6; x < 12; x++){
            ave7 += nums[x];
        }
        ave7 = ave7/6;
        
        printf("Six-Month Moving Average Report:\n\n");
        printf("January\t- June \t\t %.2f\n", ave1);
        printf("Febuary\t- July \t\t %.2f\n", ave2);
        printf("March \t- August \t %.2f\n", ave3);
        printf("April \t- September \t %.2f\n", ave4);
        printf("May \t- October \t %.2f\n", ave5);
        printf("June \t- November \t %.2f\n", ave6);
        printf("July \t- December \t %.2f\n\n", ave7);
        
        printf("Sales Report (Highest to Lowest):\n\n");
        printf("Sales \t\t Month\n\n");
        
        int i;
        float tempmax = 0;
        int mon;
        for (x = 0; x < 12; x++){
            tempmax = 0;
            mon = 0;
            for (i = 0; i < 12; i++){
                if (nums[i] > tempmax){
                    mon = i;
                    tempmax = nums[i];
                }
            }
            printf("%.2f \t %s \n", tempmax, months[mon]);
            nums[mon] = 0;
        }
    }
    
    fclose(numFile);
}
