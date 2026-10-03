#ifndef __LDEX_H__
#define __LDEX_H__

#include "JiaguInterface.h"
#include "common.h"
#include <cstdint>
class LdexInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        if(m_Instru->m_tokens.size() != 2) {
            return false;
        }

        uint8_t imm;
        uint8_t OPCODE;
        if(m_Instru->m_tokens[0].back() == 'L') {
            OPCODE = LDEL_R;
        } else if(m_Instru->m_tokens[0].back() == 'M') {
            OPCODE = LDEM_R;
        } else if (m_Instru->m_tokens[0].back() == 'H') {
            OPCODE = LDEH_R;
        }
        uint8_t PDST = EP;

        if(Reg8bit.count(m_Instru->m_tokens[1])) {
            uint8_t RSRC = Reg8bit.at(m_Instru->m_tokens[1]);
            m_Instru->m_machine_code = OPCODE << OPCODE_SHL | PDST << DST_SHL | RSRC << SRC_SHL;
        }else if(str2immd(m_Instru->m_tokens[1], imm)) {
            OPCODE |= 0b000001;
            m_Instru->m_machine_code = OPCODE << OPCODE_SHL | PDST << DST_SHL | imm;
        } else {
            std::cout << "unknown dst reg" << std::endl;
            return false;
        }
        return true;
    }
};
#endif // __LDEX_H__