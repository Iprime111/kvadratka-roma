#include<stdio.h>
#include<TXLib.h>
#include<math.h>

int main() {
    double a, b, c; //коэффициенты
    double x1, x2; //корни
    double discriminant;
    printf("Введите коэффициенты квадратного уравнения\n");
    printf("Первый: ");
    scanf("%lf", &a);
    printf("Второй: ");
    scanf("%lf", &b);
    printf("Третий: ");
    scanf("%lf", &c);

    if (a < 0.0000001 && a > -0.0000001) {
        if (b < 0.0000001 && b > -0.0000001) {
            printf("Нет корней");
        }
        else {
            x1 = x2 = -(c/b);
            printf("Один корень: %lf", x1);
        }
    }
    else {
        discriminant = b*b - 4*a*c;
        if (discriminant >= 0.0000001) {
            x1 = (-b + sqrt(discriminant))/(2*a);
            x2 = (-b - sqrt(discriminant))/(2*a);
            printf("Два корня: %lf, %lf", x1, x2);
        }
        else if (discriminant < 0.0000001 && \
        discriminant > -0.0000001) {
            x1 = x2 = -b/(2*a);
            printf("Один корень: %lf", x1);
        }
        else {
            printf("Нет корней");
        }
    }
    return 0;
}

