#include <stdio.h>
#include <string.h>

struct SalesPeople {
private:
    int snum;
    char *sname;
    char *city;
    double comm;

public:
    int get_snum() { return snum; }
    char* get_sname() { return sname; }
    char* get_city() { return city; }
    double get_comm() { return comm; }
    
    void print() {
        printf("snum=%d, sname=%s, city=%s, comm=%.2f\n", snum, sname, city, comm);
    }

    SalesPeople() : snum(0), sname(nullptr), city(nullptr), comm(0) {}

    SalesPeople(int snum, const char *sname, const char *city, double comm) {
        this->snum = snum;
        this->sname = new char[strlen(sname) + 1]; // Правильное выделение памяти
        strcpy(this->sname, sname);
        this->city = new char[strlen(city) + 1]; // Правильное выделение памяти
        strcpy(this->city, city);
        this->comm = comm;
    }

    // Деструктор для освобождения памяти
    ~SalesPeople() {
        delete[] sname;
        delete[] city;
    }

    // Конструктор копирования
    SalesPeople(const SalesPeople &other) {
        snum = other.snum;
        comm = other.comm;
        sname = new char[strlen(other.sname) + 1];
        strcpy(sname, other.sname);
        city = new char[strlen(other.city) + 1];
        strcpy(city, other.city);
    }

    // Оператор присваивания
    SalesPeople& operator=(const SalesPeople &other) {
        if (this != &other) {
            delete[] sname;
            delete[] city;

            snum = other.snum;
            comm = other.comm;
            sname = new char[strlen(other.sname) + 1];
            strcpy(sname, other.sname);
            city = new char[strlen(other.city) + 1];
            strcpy(city, other.city);
        }
        return *this;
    }
};

int maaain() {
    SalesPeople sp0;
    SalesPeople sp1 = SalesPeople(1, "Вика", "Москва", 0.5);
    sp1.print();
    printf("snum=%d", sp1.get_snum());

    return 0;
}
