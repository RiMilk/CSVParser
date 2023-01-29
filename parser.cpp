#include "parser.h"

CSVData::CSVData(std::string file)
{
    if (isOpen(file) && isValidData(file))
        fileName = file;
}

CSVData::CSVData()
{

}

CSVData::~CSVData()
{
}

void CSVData::reader(std::string file)
{
    if (isOpen(file) && isValidData(file))
        fileName = file;

    std::ifstream fileOpen(fileName);

    header = getHeader();
    columns = getColumns();
    map = getData(header);
    map = getCalc(map);

    fileOpen.close();
}

void CSVData::output()
{
    int iter = 0;
    size_t count = 1;

    for(std::string item : header)
        std::cout << "," << item;

    std::cout << std::endl;

    for(std::string column : columns)
    {
        std::cout << column;
        for(std::string head : header)
        {
            std::cout << "," << map[head+column];
        }
        std::cout<<std::endl;
    }
}

std::vector<std::string> CSVData::getHeader()
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

std::vector<std::string> CSVData::getColumns()
{

    int pos = 0;
    std::string line = "";
    std::ifstream file(fileName);
    std::vector<std::string> columns;

    getline(file, line); //Skip the first line with the header
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

std::map<std::string, std::string> CSVData::getData(std::vector<std::string> header)
{

    int pos = 0;
    std::string line = "";
    std::ifstream file(fileName);
    std::map<std::string, std::string> map;

    getline(file, line); //Skip the first line with the header
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


std::map<std::string, std::string> CSVData::getCalc(std::map<std::string, std::string> map)
{
    for(std::pair<std::string, std::string> item : map)
        if (item.second[0] == '=')
        {
            std::string tmp = item.second;

            int posSum = tmp.find('+');
            int posDiff = tmp.find('-');
            int posMult = tmp.find('*');
            int posDiv = tmp.find('/');

            if (posSum != -1)
                map[item.first] = getArithmeticOperations(tmp, posSum, '+');
            if (posDiff != -1)
                map[item.first] = getArithmeticOperations(tmp, posDiff, '-');
            if (posMult != -1)
                map[item.first] = getArithmeticOperations(tmp, posMult, '*');
            if (posDiv != -1)
                map[item.first] = getArithmeticOperations(tmp, posDiv, '/');
        }

    return (map);
}

std::string CSVData::getArithmeticOperations(std::string line, int pos, char oper)
{
    std::string left = line.substr(1, pos - 1);
    std::string right = line.substr(pos + 1, line.length() - 1 - pos);

    auto ileft = map.find(left);
    auto iright = map.find(right);

    if (oper == '+')
        return(std::to_string(std::atoi(ileft->second.c_str()) + std::atoi(iright->second.c_str())));
    if (oper == '-')
        return(std::to_string(std::atoi(ileft->second.c_str()) - std::atoi(iright->second.c_str())));
    if (oper == '*')
        return(std::to_string(std::atoi(ileft->second.c_str()) * std::atoi(iright->second.c_str())));
    if (oper == '/')
        return(std::to_string(std::atoi(ileft->second.c_str()) / std::atoi(iright->second.c_str()))); 
    
    return ("ERROR");
}

bool CSVData::isOpen(std::string fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "ERROR: File can not open!" << std::endl;
        return (false);
    }
    
    file.close();
    return (true);
}

bool CSVData::isValidData(std::string fileName)
{
    int count = 0;

    count = fileName.length();
    if (count > 3 && fileName[count - 1] == 'v' && fileName[count - 2] == 's' && fileName[count - 3] == 'c' && fileName[count - 4] == '.')
        return (true);
    
    std::cout << "ERROR: Incorrect input data format" << std::endl;
    return (false);
}