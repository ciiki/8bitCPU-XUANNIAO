#include <memory>
#include <unordered_map>
#include <queue>
#include "InsFilter.h"
#include "TokenProcessor.h"
#include "JiaguInterface.h"

// extern int g_current_lineNum;
extern std::vector<std::shared_ptr<JiaguInterface>> g_true_instrument;
extern std::unordered_map<std::string, int> lable_pos;

std::queue<std::shared_ptr<JiaguInterface>> wait_pos_queue;

bool InsFilter::Proc(std::string line)
{
    auto result = m_processer.proc(line);

    // result->Info();

    if(result->m_type == InstrType::unknown) {
        std::cout << "compile error line: " << result->m_lines << " " << result->m_source << std::endl;
        return false;
    } else if(result->m_type == InstrType::blank) {
        return true;
    } else if(result->m_type == InstrType::lable) {
        lable_pos[result->m_tokens[0]] = g_true_instrument.size();
    } else if(result->m_type == InstrType::true_Instr) {
        JiaguBuilder(result);
    }

    return true;
}

void InsFilter::JiaguBuilder(std::shared_ptr<ParseResult> Instru)
{
    auto JiaGus = factory.GetJiaGu(Instru);

    for(auto &e: JiaGus) {
        if(e->m_full_prepared == false) {
            wait_pos_queue.push(e);
        }
        g_true_instrument.push_back(e);
    }
}
