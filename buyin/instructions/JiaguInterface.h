#ifndef __JIAGUINTERFACE_H__
#define __JIAGUINTERFACE_H__
#include <cstdint>
#include <memory>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
#include "common.h"

class JiaguInterface {
public:
    JiaguInterface(std::shared_ptr<ParseResult> instru) 
    : m_Instru(instru)
    {
    }

    void appendToken(std::string token) {
        m_Instru->m_tokens.push_back(token);
    }

    uint16_t GetMachineCode() {
        return m_Instru->m_machine_code;
    }

    void VERBOSE() {
      std::cout << std::left << std::setw(32) << m_Instru->m_source << ' ';

      uint16_t data = m_Instru->m_machine_code;
      std::cout << "binary: ";
      for (int i = 15; i >= 0; --i) {
        std::cout << ((data >> i) & 1);

        if (i == 10 || i == 6) {
          std::cout << ' ';
        } else if (i == 8) {
          std::cout << ", ";
        }
      }

      std::cout << " hex:0x" << std::right << std::hex << std::setw(2)
                << std::setfill('0') << ((data >> 8) & 0xff) << " 0x"
                << std::setw(2) << std::setfill('0') << (data & 0xff)
                << std::dec << std::setfill(' ') << '\n';
    }
    virtual ~JiaguInterface() {}
    virtual bool compile() = 0;
    bool m_full_prepared{true};
    std::string wait_lable;
protected:
    std::shared_ptr<ParseResult> m_Instru;
};

#endif // __JIAGUINTERFACE_H__