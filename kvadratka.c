#include<stdio.h>
#include<TXLib.h>
#include<math.h>

int main() {
    double a, b, c; //������������
    double x1, x2; //�����
    double discriminant;
    printf("������� ������������ ����������� ���������\n");
    printf("������: ");
    scanf("%lf", &a);
    printf("������: ");
    scanf("%lf", &b);
    printf("������: ");
    scanf("%lf", &c);

    if (a < 0.0000001 && a > -0.0000001) {
        if (b < 0.0000001 && b > -0.0000001) {
            printf("��� ������");
        }
        else {
            x1 = x2 = -(c/b);
            printf("���� ������: %lf", x1);
        }
    }
    else {
        discriminant = b*b - 4*a*c;
        if (discriminant >= 0.0000001) {
            x1 = (-b + sqrt(discriminant))/(2*a);
            x2 = (-b - sqrt(discriminant))/(2*a);
            printf("��� �����: %lf, %lf", x1, x2);
        }
        else if (discriminant < 0.0000001 && \
        discriminant > -0.0000001) {
            x1 = x2 = -b/(2*a);
            printf("���� ������: %lf", x1);
        }
        else {
            printf("��� ������");
        }
    }
    return 0;
}

