#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

/**
 * @brief 
 * 
 */
 struct subject
{
    std::string FIO; ///< ФИО
    std::string form;
    int lecture;
    int semester;
    int labs;
};
int read_from_file(subject *&s, std::ifstream &file)
{
    int size = (std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n')+1) / 5;
    file.seekg(0);
    s = new subject[size];
    for(int i =0; i < size;++i)
    {
    std::string temp;
    std::getline(file, s[i].FIO);
    std::getline(file, s[i].form);
    std::getline(file, temp);
    s[i].lecture = stoi(temp);
    std::getline(file, temp);
    s[i].semester = stoi(temp);
    std::getline(file, temp);
    s[i].labs = stoi(temp);
    }
    return size;
}


void delete_struct(subject *&s, int elem, int& size)
{
    if(size == 0) return;
    if(size == 1){
        delete[] s;
        s = new subject[0];
        size = 0;
        return;
    }
    subject *temp = new subject[size-1];
    for(int i = 0 ; i < elem; ++i)
    {
        temp[i] = s[i];
    }
    for(int i = elem+1; i < size; ++i)
    {
        temp[i-1] = s[i];
    }
    delete[] s;
    s = temp;
    size--;

}

void write_in_file(const subject &s, std::fstream &file)
{
    file << s.FIO << "\n";
    file << s.form << "\n";
    file << s.lecture << "\n";
    file << s.semester << "\n";
    file << s.labs << "\n";
}
void search_by_name(subject * arr, std::string FIO, int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i].FIO == FIO)
         {
            std::cout << arr[i].FIO << "\n";
            std::cout << arr[i].form << "\n";
            std::cout << arr[i].lecture << "\n";
            std::cout << arr[i].semester << "\n";
            std::cout << arr[i].labs << "\n";
           }
      }
}
int main()
{   
    std::fstream file;
    file.open("C:\\Labs\\lab5\\lab5.txt", std::ios_base::app | std::ios_base:: in);
    subject one;
    one.FIO = "Aldar";
    one.form =  "ZaOchno";
    one.lecture = 100000;
    one.semester = 80;
    one.labs = 1;
    write_in_file(one, file);
    file.close();
    std::ifstream file1;
    std::fstream output;
 
    file1.open("C:\\Labs\\lab5\\info.txt");
    subject* subs;
    int size = read_from_file(subs, file1);
    file1.close();
    output.open("C:\\Labs\\lab5\\info.txt",  std::ios::out | std::ios::in);
    std::cout << "Исходный файл" << "\n";
    for(int i =0; i < size; ++i){std::cout << subs[i].FIO << " " << subs[i].form  << "  " << subs[i].lecture  << " " << subs[i].semester << " " << subs[i].labs << "\n"; write_in_file(subs[i], output);}
    output.close();
    delete_struct(subs, 1, size);
    output.open("C:\\Labs\\lab5\\info.txt",  std::ios::out | std::ios::trunc); 
    std::cout << "Файл после удаления" << "\n";
    for(int i =0; i < size; ++i)
    {
        std::cout << subs[i].FIO << " " << subs[i].form  << "  " << subs[i].lecture  << " " << subs[i].semester << " " << subs[i].labs << "\n"; 
        write_in_file(subs[i], output);
    }
    std::cout << "Поиск по имени\n";
    search_by_name(subs,"Dima",size);
}