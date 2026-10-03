#ifndef __COMMON_H__
#define __COMMON_H__
#include <string>
#include <sys/types.h>
#include <vector>
#include <iostream>
#include <cstdint>
#include <unordered_map>

const uint8_t R0 = 0;
const uint8_t R1 = 1;
const uint8_t R2 = 2;
const uint8_t R3 = 3;

const uint8_t EP = 0;
const uint8_t DP = 1;
const uint8_t SP = 2;
const uint8_t PC = 3;

const uint8_t NOP    = 0b000000;
const uint8_t HLT    = 0b000001;
const uint8_t MOV_RR = 0b000010;
const uint8_t MOV_RI = 0b000011;
const uint8_t ADD_RR = 0b000100;
const uint8_t ADD_RI = 0b000101;
const uint8_t SUB_RR = 0b000110;
const uint8_t SUB_RI = 0b000111;
const uint8_t AND_RR = 0b001000;
const uint8_t AND_RI = 0b001001;
const uint8_t OR_RR  = 0b001010;
const uint8_t OR_RI  = 0b001011;
const uint8_t XOR_RR = 0b001100;
const uint8_t XOR_RI = 0b001101;
const uint8_t CMP_RR = 0b001110;
const uint8_t CMP_RI = 0b001111;
const uint8_t NOT    = 0b010000;
const uint8_t INC    = 0b010001;
const uint8_t SHL    = 0b010010;
const uint8_t DEC    = 0b010011;
const uint8_t SHR    = 0b010100;
const uint8_t LOAD   = 0b010101;
const uint8_t STORE  = 0b010110;
const uint8_t JMP    = 0b010111;
const uint8_t JR     = 0b011000;
const uint8_t JZ     = 0b011001;
const uint8_t JNZ    = 0b011010;
const uint8_t JC     = 0b011011;
const uint8_t JNC    = 0b011100;
const uint8_t CALL   = 0b011101;
const uint8_t RET    = 0b011110;
const uint8_t PUSH   = 0b011111;
const uint8_t POP    = 0b100000;
const uint8_t MOV_PP = 0b100001;
const uint8_t INC_PP = 0b100010;
const uint8_t DEC_PP = 0b100011;
const uint8_t INC_DP = 0B100100;
const uint8_t LDEL_R = 0b101000;
const uint8_t LDEL_I = 0b101001;
const uint8_t LDEM_R = 0b101010;
const uint8_t LDEM_I = 0b101011;
const uint8_t LDEH_R = 0b101100;
const uint8_t LDEH_I = 0b101101;

const uint8_t OPCODE_SHL = 10;
const uint8_t DST_SHL   = 8;
const uint8_t SRC_SHL   = 6;

const std::unordered_map<std::string, uint8_t> Reg8bit {
    {"R0", R0},
    {"R1", R1},
    {"R2", R2},
    {"R3", R3},
};

const std::unordered_map<std::string, uint8_t> Reg24bit {
    {"EP", EP},
    {"DP", DP},
    {"SP", SP},
    {"PC", PC},
};

enum class InstrType {
    true_Instr,
    lable,
    blank,
    unknown
};


class ParseResult {
public:
    std::string m_source;
    InstrType m_type;
    std::vector<std::string> m_tokens;
    int m_lines;
    int m_addr;
    uint16_t m_machine_code;

    void Info() {
        std::cout << m_source << " ---> ";
        for(auto &e : m_tokens) {
            std::cout << e << " ";
        }
        std::cout << ", type: " << type2str() << std::endl;
    }
private:
    const std::string type2str() const {
        switch(m_type) {
            case InstrType::true_Instr : return "TRUE_INSTRU";
            case InstrType::lable : return "LABLE";
            case InstrType::blank : return "BLANK";
            case InstrType::unknown : return "UNKNOWN";
        }
    }
};

bool str2immd(std::string token, uint8_t &imm);

#endif // __COMMON_H__