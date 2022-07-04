//
//  homeproject.cpp
//  homeproject2
//
//  Created by Stanley Fung on 3/14/22.
//

#include "homeproject.h"

bool MyManager::ADD(std::vector<std::string> info)
{
    if(info.size() < 3){
        return false;
    }
    else{
        studentRecords.push_back(info);
    }
    return true;
}
std::vector<std::vector<std::string>> MyManager::FIND(std::vector<std::string> condition)
{
    std::vector<std::vector<std::string>> out;
    if(condition[0] == "id"){
        long int x = stoi(condition[0]);
        if(condition[1] == "<"){
            for(int i = 0; i < studentRecords.size(); i++){
                long int temp = stoi(studentRecords[i][0]);
                if(temp < x){
                    out.push_back(studentRecords[i]);
                }
            }
            return out;
        }
        if(condition[1] == ">"){
            for(int i = 0; i < studentRecords.size(); i++){
                    long int temp = stoi(studentRecords[i][0]);
                    if(temp > x){
                        out.push_back(studentRecords[i]);
                    }
                }
                return out;
        }
        if(condition[1] == "="){
                for(int i = 0; i < studentRecords.size(); i++){
                    long int temp = stoi(studentRecords[i][0]);
                    if(temp == x){
                        out.push_back(studentRecords[i]);
                    }
                }
                return out;
        }
    }
    if(condition[0] == "age"){
        short int x = stoi(condition[2]);
        if(condition[1] == "<"){
            for(int i = 0; i < studentRecords.size(); i++){
                short int temp = stoi(studentRecords[i][2]);
                if(temp < x){
                    out.push_back(studentRecords[i]);
                }
                }
            return out;
            }

        if(condition[1] == ">"){
            for(int i = 0; i < studentRecords.size(); i++){
                short int temp = stoi(studentRecords[i][2]);
                if(temp > x){
                    out.push_back(studentRecords[i]);
                }
                }
            return out;
        }
        if(condition[1] == "=")
        {
            for(int i = 0; i < studentRecords.size(); i++){
                short int temp = stoi(studentRecords[i][2]);
                if(temp == x){
                    out.push_back(studentRecords[i]);
                }
                }
            return out;
        }
    }
    
    if(condition[0] == "name"){
        for(int i = 0; i < studentRecords.size(); i++){
            if(condition[2] == studentRecords[i][1]){
                out.push_back(studentRecords[i]);
            }
        }
        return out;
    }
    return out;
}
void MyManager::REMOVE(std::vector<std::string> condition)
{
    
    if(condition[0] == "id"){
        long int x = stoi(condition[0]);
        std::vector<std::vector<std::string>>::iterator start = studentRecords.begin();
        if(condition[1] == "<"){
            for(int i = 0; i < studentRecords.size(); i++){
                long int temp = stoi(studentRecords[i][0]);
                if(temp < x){
                    studentRecords.erase(start+i);
                }
            }
        }
        if(condition[1] == ">"){
            for(int i = 0; i < studentRecords.size(); i++){
                long int temp = stoi(studentRecords[i][0]);
                if(temp > x){
                    studentRecords.erase(start+i);
                }
            }
        }
        if(condition[1] == "=")
        {
            for(int i = 0; i < studentRecords.size(); i++){
                long int temp = stoi(studentRecords[i][0]);
                if(temp == x){
                    studentRecords.erase(start+i);
                }
            }
        }
    }
    if(condition[0] == "age"){
        short int x = stoi(condition[2]);
        std::vector<std::vector<std::string>>::iterator start = studentRecords.begin();
        if(condition[1] == "<"){
            for(int i = 0; i < studentRecords.size(); i++){
                short int temp = stoi(studentRecords[i][2]);
                if(temp < x){
                    studentRecords.erase(start+i);
                }
            }
        }
        if(condition[1] == ">"){
            for(int i = 0; i < studentRecords.size(); i++){
                short int temp = stoi(studentRecords[i][2]);
                if(temp > x){
                    studentRecords.erase(start+i);
                }
            }

        }
        if(condition[1] == "=")
        {
            for(int i = 0; i < studentRecords.size(); i++){
                short int temp = stoi(studentRecords[i][2]);
                if(temp == x){
                    studentRecords.erase(start+i);
                }
            }
        }
    }
    if(condition[0] == "name"){
        std::vector<std::vector<std::string>>::iterator start = studentRecords.begin();
        for(int i = 0; i < studentRecords.size(); i++){
            if(condition[2] == studentRecords[i][1]){
                studentRecords.erase(start+i);
            }
        }
    }
}
void MyManager::STOP()
{
    writeRecords(studentRecords);
}
void MyManager::process(std::vector<std::string> parsed_command){
    if(parsed_command[0] == "ADD"){
        parsed_command.erase(parsed_command.begin());
        ADD(parsed_command);
    }
    if(parsed_command[0] == "FIND"){
        parsed_command.erase(parsed_command.begin());
        FIND(parsed_command);
    }
    if(parsed_command[0] == "REMOVE"){
        parsed_command.erase(parsed_command.begin());
        REMOVE(parsed_command);
    }
    if(parsed_command[0] == "STOP"){
        STOP();
    }
}

