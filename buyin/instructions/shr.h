#ifndef __SHR_H__
#define __SHR_H__

#include "JiaguInterface.h"
#include "common.h"
class ShrInstru : public JiaguInterface {
public:
    using JiaguInterface::JiaguInterface;
    bool compile() override {
        //TODO
        return true;
    }
};
#endif // __SHR_H__