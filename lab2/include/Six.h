#ifndef SIX_H
#define SIX_H
#include <string>
#include <initializer_list>

class Six {
public:
    // === Конструкторы ===
    Six();
    Six(const size_t &n, unsigned char t);
    Six(const std::initializer_list<unsigned char> &items);
    Six(const std::string &t);
    Six(const Six& other);           
    Six(Six&& other) noexcept; 

    // === Деструктор ===
    virtual ~Six() noexcept;

    // === Арифметические операции ===
    Six sum(Six &other);
    Six difference(Six &other);
    Six copy();

    bool greater(const Six &other);
    bool less(const Six &other);
    bool equal(Six &other);

    // === Геттеры ===
    size_t get_length() const;
    const unsigned char* get_value() const;

    // === Распечатки ===
    void print_value() const;
    void print_length() const;

private:
    unsigned char* value;
    size_t length;
};

#endif
