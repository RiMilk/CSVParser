#ifndef PARSER_H
# define PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

std::vector<std::string> getHeader(std::string fileName);
std::vector<std::string> getColumns(std::string fileName);
std::map<std::string, std::string> getData(std::string fileName, std::vector<std::string> header);
std::map<std::string, std::string> getCalc(std::map<std::string, std::string> map);

void reader(std::string fileName);
void output(std::map<std::string, std::string> map, std::vector<std::string> header, std::vector<std::string> columns);

#endif //PARSER_H