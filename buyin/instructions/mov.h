#ifndef __MOV_H__
#define __MOV_H__

#include "JiaguInterface.h"
#include "common.h"
#include <cstdint>
class MovInstru : public JiaguInterface {
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
                m_Instru->m_machine_code = MOV_RR << OPCODE_SHL | RDST << DST_SHL | RSRC << SRC_SHL;
            } else {
                uint8_t imm;
                if(str2immd(m_Instru->m_tokens[2], imm)) {
                    m_Instru->m_machine_code = MOV_RI << OPCODE_SHL | RDST << DST_SHL | imm;
                } else {
                    return false;
                }
            }

        } else if (Reg24bit.count(m_Instru->m_tokens[1])) {
            uint8_t PDST = Reg24bit.at(m_Instru->m_tokens[1]);
            if (Reg24bit.count(m_Instru->m_tokens[2])) {
                uint8_t PSRC = Reg24bit.at(m_Instru->m_tokens[2]);
                m_Instru->m_machine_code = MOV_PP << OPCODE_SHL | PDST << DST_SHL | PSRC << SRC_SHL;
            // } else if(m_Instru->m_tokens[1] == "EP") {

            } else {
                std::cout << "unsupport src reg" << std::endl;
                return false;
            }

        } else {
            std::cout << "unknown dst reg" << std::endl;
            return false;
        }
        return true;
    }
};
#endif // __MOV_H__