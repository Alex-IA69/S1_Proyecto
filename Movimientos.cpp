#include <iostream>
#include <string>
#include <vector>

#include <fstream>
#include <time.h>

#include "Movimientos.h"



Movimientos::Movimientos()
{
    movimiento = "";
}

std::string Movimientos::getMovimiento()
{
    return movimiento;
}

void Movimientos::setMov(std::string mov_)
{
    movimiento = mov_;
}
