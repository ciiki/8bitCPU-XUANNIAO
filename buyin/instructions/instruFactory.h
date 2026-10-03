#ifndef __INSTRUFACTORY_H__
#define __INSTRUFACTORY_H__
#include "JiaguInterface.h"

class JiaguFactory {
public:
    std::vector<std::shared_ptr<JiaguInterface>> GetJiaGu(std::shared_ptr<ParseResult> Instru);
private:
    void insertWaitLable(std::vector<std::shared_ptr<JiaguInterface>> &instrus, std::string lable);
};
#endif // __INSTRUFACTORY_H__