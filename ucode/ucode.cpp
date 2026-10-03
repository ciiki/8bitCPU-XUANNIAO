#include <iostream>
#include <cstdint>
#include <fstream>

//RIGHT
const uint32_t ZERO_OP    = 0;
const uint32_t EP_LOAD    = 1 << 0;
const uint32_t SP_SU      = 1 << 1;
const uint32_t SP_IC      = 1 << 2;
const uint32_t SP_CO      = 1 << 3;
const uint32_t PSL_EO     = 1 << 4;
const uint32_t PSL_EI     = 1 << 5;
const uint32_t PC_IC      = 1 << 6;
const uint32_t PC_CO      = 1 << 7;

// TOP
const uint32_t A2D_L      = 0 << 8;
const uint32_t A2D_M      = 1 << 8;
const uint32_t A2D_H      = 2 << 8;
const uint32_t A2D_EO     = 1 << 10;
const uint32_t MCT_WE     = 1 << 11;
const uint32_t MCT_CS     = 1 << 12;
// FLAG4
const uint32_t ALU_ADD    = 0 << 13;
const uint32_t ALU_SUB    = 1 << 13;
const uint32_t ALU_AND    = 2 << 13;
const uint32_t ALU_OR     = 3 << 13;
const uint32_t ALU_NOT    = 4 << 13;
const uint32_t ALU_XOR    = 5 << 13;
const uint32_t ALU_EO     = 1 << 17;
const uint32_t RSL_EO     = 1 << 18;
const uint32_t RSL_EI     = 1 << 19;

// LEFT
//OPCODE6
const uint32_t IRH_EI     = 1 << 20;
const uint32_t IRL_EI     = 1 << 21;
const uint32_t IMM_EO     = 1 << 22;
const uint32_t DP_IC      = 1 << 23;

const uint32_t HLT        = 1 << 31;

std::fstream file;

enum class UINSTRUCT : uint8_t {
NOP,
HLT,
MOV_RR,
MOV_RI,
ADD_RR,
ADD_RI,
SUB_RR,
SUB_RI,
AND_RR,
AND_RI,
OR_RR,
OR_RI,
XOR_RR,
XOR_RI,
CMP_RR,
CMP_RI,
NOT,
INC,
SHL,
DEC,
SHR,
LOAD,
STORE,
JMP,
JR,
JZ,
JNZ,
JC,
JNC,
CALL,
RET,
PUSH,
POP,
MOV_PP,
INC_PP,
DEC_PP,
INC_DP,
RESERVE2,
RESERVE3,
RESERVE4,
LDEL_R,
LDEL_I,
LDEM_R,
LDEM_I,
LDEH_R,
LDEH_I,

TOTAL_CNT,
MAX_CNT = 64
};

void FETCH_Instr() {
    uint32_t ucodes[4];

    // true instruction
    ucodes[0] = PC_CO | MCT_CS | IRL_EI;
    ucodes[1] = PC_IC;
    ucodes[2] = PC_CO | MCT_CS | IRH_EI;
    ucodes[3] = PC_IC;
    for (uint8_t uStep = 0; uStep < 4; uStep++) {
        file.write((char *)&ucodes[uStep], sizeof(uint32_t));
    }
}

void NOP_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void HLT_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = HLT;
        ucodes[1] = HLT;
        ucodes[2] = HLT;
        ucodes[3] = HLT;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void MOV_RR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = RSL_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void MOV_RI_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = IMM_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void ADD_RR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_ADD | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void ADD_RI_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_ADD | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void SUB_RR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_SUB | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void SUB_RI_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_SUB | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void AND_RR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_AND | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void AND_RI_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_AND | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void OR_RR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_OR | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void OR_RI_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_OR | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void XOR_RR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_XOR | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void XOR_RI_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_XOR | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void CMP_RR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_SUB | ALU_EO;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void CMP_RI_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_SUB | ALU_EO;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void NOT_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_NOT | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void INC_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_ADD | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void SHL_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_ADD | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void DEC_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ALU_SUB | ALU_EO | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

