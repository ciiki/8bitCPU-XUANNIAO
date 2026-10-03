#include <memory>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include "TokenProcessor.h"
// #include "logger.h"

std::unordered_set<std::string> support_instr {
    "NOP",
    "HLT",
    "MOV",
    "ADD",
    "SUB",
    "AND",
    "OR",
    "XOR",
    "CMP",
    "NOT",
    "INC",
    "SHL",
    "DEC",
    "SHR",
    "LOAD",
    "STORE",
    "JMP",
    // "JR",
    "JZ",
    "JNZ",
    "JC",
    "JNC",
    // "CALL",
    // "RET",
    "PUSH",
    "POP",
    "LDEL",
    "LDEM",
    "LDEH",
};

std::shared_ptr<ParseResult> TokenProcessor::proc(std::string source)
{
    m_copy = source;
    m_parseResult = std::make_shared<ParseResult>();
    m_parseResult->m_source = std::string(source);
    m_parseResult->m_lines = m_current_src_line++;
    SplitToken();
    return m_parseResult;
}

void TokenProcessor::SplitToken()
{
    for(auto i = m_copy.begin(); i != m_copy.end(); ++i) {
        if(*i == ',') {
            *i = ' ';
        } 
        else if(*i == ';') {
            *i = ' ';
            m_copy.insert(i+1, ';');
            break;
        }
    }

    for(int i = 0; i < m_copy.size(); i++) {
        if(m_copy[i] == ',') {
            m_copy[i] = ' ';
        }else if(m_copy[i] == ';') {
            m_copy.insert(m_copy.begin() + i, ' ');
            break;
        }
    }

    std::stringstream ss(m_copy);
    std::string token;

    bool firstToken = true;
    while (ss >> token) {
        // std::cout << token << std::endl;
        if(token[0] == ';' ) {
            break;
        }

        if(token.back() == ':') {
            token.pop_back();
            m_parseResult->m_type = InstrType::lable;
            m_parseResult->m_tokens.push_back(token);
            break;
        }

        if(firstToken) {
            for(char &c : token) {
                if('a' <= c && c <= 'z') {
                    c &= 0b11011111; // 小写转大写
                }
            }
            if(support_instr.count(token)) {
                m_parseResult->m_type = InstrType::true_Instr;
            } else {
                m_parseResult->m_type = InstrType::unknown;
            }
            firstToken = false;
        }
        m_parseResult->m_tokens.push_back(token);
        // std::cout << token << " ";
    }
    if(m_parseResult->m_tokens.empty()) {
        m_parseResult->m_type = InstrType::blank;
    }
}