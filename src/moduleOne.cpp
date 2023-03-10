#include"../include/moduleOne.h"

int MatrixInput::matrixInputFromFile(Matrix &src){
    std::string sourceFilePath = " ";
    std::string fileInputString = " ";

    getFileName(GET_FILE_FOR_MATRIX_TEXT, sourceFilePath);
    if(readLineFromFile(sourceFilePath, fileInputString) 
       == EXECUTION_ERROR){
        return EXECUTION_ERROR;
    }
    return parseStringMatrix(fileInputString, src);
}

int MatrixInput::
    matrixInputFromConsole(const int &consoleArgumentCount, 
                           char *consoleArgumentValue[], 
                           Matrix &dst){
    std::vector<std::string> consoleInput = {};
    
    if(consoleArgumentCount < 1){
        return EXECUTION_ERROR;
    }

    for(auto consoleInputIterator = 0; 
             consoleInputIterator < consoleArgumentCount; 
             consoleInputIterator++){
        consoleInput
        .push_back(consoleArgumentValue[consoleInputIterator]);
    }

    for(auto vectorIterator = consoleInput.begin();
             vectorIterator != consoleInput.end();
             vectorIterator ++){
        if(*vectorIterator == "-mat"){
            return parseStringMatrix(*(vectorIterator+1), dst);
        }
    }
    return EXECUTION_ERROR;
}