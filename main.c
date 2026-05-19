#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char names[5][11];
    int scores[5][13];

    // Läser in namn och poäng
    for (int i = 0; i < 5; i++) {
        scanf("%10s", names[i]);
        for (int j = 0; j < 13; j++)
            scanf("%d", &scores[i][j]);
    }

    // Gör första bokstaven stor och resten små
    for (int i = 0; i < 5; i++) {
        names[i][0] = toupper(names[i][0]);
        for (int j = 1; names[i][j]; j++)
            names[i][j] = tolower(names[i][j]);
    }

    // Räkna ut medelpoäng per elev och gruppens totala snitt
    double avg[5];
    double total = 0;
    for (int i = 0; i < 5; i++) {
        double sum = 0;
        for (int j = 0; j < 13; j++) sum += scores[i][j];
        avg[i] = sum / 13.0;
        total += avg[i];
    }
    double groupAvg = total / 5.0;

    // Räknar ut eleven med högst medelpoäng
    int best = 0;
    for (int i = 1; i < 5; i++)
        if (avg[i] > avg[best]) best = i;
    printf("%s\n", names[best]);

    // Räknar ut elever som ligger under gruppens snitt
    for (int i = 0; i < 5; i++)
        if (avg[i] < groupAvg)
            printf("%s\n", names[i]);

    return 0;
}


