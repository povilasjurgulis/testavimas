#include "main.h"
template<typename T>
class Skaiciai{

    private:
    T x, y;


    public:
    Skaiciai(T skaic, T skaicY) : x{skaic}, y{skaicY}{}
    T get_x()  const { return x; }
    T get_y()  const { return y; }
    void set_sk(T &skaic, T &skaicY) { this->x = skaic; this->y = skaicY; }

    // friend Skaiciai<T> operator+(Skaiciai<T> &sitas, Skaiciai<T> &other) // galima ir šitaip (galima ištrinti žodį friend)
    // {
    //     return Skaiciai{sitas.get_x() + other.get_x(), sitas.get_y() + other.get_y()};
    // }

    // Skaiciai<T> operator+(Skaiciai<T> &other) // galima ir šitaip
    // {
    //     return Skaiciai{this->x + other.x, this->y + other.y};
    // }

    Skaiciai<T> operator+(Skaiciai<T> &other) // galima ir šitaip
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Skaiciai<T> operator++() // realizavome tik ++obj (bet ne obj++)
    {
        return Skaiciai{this->x++, this->y++};
    }
};

int main() {
    Skaiciai<int> a{2, 8}, b{3, 20};
    // Skaiciai<int> c = a + b;
    // cout << c.get_sk();
    cout << (a + b).get_x() << endl;

    ++b;
    cout << b.get_y() << endl;
    return 0;
}