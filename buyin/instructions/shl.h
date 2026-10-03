#ifndef __SHL_H__
#define __SHL_H__

#include "JiaguInterface.h"
#include "common.h"
class ShlInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        if(m_Instru->m_tokens.size() != 2) {
            return false;
        }

        if(Reg8bit.count(m_Instru->m_tokens[1])) {
            uint8_t RDST = Reg8bit.at(m_Instru->m_tokens[1]);
            uint8_t RSRC = RDST;
            m_Instru->m_machine_code = SHL << OPCODE_SHL | RDST << DST_SHL | RSRC << SRC_SHL;
        } else {
            std::cout << "unknown dst reg" << std::endl;
            return false;
        }
        return true;
    }
};
#endif // __SHL_H__