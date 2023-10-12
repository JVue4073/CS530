#include <string>
#include <unordered_map>
#include <iostream>
#include "hexConverter.h"

//Handles functionality related to the opcode table including checking for valid opcodes, and encoding opcodes

//opcode table is our hard coded hashmap of opcodes and their corresponding integer values
std::unordered_map<std::string, std::string> opcodeTable{
    {"MUL","20"},
    {"ADD","18"},
    {"LDA","00"},
    {"LDS","6C"},
    {"ADDF", "58"},
    {"ADDR", "90"},
    {"AND", "40"},
    {"CLEAR", "B4"},
    {"COMP", "28"},
    {"COMPF", "88"},
    {"COMPR", "A0"},
    {"DIV", "24"},
    {"DIVF", "64"},
    {"DIVR", "9C"},
    {"FIX", "C4"},
    {"FLOAT", "C0"},
    {"HIO", "F4"},
    {"J", "3C"},
    {"JEQ", "30"},
    {"JGT", "34"},
    {"JLT", "38"},
    {"JSUB", "48"},
    {"LDB", "68"},
    {"LDCH", "50"},
    {"LDF", "70"},
    {"LDL", "08"},
    {"LDT", "74"},
    {"LDX", "04"},
    {"LPS", "D0"},
    {"MULF", "60"},
    {"MULR", "98"},
    {"NORM", "C8"},
    {"OR", "44"},
    {"RD", "D8"},
    {"RMO", "AC"},
    {"RSUB", "4C"},
    {"SHIFTL", "A4"},
    {"SHIFTR", "A8"},
    {"SIO", "F0"},
    {"SSK", "EC"},
    {"STA", "0C"},
    {"STB", "78"},
    {"STCH", "54"},
    {"STF", "80"},
    {"STI", "D4"},
    {"STL", "14"},
    {"STS", "7C"},
    {"STSW", "E8"},
    {"STT", "84"},
    {"STX", "10"},
    {"SUB", "1C"},
    {"SUBF", "5C"},
    {"SUBR", "94"},
    {"SVC", "B0"},
    {"TD", "E0"},
    {"TIO", "F8"},
    {"TIX", "2C"},
    {"TIXR", "B8"},
    {"WD", "DC"}
  };
  
//checks if a string is a valid opcode
bool checkOpcode(std::string opcode){
    //if opcode in opcode table return true
    auto opcodeNumber = opcodeTable.find(opcode);
    if(opcodeNumber!= opcodeTable.end()){
        return true;
    }
    //else return false    
    return false;
}

//returns the given opcode as a hex string
std::string encodeOpcode(std::string opcode, bool nflag, bool iflag){
    std::string opcodeNumber = opcodeTable[opcode];

    //add to our opcode integer here to set n and i flags
    //if n should be set we add +2
    if(nflag){
        opcodeNumber=toHex(toDec(opcodeNumber)+2,2);
    }
    //if i should be set we add +1
    if(iflag){
        opcodeNumber=toHex(toDec(opcodeNumber)+1,2);
    }

    return opcodeNumber;
}

//Expected output: 6D 03 20 0 1
int main(){
    std::cout<<encodeOpcode("LDS",false,true)<<std::endl;
    std::cout<<encodeOpcode("LDA",true,true)<<std::endl;
    std::cout<<encodeOpcode("MUL",false,false)<<std::endl;
    std::cout<<checkOpcode("ALU")<<std::endl;
    std::cout<<checkOpcode("MUL")<<std::endl;
}
