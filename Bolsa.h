#ifndef BOLSA_H
#define BOLSA_h

#include <string>

class Bolsa{
    public:
        Bolsa();
        Bolsa(std::string, int);
    private:
        std::string agua, frutitas, juguetes;
        int capasidad;
};

#endif //BOLSA_H