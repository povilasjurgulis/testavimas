#include "main.h"
// Daugialypis (multiple) paveldėjimas (inheritance)
class Zmogus {
  protected:
      int amzius;
      std::string vardas;
  public:
      Zmogus(int amz = 0, std::string v = "") : amzius{amz}, vardas{v} { std::cout<<"Zmogus K.\n";}
      int getAmzius() const { return amzius; }
      std::string getVardas() const { return vardas; }
      ~Zmogus (){std::cout<<"Zmogus dest\n";}
};

class Darbuotojas {
  protected:
      int alga;
  public:
      Darbuotojas(int alg = 0) : alga{alg} { std::cout<<"Darbuotojas K.\n";}
      int getAlga() const { return alga; }
    ~Darbuotojas (){std::cout<<"Darbuotojas dest\n";}
};

// Studentas visgi yra žmogus :) ir tuo pat metu gali būti dirbantis!
// Čia kaip tik ir demonstruojamas paveldėjimas iš kelių klasių vienu metu ir iš Zmogus, ir Darbuotojas
class Studentas : public Zmogus, public Darbuotojas {
  private:
    double vidurkis; // mokymosi vidurkis
  public:
    Studentas(int amz = 0, std::string v = "", int alg = 0, double avg = 0) : Zmogus{amz, v}, Darbuotojas{alg}, vidurkis{avg} 
    { std::cout<<"Studentas K.\n"; }
    int getVidurkis() const { return vidurkis; }
    ~Studentas (){std::cout<<"Studentas dest\n";}
};

int main() {
  Studentas s1{20, "Jonas", 1000, 7.5};
  Studentas s2{18, "Petras"};
  std::cout << s1.getVardas() << " uzdirba: " << s1.getAlga() << std::endl;
  std::cout << s2.getVardas() << " uzdirba: " << s2.getAlga() << std::endl;
    return 0;
}