#include <stdio.h>

struct complex {
    double re, im;
    
    // Конструктор
    complex(double re, double im) {
        this->re = re;
        this->im = im;
    }

    // Оператор сложения с другим комплексным числом
    complex operator+(const complex& other) {
        return complex(this->re + other.re, this->im + other.im);
    }

    // Оператор сложения с действительным числом
    complex operator+(double re) {
        return complex(this->re + re, this->im);
    }

    // Оператор вычитания
    complex operator-(const complex& other) {
        return complex(this->re - other.re, this->im - other.im);
    }
};

int maain() {
    complex c1(1, 2); // Создаем первое комплексное число (1 + 2i)
    complex c2(3, 4); // Создаем второе комплексное число (3 + 4i)
    complex c3 = c1 + c2; // Сложение комплексных чисел
    complex c4 = c1 + c2;
    complex c5 = c1 - c2; // Вычитание комплексных чисел
    complex c6 = c1 + 5.0; // Сложение с действительным числом

    // Печать результата
    printf("%.2f %.2f", c6.re, c6.im);

    return 0;
}
