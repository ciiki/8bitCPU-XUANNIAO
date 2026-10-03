    MOV EP, data
    MOV SP, EP

loop:
    POP R0
    INC DP
    INC R1
    CMP R1, 0xff
    JNZ loop
cnt:
    INC R2
    CMP R2, 16
    JNZ loop
    HLT
data: