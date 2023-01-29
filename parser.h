#ifndef PARSER_H
# define PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

std::vector<std::string> getHeader(std::string fileName);
std::map<std::string, std::map<std::string, std::string>> getData(std::string fileName, std::vector<std::string> header);

void reader(std::string fileName);
void output();

#endif //PARSER_H