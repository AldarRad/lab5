#include <iostream>
#include "data.h"
#include<fstream>
#include<string>


int main()
{
    std::ofstream file;
    file.open("lab5.txt");
    subject one;
    one.FIO = "Aldar Radnaev";
    one.form =  "Ochno";
    one.lecture = 1000;
    one.semester = 8;
    one.labs = 10;
    write_in_file(one, file);
    file.close();
    std::ifstream file1;
    file1.open("info.txt");
    subject two;
    read_from_file(two, file1);
    std::cout << two.FIO << " " << two.form  << "  " << two.lecture  << " " << two.semester << " " << two.labs;

}