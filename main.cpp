#include <iostream>
//#include "data.h"
#include<fstream>
#include<string>
struct subject
{
    std::string FIO;
    std::string form;
    int lecture;
    int semester;
    int labs;
};
/**
 * @brief 
 * 
 * @param s 
 * @param file 
 */
void read_from_file(subject &s, std::ifstream &file)
{
    std::string temp;
    std::getline(file, s.FIO);
    std::getline(file, s.form);
    std::getline(file, temp);
    s.lecture = stoi(temp);
    std::getline(file, temp);
    s.semester = stoi(temp);
    std::getline(file, temp);
    s.labs = stoi(temp);

}

void write_in_file(const subject &s, std::ofstream &file)
{
    file << s.FIO << "\n";
    file << s.form << "\n";
    file << s.lecture << "\n";
    file << s.semester << "\n";
    file << s.labs;
}
int main()
{
    std::ofstream file;
    file.open("lab5.txt");
    subject one;
    one.FIO = "Aldar ";
    one.form =  "ZaOchno";
    one.lecture = 100000;
    one.semester = 80;
    one.labs = 1;
    write_in_file(one, file);
    file.close();
    std::ifstream file1;
    file1.open("info.txt");
    subject two;
    read_from_file(two, file1);
    std::cout << two.FIO << " " << two.form  << "  " << two.lecture  << " " << two.semester << " " << two.labs;

}