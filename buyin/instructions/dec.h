#ifndef __DEC_H__
#define __DEC_H__

#include "JiaguInterface.h"
class DecInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        if(m_Instru->m_tokens.size() != 2) {
            return false;
        }

        if(Reg8bit.count(m_Instru->m_tokens[1])) {
            uint8_t RDST = Reg8bit.at(m_Instru->m_tokens[1]);
            uint8_t imm = 1;
            m_Instru->m_machine_code = DEC << OPCODE_SHL | RDST << DST_SHL | imm;
        } else if(m_Instru->m_tokens[1] == "EP") {
            uint8_t RDST = Reg24bit.at(m_Instru->m_tokens[1]);
            uint8_t imm = 1;
            m_Instru->m_machine_code = DEC_PP << OPCODE_SHL | RDST << DST_SHL | imm;
        } else {
            std::cout << "unknown dst reg" << std::endl;
            return false;
        }
        return true;
    }
};
#endif // __DEC_H__