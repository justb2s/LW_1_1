#include"../include/moduleTwo.h"

int MatrixSort::
    sortMatrixByIncreaseOfRowSum(Matrix &src){
    std::vector<int> sum = {};
    int currentSum = 0;
    int currentRow = 0;
    int currentRowSize = 0;

    for(auto &matrixIterator : src.array){
        currentSum += matrixIterator;
        currentRowSize ++;

        if(currentRowSize == src.rowSize){
            sum.push_back(currentSum);
            currentSum = RESET_NUMBER;
            currentRowSize = RESET_NUMBER;
        }
    }

    for(auto rowIterator = 1;
        rowIterator < (src.array.size() / src.rowSize);
        rowIterator++){
        if(sum[rowIterator-1] < sum[rowIterator]){
            std::swap(sum[rowIterator-1], sum[rowIterator]);
            for(auto arrayRowIterator 
                = (rowIterator-1) * src.rowSize;
                arrayRowIterator < rowIterator * src.rowSize;
                arrayRowIterator ++){
                std::swap(src.array[arrayRowIterator],
                          src.array[arrayRowIterator 
                                    + src.rowSize]);
            }
            rowIterator = RESET_NUMBER;
        }
    }

    return EXECUTION_SUCCEED;
}