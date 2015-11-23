#ifndef RCOMPONENTTYPE_H
#define RCOMPONENTTYPE_H

#include <bitset>

#include "BitSize.h"

class rComponentType
{
public:
    rComponentType();
    public:
        int id;
        std::bitset<BITSIZE> bit;
};

#endif // RCOMPONENTTYPE_H
