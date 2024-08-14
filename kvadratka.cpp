#include<stdio.h>
#include<TXLib.h>
#include<math.h>

int main() {
    const double EPS = 0.0000001;
    double a = NAN, b = NAN, c = NAN; //коэффициенты
    double x1 = NAN, x2 = NAN; //корни
    double discriminant = NAN;

    printf("Введите коэффициенты квадратного уравнения\n");
    printf("Первый: ");
    scanf("%lf", &a);

    printf("Второй: ");
    scanf("%lf", &b);

    printf("Третий: ");
    scanf("%lf", &c);

    if (fabs(a) < EPS) {

        if (fabs(b) < EPS) {

            if (fabs(c) < EPS) {
                printf("Решение уравнения -- множество ");
                printf("действительных чисел");
            }

            else {
                printf("Нет корней");
            }
        }

        else {
            x1 = x2 = -(c/b);
            printf("Один корень: %lf", x1);
        }
    }

    else {
        discriminant = b*b - 4*a*c;

        if (discriminant >= EPS) {
            x1 = (-b + sqrt(discriminant))/(2*a);
            x2 = (-b - sqrt(discriminant))/(2*a);
            printf("Два корня: %lf %lf", x1, x2);
        }

        else if (fabs(discriminant) < EPS) {
            x1 = x2 = -b/(2*a);
            printf("Один корень: %lf", x1);
        }

        else {
            printf("Нет корней");
        }
    }

    return 0;
}
