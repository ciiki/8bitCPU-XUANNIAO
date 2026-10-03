#ifndef __BUYIN_H__
#define __BUYIN_H__
#include <fstream>

class Buyin {
public:
    Buyin();
    ~Buyin();
    void Work();

private:
    void FillLablePos();
    std::fstream m_outfile;
};
#endif // __BUYIN_H__