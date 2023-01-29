#ifndef PARSER_H
# define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

class CSVData{
public:

    CSVData();
    ~CSVData();
    CSVData(std::string fileName);

    std::string fileName;

    void reader(std::string file);
    void output();

    std::vector<std::string> getHeader();
    std::vector<std::string> getColumns();

private:

    std::vector<std::string> header;
    std::vector<std::string> columns;
    std::map<std::string, std::string> map;

    bool isOpen(std::string fileName);
    bool isValidData(std::string fileName);
    std::string getArithmeticOperations(std::string line, int pos, char oper);
    std::map<std::string, std::string> getData(std::vector<std::string> header);
    std::map<std::string, std::string> getCalc(std::map<std::string, std::string> map);
};

#endif //PARSER_H