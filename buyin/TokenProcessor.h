#ifndef __TOKENPROCESSOR_H__
#define __TOKENPROCESSOR_H__

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <memory>
#include "common.h"

class TokenProcessor {
public:
    std::shared_ptr<ParseResult> proc(std::string source);

private:
    void SplitToken();
    std::string m_copy;
    std::shared_ptr<ParseResult> m_parseResult;
    int m_current_src_line{0};
};
#endif // __TOKENPROCESSOR_H__