#include <stdio.h>
#include "stdbool.h"

struct Number {
    int num;
    bool show[7];
};

struct Number number_list[] = {
        {0, {1, 1, 1, 0, 1, 1, 1}},
        {1, {0, 1, 0, 0, 0, 1, 0}},
        {2, {1, 1, 0, 1, 1, 0, 1}},
        {3, {1, 1, 0, 1, 0, 1, 1}},
        {4, {0, 1, 1, 1, 0, 1, 0}},
        {5, {1, 0, 1, 1, 0, 1, 1}},
        {6, {1, 0, 1, 1, 1, 1, 1}},
        {7, {1, 1, 0, 0, 0, 1, 0}},
        {8, {1, 1, 1, 1, 1, 1, 1}},
        {9, {1, 1, 1, 1, 0, 1, 1}},
};

void writeLine_1(struct Number *number);
void writeLine_2_3(struct Number *number);
void writeLine_4(struct Number *number);
void writeLine_5_6(struct Number *number);
void writeLine_7(struct Number *number);
void writeLine(int line, struct Number *number);
int chatToNumber(char n);
void writeMoreNumber(char *number);

int main(int argc, char **argv){
    if (argc != 2)
        printf("Please Enter one number.");
    writeMoreNumber(argv[1]);
    return 0;
}

void writeMoreNumber(char *number) {
    for (int i = 1; i <= 7; i++) {
        for (char *ch = number; *ch != 0; ch++) {
            int n = chatToNumber(*ch);
            if (n == -1)
                continue;
            struct Number *num = number_list + n;
            writeLine(i, num);
            printf("   ");
        }
        printf("\n");
    }
}

int chatToNumber(char n) {
    switch (n) {
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case '0': return 0;
        default: return -1;
    }
}

void writeLine(int line, struct Number *number) {
    switch (line) {
        case 1:
            writeLine_1(number);
            break;
        case 2:
        case 3:
            writeLine_2_3(number);
            break;
        case 4:
            writeLine_4(number);
            break;
        case 5:
        case 6:
            writeLine_5_6(number);
            break;
        case 7:
            writeLine_7(number);
            break;
        default:
            break;
    }
}

void writeLine_1(struct Number *number) {
    if (number->show[0])
        printf("* * * * *");
    else if (number->show[1] && number->show[2])
        printf("*       *");
    else if (number->show[1])
        printf("        *");
    else if (number->show[2])
        printf("*        ");
    else
        printf("         ");
}

void writeLine_2_3(struct Number *number) {
    if (number->show[1] && number->show[2])
        printf("*       *");
    else if (number->show[1])
        printf("        *");
    else if (number->show[2])
        printf("*        ");
    else
        printf("         ");
}

void writeLine_4(struct Number *number) {
    if (number->show[3])
        printf("* * * * *");
    else if (number->show[1] && number->show[2] || number->show[4] && number->show[5])
        printf("*       *");
    else if (number->show[1] || number->show[5])
        printf("        *");
    else if (number->show[2] || number->show[4])
        printf("*        ");
    else
        printf("         ");
}

void writeLine_5_6(struct Number *number) {
    if (number->show[4] && number->show[5])
        printf("*       *");
    else if (number->show[5])
        printf("        *");
    else if (number->show[4])
        printf("*        ");
    else
        printf("         ");
}

void writeLine_7(struct Number *number) {
    if (number->show[6])
        printf("* * * * *");
    else if (number->show[4] && number->show[5])
        printf("*       *");
    else if (number->show[5])
        printf("        *");
    else if (number->show[4])
        printf("*        ");
    else
        printf("         ");
}
