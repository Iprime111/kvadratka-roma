#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "structures.h"
#include "enter_print.h"
#include "utils.h"

void enter_se_parameters(double *a, double *b, double *c) {
    printf("Введите значения трех коэффициентов через пробел\n");
    for (int tryCounter = 0; tryCounter < 3; tryCounter++) {
        int scanfResult = scanf("%lf %lf %lf", a, b, c);

        if (!null_pointer_check(a, b, c)) {
            printf("Ошибка -- невозможный адрес переменной\n");
        }

        if (!is_parameters_valid(*a, *b, *c)) {
            printf("Невозможные значения\n");
        }

        if (scanfResult == 3) {
            break;
        }
        else if (tryCounter == 2) {
            printf("Ошибка\nКонец программы\n");
        }
        else {
            printf("Ошибка, введите снова\n");
        }

        clear_buffer();
    }
}

void print_solutions(const SE_SOLUTIONS *solutions) {
    switch(solutions->num_of_sol) {
        case ERROR_NUMBER:
            printf("Ошибка решения\n");
            break;
        case NO_SOLUTIONS:
            printf("Нет решений\n");
            break;
        case ONE_SOLUTION:
            printf("Одно решение: %lf\n", solutions->x1);
            break;
        case TWO_SOLUTIONS:
            printf("Два решения: %lf %lf\n", solutions->x1, solutions->x2);
            break;
        case INF_NUMBER_OF_SOLUTIONS:
            printf("Бесконечное количество решений\n");
            break;
        default:
            printf("Ошибка\n");
            break;
    }
}
