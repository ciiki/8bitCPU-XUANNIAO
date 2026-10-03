#ifndef __INSFILTER_H__
#define __INSFILTER_H__
#include <string>
#include <vector>
#include "TokenProcessor.h"
#include "instruFactory.h"

class InsFilter {
public:
    static InsFilter* GetInstanc() {
        static InsFilter singleton;
        return &singleton;
    }

    bool Proc(std::string line);
private:
    void JiaguBuilder(std::shared_ptr<ParseResult> Instru);
    InsFilter() {}
    TokenProcessor m_processer;
    JiaguFactory factory;
};
#endif // __INSFILTER_H__