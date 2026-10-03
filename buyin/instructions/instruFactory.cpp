#include "instruFactory.h"
#include "add.h"
#include "and.h"
#include "cmp.h"
#include "common.h"
#include "dec.h"
#include "hlt.h"
#include "inc.h"
#include "jmp.h"
#include "ldex.h"
#include "load.h"
#include "mov.h"
#include "nop.h"
#include "not.h"
#include "or.h"
#include "pop.h"
#include "push.h"
#include "shl.h"
#include "shr.h"
#include "store.h"
#include "sub.h"
#include "xor.h"
#include <memory>

std::vector<std::shared_ptr<JiaguInterface>>  JiaguFactory::GetJiaGu(std::shared_ptr<ParseResult> Instru) {
    std::vector<std::shared_ptr<JiaguInterface>> result;
    if(Instru->m_tokens[0] == "NOP") {
        auto it = std::make_shared<NopInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "HLT") {
        auto it = std::make_shared<HltInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "MOV") {
        if(Instru->m_tokens[1] == "EP" && !Reg24bit.count(Instru->m_tokens[2])) { // MOV EP, 'LABLE'
            insertWaitLable(result, Instru->m_tokens[2]);         
            return result;
        }
        auto it = std::make_shared<MovInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "ADD") {
        auto it = std::make_shared<AddInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "SUB") {
        auto it = std::make_shared<SubInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "AND") {
        auto it = std::make_shared<AndInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "OR") {
        auto it = std::make_shared<OrInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "XOR") {
        auto it = std::make_shared<XorInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "CMP") {
        auto it = std::make_shared<CmpInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "NOT") {
        auto it = std::make_shared<NotInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "INC") {
        auto it = std::make_shared<IncInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "SHL") {
        auto it = std::make_shared<ShlInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "DEC") {
        auto it = std::make_shared<DecInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "SHR") {
        auto it = std::make_shared<ShrInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "LOAD") {
        auto it = std::make_shared<LoadInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "STORE") {
        auto it = std::make_shared<StoreInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "PUSH") {
        auto it = std::make_shared<PushInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "POP") {
        auto it = std::make_shared<PopInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "LDEL" || 
                Instru->m_tokens[0] == "LDEM" || 
                Instru->m_tokens[0] == "LDEH") {
        auto it = std::make_shared<LdexInstru>(Instru);
        result.push_back(it);
    } else if(Instru->m_tokens[0] == "JMP" || 
                Instru->m_tokens[0] == "JR" || 
                Instru->m_tokens[0] == "JZ" || 
                Instru->m_tokens[0] == "JNZ" || 
                Instru->m_tokens[0] == "JC" || 
                Instru->m_tokens[0] == "JNC") {

        insertWaitLable(result, Instru->m_tokens[1]);
        auto it = std::make_shared<JmpInstru>(Instru);
        result.push_back(it);
    }

    return result;
}

void JiaguFactory::insertWaitLable(std::vector<std::shared_ptr<JiaguInterface>> &instrus, std::string lable)
{
    auto wait_EL = std::make_shared<ParseResult>();
    wait_EL->m_type = InstrType::true_Instr;
    wait_EL->m_tokens.push_back("LDEL");
    auto wait_instru = std::make_shared<LdexInstru>(wait_EL);
    wait_instru->m_full_prepared = false;
    wait_instru->wait_lable = lable;
    instrus.push_back(wait_instru);

    auto wait_EM = std::make_shared<ParseResult>();
    wait_EM->m_type = InstrType::true_Instr;
    wait_EM->m_tokens.push_back("LDEM");
    wait_instru = std::make_shared<LdexInstru>(wait_EM);
    wait_instru->m_full_prepared = false;
    wait_instru->wait_lable = lable;
    instrus.push_back(wait_instru);

    auto wait_EH = std::make_shared<ParseResult>();
    wait_EH->m_type = InstrType::true_Instr;
    wait_EH->m_tokens.push_back("LDEH");
    wait_instru->wait_lable = lable;
    wait_instru = std::make_shared<LdexInstru>(wait_EH);
    wait_instru->m_full_prepared = false;
    instrus.push_back(wait_instru);
    return;
}