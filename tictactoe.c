#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int game(int arr[3][3], int x, int y);

int ifx(int arr[3][3], int x);
int ify(int arr[3][3], int y);

int winner(int arr[3][3]);

void inputx(int arr[3][3], int* x);
void inputy(int arr[3][3], int* y);

int drawCheck(int arr[3][3]);


int main() {

    int arr[3][3] = { 1, 2, 3 , 4, 5, 6, 7, 8, 9 };

    int x = 0;
    int y = 0;

    bool check;

    while (check = true) {
        game(arr, x, y);
        inputx(arr, &x);
        system("clear");
        ifx(arr, x);
        if (winner(arr) == 0) {
            check = false;
            printf("Player X won the game!\n");
            game(arr, x, y);
            break;
        }
        else if (drawCheck(arr) == 2) {
            check = false;
            printf("DRAW!\n");
            break;
        }
        game(arr, x, y);
        inputy(arr, &y);
        system("clear");
        ify(arr, y);
        if (winner(arr) == 1) {
            check = false;
            printf("Player O won the game!\n");
            game(arr, x, y);
            break;
        }
        else if (drawCheck(arr) == 2) {
            check = false;
            printf("DRAW!\n");
            break;
        }
        system("clear");
    }

    return 0;
}

int game(int arr[3][3], int x, int y) {
    printf("\n");
    int i;
    int j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (arr[i][j] == -1) {
                printf("X | ");
            }
            else if (arr[i][j] == -2) {
                printf("O | ");
            }
            else printf("%d | ", arr[i][j]);
        }
        printf("\n```````````\n");
    }
}


int ifx(int arr[3][3], int x) {
    if (x == 1) {
        arr[0][0] = -1;
    }
    if (x == 2) {
        arr[0][1] = -1;
    }
    if (x == 3) {
        arr[0][2] = -1;
    }
    if (x == 4) {
        arr[1][0] = -1;
    }
    if (x == 5) {
        arr[1][1] = -1;
    }
    if (x == 6) {
        arr[1][2] = -1;
    }
    if (x == 7) {
        arr[2][0] = -1;
    }
    if (x == 8) {
        arr[2][1] = -1;
    }
    if (x == 9) {
        arr[2][2] = -1;
    }
}

int ify(int arr[3][3], int y) {
    if (y == 1) {
        arr[0][0] = -2;
    }
    if (y == 2) {
        arr[0][1] = -2;
    }
    if (y == 3) {
        arr[0][2] = -2;
    }
    if (y == 4) {
        arr[1][0] = -2;
    }
    if (y == 5) {
        arr[1][1] = -2;
    }
    if (y == 6) {
        arr[1][2] = -2;
    }
    if (y == 7) {
        arr[2][0] = -2;
    }
    if (y == 8) {
        arr[2][1] = -2;
    }
    if (y == 9) {
        arr[2][2] = -2;
    }
}

void inputx(int arr[3][3], int* x) {
    int i, j;
    printf("Please enter the appropriate number for X: ");
    scanf("%d", x);

    if (*x > 9 || *x < 1 || arr[(*x - 1) / 3][(*x - 1) - (3 * ((*x - 1) / 3))] == -1 || arr[(*x - 1) / 3][(*x - 1) - (3 * ((*x - 1) / 3))] == -2)
        do {
            printf("Invalid choice! Enter the coordinate again: ");
            scanf("%d", x);
        } while (*x > 9 || *x < 1 || arr[(*x - 1) / 3][(*x - 1) - (3 * ((*x - 1) / 3))] == -1 || arr[(*x - 1) / 3][(*x - 1) - (3 * ((*x - 1) / 3))] == -2);
}

void inputy(int arr[3][3], int* y) {
    printf("Please enter the appropriate number for Y: ");
    scanf("%d", y);
    if (*y > 9 || *y < 1 || arr[(*y - 1) / 3][(*y - 1) - (3 * ((*y - 1) / 3))] == -1 || arr[(*y - 1) / 3][(*y - 1) - (3 * ((*y - 1) / 3))] == -2)
        do {
            printf("Invalid choice! Enter the coordinate again: ");
            scanf("%d", y);
        } while (*y > 9 || *y < 1 || arr[(*y - 1) / 3][(*y - 1) - (3 * ((*y - 1) / 3))] == -1 || arr[(*y - 1) / 3][(*y - 1) - (3 * ((*y - 1) / 3))] == -2);
}

int winner(int arr[3][3]) {
    if (arr[0][0] == -1 && arr[1][1] == -1 && arr[2][2] == -1) {
        return 0;
    }
    else if (arr[0][0] == -1 && arr[0][1] == -1 && arr[0][2] == -1) {
        return 0;
    }
    else if (arr[1][0] == -1 && arr[1][1] == -1 && arr[1][2] == -1) {
        return 0;
    }
    else if (arr[0][2] == -1 && arr[1][2] == -1 && arr[2][2] == -1) {
        return 0;
    }
    else if (arr[0][2] == -1 && arr[1][1] == -1 && arr[2][0] == -1) {
        return 0;
    }
    else if (arr[0][0] == -1 && arr[1][0] == -1 && arr[2][0] == -1) {
        return 0;
    }
    else if (arr[0][2] == -1 && arr[1][2] == -1 && arr[2][2] == -1) {
        return 0;
    }
    //////////////////////////////////////////////////////////////////////////
    else  if (arr[0][0] == -2 && arr[1][1] == -2 && arr[2][2] == -2) {
        return 1;
    }
    else if (arr[0][0] == -2 && arr[0][1] == -2 && arr[0][2] == -2) {
        return 1;
    }
    else if (arr[1][0] == -2 && arr[1][1] == -2 && arr[1][2] == -2) {
        return 1;
    }
    else if (arr[0][2] == -2 && arr[1][2] == -2 && arr[2][2] == -2) {
        return 1;
    }
    else if (arr[0][2] == -2 && arr[1][1] == -2 && arr[2][0] == -2) {
        return 1;
    }
    else if (arr[0][0] == -2 && arr[1][0] == -2 && arr[2][0] == -2) {
        return 1;
    }
    else if (arr[0][2] == -2 && arr[1][2] == -2 && arr[2][2] == -2) {
        return 1;
    }
    else {
        return 2;
    }
}

int drawCheck(int arr[3][3]) {
    if ((arr[0][0] == -1 || arr[0][0] == -2)
        && (arr[0][1] == -1 || arr[0][1] == -2)
        && (arr[0][2] == -1 || arr[0][2] == -2)
        && (arr[1][0] == -1 || arr[1][0] == -2)
        && (arr[1][1] == -1 || arr[1][1] == -2)
        && (arr[1][2] == -1 || arr[1][2] == -2)
        && (arr[2][0] == -1 || arr[2][0] == -2)
        && (arr[2][1] == -1 || arr[2][1] == -2)
        && (arr[2][2] == -1 || arr[2][2] == -2)) {
        return 2;
    }
}