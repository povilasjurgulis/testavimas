#include "main.h"
// Klasės operatoriai. Kai return *this, tai reikės po Skaiciai<T> padėti &
template<typename T>
class Skaiciai{

    private:
    T x, y;


    public:
    Skaiciai() = default;
    Skaiciai(T skaic, T skaicY) : x{skaic}, y{skaicY}{}
    ~Skaiciai(){};
    T get_x()  const { return x; }
    T get_y()  const { return y; }
    void set_sk(T skaic, T skaicY) { this->x = skaic; this->y = skaicY; }

    // friend Skaiciai<T> operator+(Skaiciai<T> &sitas, Skaiciai<T> &other) // galima ir šitaip (galima ištrinti žodį friend)
    // {
    //     return Skaiciai{sitas.get_x() + other.get_x(), sitas.get_y() + other.get_y()}; // Sukuria naują objektą, pvz: objektas c = (a + b)
    // }

    Skaiciai<T> operator+(const Skaiciai<T>& other) const // galima ir šitaip
    {
        return Skaiciai{this->x + other.x, this->y + other.y}; // Sukuria naują objektą, pvz: objektas c = (a + b)
    }

    Skaiciai<T>& operator++() // realizavome prefix ++obj
    {
        ++this->x;
        ++this->y;
        return *this;
    }

    // Norint padaryti postfix, skliaustuose dar reikia pridėti 'int', netgi jeigu T bus double ar string, ten vis tiek turės būti parašytas 'int'
    // Jeigu po Skaiciai<T> padėsi nuorodą &, tai ši operacija NEVEIKS, kadangi temp yra lokalus kintamasis, 
    // kuris bus sunaikintas išėjus iš funkcijos, tai gausis undefined behaviour su nuoroda &
    Skaiciai<T> operator++(int) // realizavome postfix obj++
    {
        Skaiciai temp(*this);
        this->x++;
        this->y++;
        return temp; // reikia grąžinti SENĄ reikšmę, o prieš jos grąžinimą padidinti dabartinę reikšmę
    }

    friend ostream& operator<<(ostream &out, const Skaiciai &obj)
    {
        out << obj.x << " " << obj.y;
        return out;
    }

    friend istream& operator>>(istream &in, Skaiciai &obj)
    {
        in >> obj.x >> obj.y;
        return in;
    }

    Skaiciai<T>& operator+=(const T &skaicius)
    {
        this->x += skaicius;
        this->y += skaicius;
        return *this;
    }
    Skaiciai<T>& operator+=(const Skaiciai &obj) 
    {
        this->x += obj.x; 
        this->y += obj.y;
        return *this; 
    }
    
};

int main() {
    Skaiciai<int> a{2, 8}, b{3, 20};
    
    cout <<"a+b:\tx = " << (a + b).get_x() << "\ty = " << (a + b).get_y() << endl;
    cout << "a: " << a << "\tb: " << b << endl;
    
    ++b;
    cout <<"++b : " << b << endl;

    a++;
    cout << "a++ : " << a << endl;

    Skaiciai<int> e;
    cout << "Iveskite objekto e skaicius x ir y: "; 
    cin >> e;
    cout << "e: " << e << endl;
    
    e+=a;
    cout << "e+=a : " << e << endl;

    a+=5;
    cout << "a+=5 : " << a << endl;

    return 0;
}