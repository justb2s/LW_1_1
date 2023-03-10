#include"../include/Constants.h"
#include"../include/moduleOne.h"

int main(int argc, char *argv[]){
    Matrix matrix = {};
    int errorCode = 0;

    if(MatrixInput::matrixInputFromConsole(argc, argv, matrix)
       == EXECUTION_ERROR){
        errorCode = MatrixInput::matrixInputFromFile(matrix);
    }

    if(errorCode == EXECUTION_ERROR){
        return EXECUTION_ERROR;
    }

    int rowJumpCount = 0;
    for(auto &it : matrix.array){
        std::cout << it << " ";
        rowJumpCount ++;
        if(rowJumpCount == matrix.rowSize){
            std::cout << std::endl;
            rowJumpCount = 0;
        }
    }
    
    system("pause");
    return EXECUTION_SUCCEED;
}