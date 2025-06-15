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

    bool operator==(const Skaiciai &obj) const
    {
        if(this->x == obj.x && this->y == obj.y)
            return true;
        else return false;
    }
    
    bool operator!=(const Skaiciai &obj) const
    {
        if(*this == obj)
            return false;
        else return true;
    }

    Skaiciai<T>& operator=(const Skaiciai &obj) // copy assignment operator
    {
        // if(this==&obj) patikrina, ar adresai sutampa, kad žinotume, ar ne tą patį elementą kopijuojame
        if(this==&obj) // Negalima rašyti if(*this==obj), nes čia tiesiog patikslina ar visi elementai tokie patys
        {
            return *this;
        }
        this->x = obj.x;
        this->y = obj.y;
        return *this;
    }

    Skaiciai<T>& operator=(Skaiciai &&obj) noexcept// move assignment operator
    {
        if(this==&obj)
        {
            return *this;
        }
        this->x = std::move(obj.x);
        this->y = std::move(obj.y);
        return *this;
    }
    
    Skaiciai(const Skaiciai &obj) : x{obj.x}, y{obj.y}{} // copy konstruktorius
    Skaiciai(Skaiciai &&obj) noexcept : x{std::move(obj.x)}, y{std::move(obj.y)}{} // move konstruktorius
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

    e=a;
    cout << "e=a : " << e << endl;
    return 0;
}