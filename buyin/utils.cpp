#include <iostream>
#include <string>
#include <cstdint>

bool str2immd(std::string token, uint8_t &imm) {
    uint16_t imm_data;
    try {
        if(token.size() > 2 && token.at(0) == '0' && ((token.at(1) & 0b11011111) == 'X')) {
            imm_data = std::stoi(token, nullptr, 16);
        } else {
            imm_data = std::stoi(token);
        }

        if(imm_data < 0 || imm_data > UINT8_MAX) {
            return false;
        }

        imm = imm_data;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;
}