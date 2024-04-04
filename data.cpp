#include "data.h"

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