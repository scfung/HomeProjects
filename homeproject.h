//
//  homeproject.h
//  homeproject2
//
//  Created by Stanley Fung on 3/14/22.
//

#ifndef homeproject_h
#define homeproject_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>

class Student{
    public:
    Student(unsigned int ID, std::string name, unsigned short age);
    Student();
    ~Student();
    protected:
    unsigned int student_ID;
    std::string student_name;
    unsigned short student_age;
    
};

class DiskManagement:public Student{
    public:
    std::vector<std::string> readRecords(std::ifstream& myfile);
    void writeRecords(std::vector<std::vector<std::string>> student_records);
    DiskManagement();
    ~DiskManagement();
    private:
    std::vector<std::string> stored_records;
};
    
class MyManager:public DiskManagement{
    public:
    MyManager();
    ~MyManager();
    bool ADD(std::vector<std::string> info);
    std::vector<std::vector<std::string>> FIND(std::vector<std::string> condition);
    void REMOVE(std::vector<std::string> condition);
    void STOP();
    void process(std::vector<std::string> parsed_command);
    protected:
    std::vector<std::vector<std::string>> studentRecords;
};


class MyParser:public MyManager{
    public:
    MyParser();
    ~MyParser();
    std::vector<std::string> Parser(std::string user_command);
    private:
    char space = ' ';
    
};


#endif /* homeproject_h */
