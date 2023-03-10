#pragma once

#include<iostream>
#include<vector>
#include<fstream>
#include<string>

#define MATRIX_SIZE_INPUT_TEXT "Enter size of matrix"
#define EXECUTION_ERROR -1
#define EXECUTION_SUCCEED 0
#define COLUMN_DELIMITER ','
#define ROW_DELIMITER '_'
#define NEGATIVE_NUMBER '!'
#define MAX_MATRIX_ROWS 100
#define MAX_MATRIX_COLUMS 100
#define GET_FILE_FOR_MATRIX_TEXT "Enter file for matrix to parse> "
#define GET_FILE_FOR_OUPUT_TEXT "Enter file for ouput> "


struct Matrix{
    std::vector<int> array = {};
    int rowSize = MAX_MATRIX_ROWS; 
};

int getFileName(const char *, std::string &);

int writeLineToFile(const std::string &, const std::string &);

int readLineFromFile(const std::string &, std::string &);

int parseStringMatrix(const std::string &, Matrix &);