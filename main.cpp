#include <stdio.h>
#include <string.h>

// Определение структуры SalesPeople
struct SalesPeople {
private:
    int snum;          // Номер продажи
    char *sname;      // Имя продавца
    char *city;       // Город продавца
    double comm;      // Комиссия продавца
public:
    // Метод для получения номера продажи, продавца, города, комиссии
    int get_snum() { return snum; }
    char* get_sname() { return sname; }
    char* get_city() { return city; }
    double get_comm() { return comm; }
    
    // Метод для вывода информации о продавце
    void print() {
        printf("snum=%d, sname=%s, city=%s, comm=%.2f\n", snum, sname, city, comm);
    }
    
    // Деструктор для освобождения памяти
    ~SalesPeople() {
        delete[] sname; // Освобождение памяти для имени
        delete[] city;  // Освобождение памяти для города
        printf(" объект успешно удален");
    }
    
    // Конструктор без параметров
    SalesPeople() : snum(0), sname(nullptr), city(nullptr), comm(0) {}

    // конструктор
    SalesPeople(int snum, const char *sname, const char *city, double comm) 
        : snum(snum), comm(comm) {
            // Выделение памяти для имени и города
            this->sname = new char[strlen(sname) + 1]; // +1 для символа конца строки
            strcpy(this->sname, sname); // Копирование имени
            this->city = new char[strlen(city) + 1]; // +1 для символа конца строки
            strcpy(this->city, city); // Копирование города
    }
};

int main() {
    SalesPeople sp0; // Создание объекта с помощью конструктора по умолчанию
    SalesPeople sp1(1, "Вика", "Москва", 0.5); // Создание объекта с параметрами
    sp1.print(); // Вывод информации о продавце
    printf("snum=%d", sp1.get_snum()); // Вывод номера продажи
    return 0;
}
