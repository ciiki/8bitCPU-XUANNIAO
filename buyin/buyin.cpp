#include <cstdint>
#include <memory>
#include <queue>
#include <string>
#include <sys/types.h>
#include "buyin.h"
#include "common.h"
#include "JiaguInterface.h"

extern std::vector<std::shared_ptr<JiaguInterface>> g_true_instrument;
extern std::unordered_map<std::string, int> lable_pos;
extern std::queue<std::shared_ptr<JiaguInterface>> wait_pos_queue;

void Buyin::Work()
{

    for(auto e : lable_pos) {
        std::cout << e.first << ":" << e.second << std::endl;
    }
    FillLablePos();
    
    // for(auto e : g_true_instrument) {
    for(int i = 0; i < g_true_instrument.size(); i++) {
        auto e = g_true_instrument[i];
        e->compile();
        std::cout << "line: " << i << "    ";
        e->VERBOSE();
        uint16_t machineCode = e->GetMachineCode();
        m_outfile.write((const char*)&machineCode, sizeof(machineCode));
    }
}

void Buyin::FillLablePos()
{
    while(!wait_pos_queue.empty()) {
        auto item = wait_pos_queue.front();
        int true_pos;
        if(lable_pos.count(item->wait_lable)) {
            true_pos = lable_pos[item->wait_lable] << 1;
        } else {
            std::cout << "could not find lable: " <<  item->wait_lable << std::endl;
            exit(-1);
        }
        for(int i = 0; i < 3; i++) {
            auto instra = wait_pos_queue.front();
            uint8_t pos_8bit = (true_pos >> (i * 8));
            instra->appendToken(std::to_string(pos_8bit));
            wait_pos_queue.pop();
        }
    }
}

Buyin::Buyin()
{
    m_outfile.open("program.bin", std::ios::out | std::ios::binary);
}

Buyin::~Buyin()
{
    m_outfile.close();
}
