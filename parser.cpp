#include "parser.h"

void reader(std::string fileName)
{
    std::ifstream file(fileName);
    std::vector<std::string> header;
    std::vector<std::map<std::string, std::string>> map;

    header = getHeader(fileName);
}

void output()
{

}

std::vector<std::string> getHeader(std::string fileName)
{

    std::ifstream file(fileName);

    int pos = 0;
    std::string line = "";
    std::vector<std::string> header;

    getline(file, line);

    pos = line.find(',');
    line = line.erase(0, 1);

    pos = line.find(',');
    while(pos != -1)
    {
        int tmp = line.find(',');
        std::string tmp_str = line.substr(0, tmp);
        header.push_back(tmp_str);
        line = line.erase(0, tmp + 1);
        pos = tmp;
    }

    file.close();
    return (header);
}