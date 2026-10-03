#ifndef __HLT_H__
#define __HLT_H__

#include "JiaguInterface.h"
#include "common.h"
class HltInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        m_Instru->m_machine_code = HLT << OPCODE_SHL | 0;
        return true;
    }
};
#endif // __HLT_H__