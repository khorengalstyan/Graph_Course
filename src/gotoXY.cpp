#include <cstdio>

#include "../include/gotoXY.hpp"


void gotoXY(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}
