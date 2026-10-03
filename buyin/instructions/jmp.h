#ifndef __JMP_H__
#define __JMP_H__

#include "JiaguInterface.h"
#include "common.h"
#include <cstdint>
class JmpInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        if(m_Instru->m_tokens.size() != 2) {
            return false;
        }

        uint8_t OPCODE;
        if(m_Instru->m_tokens[0] == "JMP") {
            OPCODE = JMP;
        } else if(m_Instru->m_tokens[0] == "JR") {
            OPCODE = JR;
        } else if(m_Instru->m_tokens[0] == "JZ") {
            OPCODE = JZ;
        } else if(m_Instru->m_tokens[0] == "JNZ") {
            OPCODE = JNZ;
        } else if(m_Instru->m_tokens[0] == "JC") {
            OPCODE = JC;
        } else if(m_Instru->m_tokens[0] == "JNC") {
            OPCODE = JNC;
        }

        uint8_t PDST = PC;
        uint8_t PSRC = EP;
        m_Instru->m_machine_code = OPCODE << OPCODE_SHL | PDST << DST_SHL | PSRC << SRC_SHL;

        return true;
    }
};
#endif // __JMP_H__