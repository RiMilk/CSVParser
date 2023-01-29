#ifndef PARSER_H
# define PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

std::vector<std::string> getHeader(std::string fileName);

void reader(std::string fileName);
void output();

#endif //PARSER_H