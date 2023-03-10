#include"../include/Constants.h"

int getFileName(const char *src, std::string &dst){
    std::cout << src;
    std::cin >> dst;
    return EXECUTION_SUCCEED;
}

int writeLineToFile(const std::string &fileSourcePath, 
                     const std::string &inputString){
    std::ofstream outFile(fileSourcePath, std::ios::app);
    if(!outFile.is_open()){
        return EXECUTION_ERROR;
    }
    outFile << inputString;
    outFile.close();
    return EXECUTION_SUCCEED;
}

int readLineFromFile(const std::string &fileSourcePath,
                  std::string &outputString){
    std::ifstream inFile(fileSourcePath);
    if(!inFile.is_open()){
        return EXECUTION_ERROR;
    }
    std::getline(inFile, outputString);   
    inFile.close();
    return EXECUTION_SUCCEED;
}

int parseStringMatrix(const std::string &src, Matrix &dst){
    int currentNumber = 0;
    int decimalOrder = 10;
    std::vector<int> rowSize = {};
    int currentSize = 0;
    bool firstDetection = 1;
    bool isNegativeNumber = 0;

    for(auto &stringIterator : src){
        if(stringIterator == NEGATIVE_NUMBER){
            isNegativeNumber = 1;
            continue;
        }
        if(isdigit(stringIterator)){
            currentNumber = decimalOrder * currentNumber + int(stringIterator - '0');
            continue;
        }
        if(stringIterator == COLUMN_DELIMITER 
           || stringIterator == ROW_DELIMITER){
            if(isNegativeNumber){
                currentNumber*=-1;
            }
            dst.array.push_back(currentNumber);
            isNegativeNumber = 0;
            currentNumber = 0;
            currentSize++;
        }
        if(stringIterator == ROW_DELIMITER){
            if(firstDetection){
                dst.rowSize = currentSize;
            }
            rowSize.push_back(currentSize);
            firstDetection = 0;
            currentSize = 0;
        }
    }
    if(isNegativeNumber){
        currentNumber*=-1;
    }
    dst.array.push_back(currentNumber);
    currentSize++;

    rowSize.push_back(currentSize);
    for(auto &rowIterator : rowSize){
        if(rowIterator != dst.rowSize){
            return EXECUTION_ERROR;
        }
    }
    if(dst.array.size() < 1){
        return EXECUTION_ERROR;
    }
    return EXECUTION_SUCCEED;
}