// 暂不支持
void SHR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void LOAD_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = PSL_EO | MCT_CS | RSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void STORE_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = PSL_EO | MCT_CS | MCT_WE | RSL_EO;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void JMP_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = PSL_EO | PSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

//TODO
void JR_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void JZ_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        if((flag & 0x1) != 0) {
            ucodes[0] = PSL_EO | PSL_EI;
        }
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void JNZ_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        if((flag & 0x1) == 0) {
            ucodes[0] = PSL_EO | PSL_EI;
        }
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void JC_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        if((flag & 0x4) != 0) {
            ucodes[0] = PSL_EO | PSL_EI;
        }
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void JNC_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        if((flag & 0x4) == 0) {
            ucodes[0] = PSL_EO | PSL_EI;
        }
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

//TODO
void CALL_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

//TODO
void RET_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void PUSH_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = SP_SU | SP_IC;
        ucodes[1] = SP_CO | MCT_CS | MCT_WE | RSL_EO;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void POP_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = SP_IC;
        ucodes[1] = SP_CO | MCT_CS | RSL_EI;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void MOV_PP_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = PSL_EO | PSL_EI;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

//TODO
void INC_PP_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

//TODO
void DEC_PP_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = ZERO_OP;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void DP_IC_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = DP_IC;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void LDEL_R_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = RSL_EO | EP_LOAD;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void LDEL_I_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = IMM_EO | EP_LOAD;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void LDEM_R_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = RSL_EO | EP_LOAD;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void LDEM_I_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = IMM_EO | EP_LOAD;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void LDEH_R_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = RSL_EO | EP_LOAD;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}

void LDEH_I_Instr() {
    for(uint8_t flag = 0; flag <= 0xf; flag++) {
        FETCH_Instr();
        uint32_t ucodes[4];

        // true instruction
        ucodes[0] = IMM_EO | EP_LOAD;
        ucodes[1] = ZERO_OP;
        ucodes[2] = ZERO_OP;
        ucodes[3] = ZERO_OP;
        for(uint8_t uStep = 0; uStep < 4; uStep++) {
            file.write((char*)&ucodes[uStep], sizeof(uint32_t));  
        }
    }
}


int main() {
    file.open("ucode.bin", std::ios::out | std::ios::binary);
    NOP_Instr();
    HLT_Instr();
    MOV_RR_Instr();
    MOV_RI_Instr();
    ADD_RR_Instr();
    ADD_RI_Instr();
    SUB_RR_Instr();
    SUB_RI_Instr();
    AND_RR_Instr();
    AND_RI_Instr();
    OR_RR_Instr();
    OR_RI_Instr();
    XOR_RR_Instr();
    XOR_RI_Instr();
    CMP_RR_Instr();
    CMP_RI_Instr();
    NOT_Instr();
    INC_Instr();
    SHL_Instr();
    DEC_Instr();
    SHR_Instr();
    LOAD_Instr();
    STORE_Instr();
    JMP_Instr();
    JR_Instr();
    JZ_Instr();
    JNZ_Instr();
    JC_Instr();
    JNC_Instr();
    CALL_Instr();
    RET_Instr();
    PUSH_Instr();
    POP_Instr();
    MOV_PP_Instr();
    INC_PP_Instr();
    DEC_PP_Instr();
    DP_IC_Instr();

    //reserve
    NOP_Instr();
    NOP_Instr();
    NOP_Instr();
    
    LDEL_R_Instr();
    LDEL_I_Instr();
    LDEM_R_Instr();
    LDEM_I_Instr();
    LDEH_R_Instr();
    LDEH_I_Instr();

    for(uint8_t instrs = (uint8_t)UINSTRUCT::TOTAL_CNT; instrs < (uint8_t)UINSTRUCT::MAX_CNT; instrs++) {
        NOP_Instr();
    }
    file.close();
    return 0; 
}