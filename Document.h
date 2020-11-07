#pragma once
#include <string>
#include <iostream>
#include <vector>

class Document {
    
public:
    std::vector<std::string> editSong;
    int currLine;
    
public:
//CONSTRUCTOR
Document(std::vector<std::string> v, std::vector<std::string> cmds,int line): editSong(v),currLine(0){}
Document()=default;
    
// FUNCTIONS
void lineOne();
void plus(int num);
void minus(int num);
void moveLstLine();
void addLine_before();
void addLine_after();
void delete_line();
void write_toFile(std::string fileName);
void merge2Lines();
void exit_();
void text_(std::string text);
void old_new(std::string _old, std::string _new);
    
}; //end class Document