Student::Student(unsigned int ID, std::string name, unsigned short age)
{
    student_ID = ID;
    student_name = name;
    student_age = age;
}
//ready to test, might need to fix
std::vector<std::string> MyParser::Parser(std::string user_command)
{
    std::stringstream user(user_command);
    std::vector<std::string> parsed_command;
    std::string middle;
    while(getline(user, middle, space)){
        parsed_command.push_back(middle);
        if(middle == ""){
            parsed_command.pop_back();
        }
        if(parsed_command[0] != "STOP"){
            if(parsed_command.size() > 4 && parsed_command[0] == "ADD"){
            parsed_command[2] = parsed_command[2] + " " + parsed_command[3];
        }
        if(parsed_command.size() < 4 && parsed_command[0] != "ADD"){
            for(int i = 0; i < parsed_command.size(); i++){
                if(parsed_command[i].find("age") != std::string::npos){
                    parsed_command[1] = "age";
                }
                if(parsed_command[i].find("name") != std::string::npos){
                    parsed_command[1] = "age";
                }
                if(parsed_command[i].find("id") != std::string::npos){
                    parsed_command[1] = "id";
                }
                if(parsed_command[i].find("<") != std::string::npos){
                    parsed_command[2] = "<";
                }
                if(parsed_command[i].find(">") != std::string::npos){
                    parsed_command[2] = ">";
                }
                if(parsed_command[i].find("=") != std::string::npos){
                    parsed_command[2] = "=";
                }
                if(parsed_command[2].find("=") != std::string::npos){
                    parsed_command[3] = user_command.substr(user_command.find('=')+1);
                }
                if(parsed_command[2].find("<") != std::string::npos){
                    parsed_command[3] = user_command.substr(user_command.find('<')+1);
                }
                if(parsed_command[2].find(">") != std::string::npos){
                    parsed_command[3] = user_command.substr(user_command.find('>')+1);
                }
            }
        }
    }
        
}
    return parsed_command;
}

std::vector<std::string> DiskManagement::readRecords(std::ifstream& myfile)
{
    std::vector<std::string> records;
    myfile.open("myfile.txt");
    std::string line;
    while(getline(myfile, line)){
        records.push_back(line);
    }
    myfile.close();
    return records;
}
//ready to test
void DiskManagement::writeRecords(std::vector<std::vector<std::string>> student_records){
    std::ofstream myfile;
    myfile.open("myfile.txt");
    for(int i = 0; i < student_records.size(); i++){
        for(int j = 0; j < student_records.size(); j++){
        myfile << student_records[i][j] << std::endl;
    }
    }
    myfile.close();
}

int main(){
    std::cout << "hello";
}
