#pragma once

#include"./Constants.h"

namespace MatrixInput{
    int matrixInputFromFile(Matrix &);

    int matrixInputFromConsole(const int &, 
                               char *[],
                               Matrix &);
}