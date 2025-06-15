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
    //     return Skaiciai{sitas.get_x() + other.get_x(), sitas.get_y() + other.get_y()}; // Sukuria naują objektą, pvz: objektas c = (a + b)
    // }

    Skaiciai<T> operator+(Skaiciai<T> &other) // galima ir šitaip
    {
        return Skaiciai{this->x + other.x, this->y + other.y}; // Sukuria naują objektą, pvz: objektas c = (a + b)
    }

    Skaiciai<T> operator++() // realizavome prefix ++obj
    {
        return Skaiciai{this->x++, this->y++};
    }

    // Norint padaryti postfix, yra skliaustus dar reikia pridėti skaičių x ir y duomenų tipą, kuris šiuo atveju yra T
    Skaiciai<T> operator++(T) // realizavome postfix obj++
    {
        return Skaiciai{this->x++, this->y++};
    }

    friend ostream& operator<<(ostream &out, Skaiciai &obj)
    {
        out << obj.get_x() << " " << obj.get_y();
        return out;
    }

};

int main() {
    Skaiciai<int> a{2, 8}, b{3, 20};
    
    cout <<"a+b:\tx = " << (a + b).get_x() << "\ty = " << (a + b).get_y() << endl;
    cout << "a: " << a << "\tb: " << b << endl;
    
    ++b;
    cout << b.get_y() << endl;

    a++;
    cout << a.get_y() << endl;
    return 0;
}