#include"../include/moduleThree.h"

int MatrixCalculation::ariphmeticAverage(const Matrix &src, 
                                         int &dst){
    dst = 0;

    for(auto &vectorIterator : src.array){
        dst += vectorIterator;
    }

    dst = dst / src.array.size();
    return EXECUTION_SUCCEED;
}
    
int MatrixCalculation::elementCount(const Matrix &src,
                                    int &dst){
    dst = src.array.size();
    return EXECUTION_SUCCEED;
}