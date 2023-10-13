#include <stdio.h>

void combos(int score) {
    for (int touchdown = 0; touchdown <= score / 6; touchdown++) {
        for (int fieldgoal = 0; fieldgoal <= score / 3; fieldgoal++) {
            for (int safety = 0; safety <= score / 2; safety++) {
                for (int conversion = 0; conversion <= (score - (touchdown * 6 + fieldgoal * 3 + safety * 2)) / 8; conversion++) {
                    for (int tdfg = 0; tdfg <= (score - (touchdown * 6 + fieldgoal * 3 + safety * 2 + conversion * 8)) / 7; tdfg++) {
                        int remaining_score = score - (touchdown * 6 + fieldgoal * 3 + safety * 2 + conversion * 8 + tdfg * 7);
                        if (remaining_score == 0) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", conversion, tdfg, touchdown, fieldgoal, safety);
                        }
                    }
                }
            }
        }
    }
}

main() {
    int score;
    
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
 
        printf("Possible combinations of scoring plays:\n");
        combos(score);
    }
}
