#pragma once

#include"./Constants.h"

namespace MatrixOutput{
    void outputMatrixToConsole(const Matrix &);

    void outputMatrixToFile(const Matrix &,
                            const int &,
                            const int &);
}