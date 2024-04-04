#include <iostream>
#include <string>
#include<fstream>
struct subject
{
    std::string FIO;
    std::string form;
    int lecture;
    int semester;
    int labs;
};

void read_from_file(subject &s, std::ifstream &file);
void write_in_file(const subject &s, std::ofstream &file);