#ifndef __LOAD_H__
#define __LOAD_H__

#include "JiaguInterface.h"
#include "common.h"
class LoadInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        if(m_Instru->m_tokens.size() != 2) {
            return false;
        }

        if(Reg8bit.count(m_Instru->m_tokens[1])) {
            uint8_t RDST = Reg8bit.at(m_Instru->m_tokens[1]);
            uint8_t PSRC = DP;
            m_Instru->m_machine_code = LOAD << OPCODE_SHL | RDST << DST_SHL | PSRC << SRC_SHL;
        } else {
            std::cout << "unknown dst reg" << std::endl;
            return false;
        }
        return true;
    }
};
#endif // __LOAD_H__