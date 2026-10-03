> 天命玄鸟，降而生商

![](pic/xuanniao.jpeg)

## REGISTER

8bit:R0,R1,R2,R3

8bit:FLAG

16bit: IR

24bit:DP,EP,SP,CP

---

* R0: 00
* R1: 01
* R2: 10
* R3: 11

* EP: 00
* DP: 01
* SP: 10
* PC: 11

| flag | 7   | 6   | 5   | 4   | 3   | 2    | 1   | 0   |
| ---- | --- | --- | --- | --- | --- | ---- | --- | --- |
|      | 0   | 0   | 0   | 0   |     | 溢出 | 奇  | 零  |

## machine code

| ASM    | OPCODE | Rd  | Rs  | IMD    | Note    |
| ------ | ------ | --- | --- | ------ | ------- |
| NOP    | 000000 | 00  | 00  | 000000 |         |
| HLT    | 000001 | 00  | 00  | 000000 |         |
| MOV_RR | 000010 | XX  | YY  | 000000 |         |
| MOV_RI | 000011 | XX  | II  | IIIIII |         |
| ADD_RR | 000100 | XX  | YY  | 000000 |         |
| ADD_RI | 000101 | XX  | II  | IIIIII |         |
| SUB_RR | 000110 | XX  | YY  | 000000 |         |
| SUB_RI | 000111 | XX  | II  | IIIIII |         |
| AND_RR | 001000 | XX  | YY  | 000000 |         |
| AND_RI | 001001 | XX  | II  | IIIIII |         |
| OR_RR  | 001010 | XX  | YY  | 000000 |         |
| OR_RI  | 001011 | XX  | II  | IIIIII |         |
| XOR_RR | 001100 | XX  | YY  | 000000 |         |
| XOR_RI | 001101 | XX  | II  | IIIIII |         |
| CMP_RR | 001110 | XX  | YY  | 000000 |         |
| CMP_RI | 001111 | XX  | II  | IIIIII |         |
| NOT    | 010000 | XX  | XX  | 000000 |         |
| INC    | 010001 | XX  | 00  | 000001 |         |
| SHL    | 010010 | XX  | XX  | 000000 |         |
| DEC    | 010011 | XX  | XX  | 000001 |         |
| SHR    | 010100 | XX  | XX  | 000000 | TODO    |
| LOAD   | 010101 | XX  | DP  | 000000 |         |
| STORE  | 010110 | DP  | YY  | 000000 |         |
| JMP    | 010111 | PC  | EP  | 000000 |         |
| JR     | 011000 | PC  | II  | IIIIII | TODO    |
| JZ     | 011001 | PC  | EP  | 000000 |         |
| JNZ    | 011010 | PC  | EP  | 000000 |         |
| JC     | 011011 | PC  | EP  | 000000 | TODO    |
| JNC    | 011100 | PC  | EP  | 000000 | TODO    |
| CALL   | 011101 | PC  | EP  | 000000 | TODO    |
| RET    | 011110 | PC  | EP  | 000000 | TODO    |
| PUSH   | 011111 | SP  | YY  | 000000 |         |
| POP    | 100000 | XX  | SP  | 000000 |         |
| MOV_PP | 100001 | XX  | EP  | 000000 |         |
| INC_PP | 100010 | EP  | 00  | 000001 | TODO    |
| DEC_PP | 100011 | EP  | 00  | 000001 | TODO    |
| INC_DP | 100100 | DP  | 00  | 000001 |         |
|        | 100101 |     |     |        | RESERVE |
|        | 100110 |     |     |        | RESERVE |
|        | 100111 |     |     |        | RESERVE |
| LDEL_R | 101000 | EP  | YY  | 000000 |         |
| LDEL_I | 101001 | EP  | II  | IIIIII |         |
| LDEM_R | 101010 | EP  | YY  | 000000 |         |
| LDEM_I | 101011 | EP  | II  | IIIIII |         |
| LDEH_R | 101100 | EP  | YY  | 000000 |         |
| LDEH_I | 101101 | EP  | II  | IIIIII |         |


## ASM instructions

- [x] NOP
- [x] HLT
- [x] ADD : ADD Rd, Rs; ADD Rd, imm
- [x] SUB : SUB Rd, Rs; SUB Rd, imm
- [x] AND : AND Rd, Rs; AND Rd, imm
- [x] OR :  OR Rd, Rs; OR Rd, imm
- [x] NOT : NOT Rd
- [x] CMP : CMP Rd, Rs; CMP Rd, imm
- [x] NOR : NOR Rd, Rs; NOR Rd, imm
- [x] INC : INC Rd; INC DP;
- [x] SHL : SHL Rd
- [x] DEC : DEC Rd
- [ ] SHR : SHR Rd
- [ ] MUL
- [ ] DIV
- [ ] CALL
- [ ] RET
- [x] MOV : MOV Rd, Rs; MOV Rd, imm; MOV Pd, Ps; MOV EP, 'lable'
- [X] PUSH : PUSH Rs
- [X] POP : POP Rd
- [X] LOAD : LOAD Rd
- [X] STORE : STORE Rs
- [x] JMP : JMP 'lable'
- [x] JZ : JZ 'lable'
- [X] JNZ : JNZ 'lable'
- [X] LDEL : LDEL imm(mov imm to EP low 8bit)
- [X] LDEM : LDEM imm(mov imm to EP middle 8bit)
- [X] LDEH : LDEH imm(mov imm to EP high 8bit)