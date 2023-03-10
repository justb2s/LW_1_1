#include"../include/Constants.h"
#include"../include/moduleOne.h"
#include"../include/moduleTwo.h"
#include"../include/moduleThree.h"
#include"../include/moduleFour.h"

int main(int argc, char *argv[]){
    Matrix matrix = {};
    Matrix sortedMatrix = {};
    int aAvegare = 0;
    int elementCount = 0;

    if(MatrixInput::matrixInputFromConsole(argc, argv, matrix)
       == EXECUTION_ERROR){

        matrix.array.clear();
        matrix.rowSize = MAX_MATRIX_ROWS;

        if(MatrixInput::matrixInputFromFile(matrix) 
           == EXECUTION_ERROR){
            return EXECUTION_ERROR;
        }
    }

    MatrixOutput::outputMatrixToConsole(matrix);

    MatrixSort::sortMatrixByIncreaseOfRowSum(matrix);

    MatrixOutput::outputMatrixToConsole(matrix);

    MatrixCalculation::ariphmeticAverage(matrix, aAvegare);

    std::cout << std::endl << "Matrix average: " 
              << aAvegare << std::endl;

    MatrixCalculation::elementCount(matrix, elementCount);

    std::cout << std::endl << "Element count: " 
              << elementCount << std::endl;

    MatrixOutput::outputMatrixToFile(matrix,
                                     aAvegare,
                                     elementCount);

    std::cout << std::endl;
    system("pause");
    return EXECUTION_SUCCEED;
}