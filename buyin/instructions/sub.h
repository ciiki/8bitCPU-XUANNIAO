#ifndef __SUB_H__
#define __SUB_H__

#include "JiaguInterface.h"
#include "common.h"

class SubInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        if(m_Instru->m_tokens.size() != 3) {
            return false;
        }

        if(Reg8bit.count(m_Instru->m_tokens[1])) {
            uint8_t RDST = Reg8bit.at(m_Instru->m_tokens[1]);
            if (Reg8bit.count(m_Instru->m_tokens[2])) {
                uint8_t RSRC = Reg8bit.at(m_Instru->m_tokens[2]);
                m_Instru->m_machine_code = SUB_RR << OPCODE_SHL | RDST << DST_SHL | RSRC << SRC_SHL;
            } else {
                uint8_t imm;
                if(str2immd(m_Instru->m_tokens[2], imm)) {
                    m_Instru->m_machine_code = SUB_RI << OPCODE_SHL | RDST << DST_SHL | imm;
                } else {
                    return false;
                }
            }

        } else {
            std::cout << "unknown dst reg" << std::endl;
            return false;
        }
        return true;
    }
};
#endif // __SUB_H__