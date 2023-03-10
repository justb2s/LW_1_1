#include"../include/moduleFour.h"

void MatrixOutput::outputMatrixToConsole(const Matrix &src){
    std::string dst = "";
    std::cout << std::endl << "Matrix: " << std::endl;
    int rowJumpCount = 0;
    for(auto &matrixIterator : src.array){
        std::cout << matrixIterator;
        std::cout << ' ';
        rowJumpCount ++;
        if(rowJumpCount == src.rowSize){
            std::cout << std::endl;
            rowJumpCount = 0;
        }
    }
}

void MatrixOutput::outputMatrixToFile(const Matrix &src,
                                      const int &avr,
                                      const int &size){
    std::string outputFilePath = " ";
    std::string outputString = " ";
    int rowJumpCount = 0;

    getFileName(GET_FILE_FOR_OUPUT_TEXT, outputFilePath);   

    writeLineToFile(outputFilePath, "\r\nMatrix: ");
    outputString.append("\n");
    for(auto &matrixIterator : src.array){
        outputString.append(std::to_string(matrixIterator));
        outputString.append(" ");
        rowJumpCount ++;
        if(rowJumpCount == src.rowSize){
            outputString.append("\n");
            writeLineToFile(outputFilePath, outputString);
            outputString = "";
            rowJumpCount = 0;
        }
    }  

    outputString.append("\n");
    outputString.append("Avegare = ");
    outputString.append(std::to_string(avr));
    writeLineToFile(outputFilePath, outputString);

    outputString = " ";

    outputString.append("\r\n");
    outputString.append("Element count = ");
    outputString.append(std::to_string(size));
    writeLineToFile(outputFilePath, outputString);
}