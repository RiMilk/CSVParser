#include "main.h"
#include "parser.h"

int main(int count, char *params[])
{
    if (count == 2)
    {
        if (isOpen(params[1]))
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
        return (false);
    
    return (true);
}