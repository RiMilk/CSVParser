#include "main.h"
#include "parser.h"

int main(int count, char *params[])
{
    if (count == 2)
    {
        if (isOpen(params[1]) && isValidData(params[1]))
        {
            std::cout << "compl" << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: Incorrect input data format" << std::endl;
    }
}

bool isOpen(std::string fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "ERROR: File can not open!" << std::endl;
        return (false);
    }
    
    return (true);
}

bool isValidData(std::string fileName)
{
    int count = 0;

    count = fileName.length();
    if (count > 3 && fileName[count - 1] == 'v' && fileName[count - 2] == 's' && fileName[count - 3] == 'c' && fileName[count - 4] == '.')
        return (true);
    
    std::cout << "ERROR: Incorrect input data format" << std::endl;
    return (false);
}