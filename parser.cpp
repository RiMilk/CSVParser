#include "parser.h"

void reader(std::string fileName)
{
    std::ifstream file(fileName);
    std::vector<std::string> header;
    std::map<std::string, std::map<std::string, std::string>> map;

    header = getHeader(fileName);
    map = getData(fileName, header);
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

    getline(file, line); //

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

std::map<std::string, std::map<std::string, std::string>> getData(std::string fileName, std::vector<std::string> header)
{

    int pos = 0;
    std::string line = "";
    std::ifstream file(fileName);
    std::map<std::string, std::map<std::string, std::string>> map;

    getline(file, line); //
    while (!file.eof())
    {
        std::map<std::string, std::string> tmp_map;

        getline(file, line);
        
        pos = line.find(',');
        std::string tmp_str = line.substr(0, pos);     
        line = line.erase(0, pos + 1);

        pos = line.find(',');
        int count = 0;
        while(pos != -1)
        {
            int tmp = line.find(',');
            std::string data = line.substr(0, tmp);

            tmp_map.insert(std::pair<std::string, std::string>(header[count], data));
            
            line = line.erase(0, tmp + 1);
            pos = tmp;
            count++;
        }
        
        map.insert(std::pair<std::string, std::map<std::string, std::string>>(tmp_str, tmp_map));
    }

/*
    for(std::pair<std::string, std::map<std::string, std::string>> item : map)
    {
        std::cout << item.first << " ";
        for (std::pair<std::string, std::string> items :  item.second)
        {
            std::cout << items.second << " ";
        }
        std::cout << std::endl;
    }
*/
    file.close();
    return (map);
}