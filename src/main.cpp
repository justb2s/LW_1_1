#include"../include/Constants.h"
#include"../include/moduleOne.h"
#include"../include/moduleTwo.h"

int main(int argc, char *argv[]){
    Matrix matrix = {};
    Matrix sortedMatrix = {};

    if(MatrixInput::matrixInputFromConsole(argc, argv, matrix)
       == EXECUTION_ERROR){

        matrix.array.clear();
        matrix.rowSize = MAX_MATRIX_ROWS;

        if(MatrixInput::matrixInputFromFile(matrix) 
           == EXECUTION_ERROR){
            return EXECUTION_ERROR;
        }
    }

    MatrixOutput::outputMatrix(matrix);

    MatrixSort::sortMatrixByIncreaseOfRowSum(matrix);

    MatrixOutput::outputMatrix(matrix);

    
    
    system("pause");
    return EXECUTION_SUCCEED;
}