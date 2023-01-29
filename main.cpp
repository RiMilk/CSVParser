#include "main.h"

int main(int count, char *params[])
{
    CSVData data;
    
    data.reader(params[1]);
    data.output();
}
