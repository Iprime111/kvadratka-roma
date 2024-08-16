#include <stdio.h>
#include <TXLib.h>
#include <math.h>

enum NUMBER_OF_SOLUTIONS {
    ERROR_NUMBER,
    NO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INF_NUMBER_OF_SOLUTIONS
};

struct se_solutions{
    double x1, x2;
    NUMBER_OF_SOLUTIONS num_of_sol;
};

bool is_var_equal_to_zero(double val);
void enter_se_parameters(double *a, double *b, double *c);
void solve_square_equation(double a, double b, \
double c, struct se_solutions *ptr_struct);
void print_solutions(struct se_solutions solutions);

const double EPS = 0.0000001;

int main() {
    double a = NAN, b = NAN, c = NAN; // коэффициенты кв.
    struct se_solutions solutions = {
        NAN, NAN,
        ERROR_NUMBER
    };

    enter_se_parameters(&a, &b, &c);
    solve_square_equation(a, b, c, &solutions);
    print_solutions(solutions);

    return 0;
}

bool is_var_equal_to_zero(double val) {
    return (fabs(val) < EPS);
}

void enter_se_parameters(double *a, double *b, double *c) {
    printf("Введите значения коэффициентов\n");

    printf("Первый коэффициент: ");
    scanf("%lf", a);

    printf("Второй коэффициент: ");
    scanf("%lf", b);

    printf("Третий коэффициент: ");
    scanf("%lf", c);
}

void solve_square_equation(double a, double b, double c,
struct se_solutions *ptr_struct) {
    double discriminant = NAN;

    if (is_var_equal_to_zero(a)) {
        if (is_var_equal_to_zero(b)) {
            if (is_var_equal_to_zero(c)) {
                ptr_struct->num_of_sol =
                INF_NUMBER_OF_SOLUTIONS;
            }
            else {
                ptr_struct->num_of_sol
                = NO_SOLUTIONS;
            }
        }
        else {
            ptr_struct->x1 =
            ptr_struct->x2 = -c/b;
            ptr_struct->num_of_sol
            = ONE_SOLUTION;
        }
    }
    else {
        discriminant = b*b - 4*a*c;
        if (discriminant > EPS) {
            ptr_struct->x1 =
            (-b + sqrt(discriminant))/(2*a);
            ptr_struct->x2 =
            (-b - sqrt(discriminant))/(2*a);
            ptr_struct->num_of_sol =
            TWO_SOLUTIONS;
        }
        else if (is_var_equal_to_zero(discriminant)) {
            ptr_struct->x1 =
            ptr_struct->x2 = -b/(2*a);
            ptr_struct->num_of_sol =
            ONE_SOLUTION;
        }
        else {
            ptr_struct->num_of_sol =
            NO_SOLUTIONS;
        }
    }
}

void print_solutions(struct se_solutions solutions) {
    switch(solutions.num_of_sol) {
        case ERROR_NUMBER:
            printf("ERROR");
            break;
        case NO_SOLUTIONS:
            printf("Нет решений");
            break;
        case ONE_SOLUTION:
            printf("Одно решение: %lf", solutions.x1);
            break;
        case TWO_SOLUTIONS:
            printf("Два решения: %lf %lf",
            solutions.x1, solutions.x2);
            break;
        case INF_NUMBER_OF_SOLUTIONS:
            printf("Бесконечное количество решений");
            break;
        default:
            printf("ERRORdefault");
    }
}
