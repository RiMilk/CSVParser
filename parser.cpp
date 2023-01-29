#include "parser.h"

void reader(std::string fileName)
{
    std::ifstream file(fileName);
    std::vector<std::string> header;
    std::vector<std::string> columns;
    std::map<std::string, std::string> map;

    header = getHeader(fileName);
    columns = getColumns(fileName);
    map = getData(fileName, header);
    map = getCalc(map);
    
    output(map, header, columns);
}

void output(std::map<std::string, std::string> map, std::vector<std::string> header, std::vector<std::string> columns)
{
    int iter = 0;
    size_t count = 1;

    for(std::string item : header)
        std::cout << "," << item;

    std::cout << std::endl;

    for(std::pair<std::string, std::string> item : map)
    {
        if (count == 1)
        {
            std::cout << columns[iter];
            iter++;
        }

        std::cout << " " << item.second;

        if (count == header.size())
        {
            std::cout << std::endl;
            count = 1;
        }
        else
            count++;
    }
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

std::vector<std::string> getColumns(std::string fileName)
{

    int pos = 0;
    std::string line = "";
    std::ifstream file(fileName);
    std::vector<std::string> columns;

    getline(file, line); //
    while (!file.eof())
    {
        std::map<std::string, std::string> tmp_map;

        getline(file, line);
        
        pos = line.find(',');
        std::string tmp_str = line.substr(0, pos);
        columns.push_back(tmp_str);
    }

    file.close();
    return (columns);
}

std::map<std::string, std::string> getData(std::string fileName, std::vector<std::string> header)
{

    int pos = 0;
    std::string line = "";
    std::ifstream file(fileName);
    std::map<std::string, std::string> map;

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

            map.insert(std::pair<std::string, std::string>(header[count]+tmp_str, data));
            
            line = line.erase(0, tmp + 1);
            pos = tmp;
            count++;
        }
        
    }

    file.close();
    return (map);
}


std::map<std::string, std::string> getCalc(std::map<std::string, std::string> map)
{
    for(std::pair<std::string, std::string> item : map)
    {
        if (item.second[0] == '=')
        {
            std::string tmp = item.second;

            int posSum = tmp.find('+');
            int posDiff = tmp.find('-');
            int posMult = tmp.find('*');
            int posDiv = tmp.find('/');

            if (posSum != -1)
            {
                std::string left = tmp.substr(1, posSum - 1);
                std::string right = tmp.substr(posSum + 1, tmp.length() - 1 - posSum);

                auto ileft = map.find(left);
                auto iright = map.find(right);

                map[item.first] = std::to_string(std::atoi(ileft->second.c_str()) + std::atoi(iright->second.c_str()));
            }

            if (posDiff != -1)
            {
                std::string left = tmp.substr(1, posSum - 1);
                std::string right = tmp.substr(posSum + 1, tmp.length() - 1 - posSum);

                auto ileft = map.find(left);
                auto iright = map.find(right);

                map[item.first] = std::to_string(std::atoi(ileft->second.c_str()) - std::atoi(iright->second.c_str()));
            }

            if (posMult != -1)
            {
                std::string left = tmp.substr(1, posSum - 1);
                std::string right = tmp.substr(posSum + 1, tmp.length() - 1 - posSum);

                auto ileft = map.find(left);
                auto iright = map.find(right);

                map[item.first] = std::to_string(std::atoi(ileft->second.c_str()) * std::atoi(iright->second.c_str()));
            }

            if (posDiv != -1)
            {
                std::string left = tmp.substr(1, posSum - 1);
                std::string right = tmp.substr(posSum + 1, tmp.length() - 1 - posSum);

                auto ileft = map.find(left);
                auto iright = map.find(right);

                map[item.first] = std::to_string(std::atoi(ileft->second.c_str()) / std::atoi(iright->second.c_str()));
            }
            
        }
    }

    return (map);
}