#ifndef __NOP_H__
#define __NOP_H__

#include "JiaguInterface.h"

class NopInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        m_Instru->m_machine_code = NOP << OPCODE_SHL | 0;
        return true;
    }
};
#endif // __NOP_H__