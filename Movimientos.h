#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include <string>

class Movimientos
{
    public:
        Movimientos();
        std::string getMovimiento();
        void setMov(std::string);

    private:
        std::string movimiento;
};

#endif //MOVIMIENTOS_H