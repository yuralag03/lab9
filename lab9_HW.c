#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    setlocale(LC_ALL, "");
    int continue_program;

    do {
        char symbol;
        int r;
        int i, j;
        int size;

        printf("Введите символ из которого будет строиться фигура: ");
        scanf(" %c", &symbol);

        printf("Введите радиус r: ");
        scanf("%d", &r);

        size = 2 * r;

        printf("Квадрат с вписанной окружностью (r=%d):\n", r);

        for (i = 0; i <= size; i++)
        {
            for (j = 0; j <= size; j++)
            {
                int x = j - r;
                int y = i - r;

                int dist_sq = x * x + y * y;

                int on_square = (i == 0 || i == size || j == 0 || j == size);

                int on_circle = (dist_sq >= r * r - r && dist_sq <= r * r + r);

                if (on_square || on_circle) {
                    printf("%c", symbol);
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("\nПродолжить? (Да - введите любое число. Нет - введите 0): ");
        scanf("%d", &continue_program);
        printf("\n");

    } while (continue_program != 0);

    printf("Программа завершена.\n");
    system("pause");
}