#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
#include "InsFilter.h"
#include "TokenProcessor.h"
#include "JiaguInterface.h"
#include "buyin.h"

std::unordered_map<std::string, int> lable_pos;
std::vector<std::shared_ptr<JiaguInterface>> g_true_instrument;

int main(int argc, char* argv[]) {
    
    std::fstream srcFile;
    srcFile.open(argv[1], std::ios::in);
    // srcFile.open("../hello.asm", std::ios::in);

    std::string line;
    while(std::getline(srcFile, line)) {
        InsFilter::GetInstanc()->Proc(line);
    }

    Buyin worker;
    worker.Work();
    return 0;
}