#ifndef __PUSH_H__
#define __PUSH_H__

#include "JiaguInterface.h"
#include "common.h"
class PushInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        if(m_Instru->m_tokens.size() != 2) {
            return false;
        }

        if(Reg8bit.count(m_Instru->m_tokens[1])) {
            uint8_t RSRC = Reg8bit.at(m_Instru->m_tokens[1]);
            uint8_t PDST = SP;
            m_Instru->m_machine_code = PUSH << OPCODE_SHL | PDST << DST_SHL | RSRC << SRC_SHL;
        } else {
            std::cout << "unknown dst reg" << std::endl;
            return false;
        }
        return true;
    }
};
#endif // __PUSH_H__