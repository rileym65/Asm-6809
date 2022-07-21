#define MAIN

#include <time.h>
#include "header.h"

#define OP_STOP     0xff
#define OP_DIV      0x71
#define OP_MUL      0x70
#define OP_SUB      0x61
#define OP_ADD      0x60
#define OP_SHR      0x51
#define OP_SHL      0x50
#define OP_LT       0x45
#define OP_LE       0x44
#define OP_GT       0x43
#define OP_GE       0x42
#define OP_NE       0x41
#define OP_EQ       0x40
#define OP_XOR      0x32
#define OP_OR       0x31
#define OP_AND      0x30
#define OP_LAND     0x20
#define OP_LOR      0x10
#define OP_OP       0x09
#define OP_CP       0x08
#define OP_END      0x01

typedef union {
  float f;
  unsigned int i;
  } FTOI;

void addOpcode(char* op, char* trans) {
  strcpy(opcodes[numOpcodes], op);
  strcpy(translations[numOpcodes], trans);
  numOpcodes++;
  if (numOpcodes > 767) {
    printf("Opcode table full\n");
    exit(1);
    }
  }

char* get32(char* line) {
  evalErrors = 0;
  args[argCount++] = 0x1234;
  args[argCount++] = 0x5678;
  while (*line != 0) line++;
  return line;
  }

void initOpcodes() {
  numOpcodes = 0;
  addOpcode("ABX",               "3A");

  addOpcode("ADCA #{B}",         "89 [L]");
  addOpcode("ADCA <{B}",         "99 [L]");
  addOpcode("ADCA {I}",          "A9 [I]");
  addOpcode("ADCA {W}",          "B9 [W]");
  addOpcode("ADCA [{W}]",        "A9 9F [W]");

  addOpcode("ADCB #{B}",         "C9 [L]");
  addOpcode("ADCB <{B}",         "D9 [L]");
  addOpcode("ADCB {I}",          "E9 [I]");
  addOpcode("ADCB {W}",          "F9 [W]");
  addOpcode("ADCB [{W}]",        "E9 9F [W]");

  addOpcode("ADDA #{B}",         "8B [L]");
  addOpcode("ADDA <{B}",         "9B [L]");
  addOpcode("ADDA {I}",          "AB [I]");
  addOpcode("ADDA {W}",          "BB [W]");
  addOpcode("ADDA [{W}]",        "AB 9F [W]");

  addOpcode("ADDB #{B}",         "CB [L]");
  addOpcode("ADDB <{B}",         "DB [L]");
  addOpcode("ADDB {I}",          "EB [I]");
  addOpcode("ADDB {W}",          "FB [W]");
  addOpcode("ADDB [{W}]",        "EB 9F [W]");

  addOpcode("ADDD #{W}",         "C3 [W]");
  addOpcode("ADDD <{B}",         "D3 [L]");
  addOpcode("ADDD {I}",          "E3 [I]");
  addOpcode("ADDD {W}",          "F3 [W]");
  addOpcode("ADDD [{W}]",        "E3 9F [W]");

  addOpcode("ANDA #{B}",         "84 [L]");
  addOpcode("ANDA <{B}",         "94 [L]");
  addOpcode("ANDA {I}",          "A4 [I]");
  addOpcode("ANDA {W}",          "B4 [W]");
  addOpcode("ANDA [{W}]",        "A4 9F [W]");

  addOpcode("ANDB #{B}",         "C4 [L]");
  addOpcode("ANDB <{B}",         "D4 [L]");
  addOpcode("ANDB {I}",          "E4 [I]");
  addOpcode("ANDB {W}",          "F4 [W]");
  addOpcode("ANDB [{W}]",        "E4 9F [W]");

  addOpcode("ANDCC #{B}",        "1C [L]");

  addOpcode("ASLA",              "48");

  addOpcode("ASLB",              "58");

  addOpcode("ASL <{B}",          "08 [L]");
  addOpcode("ASL {I}",           "68 [I]");
  addOpcode("ASL {W}",           "78 [W]");
  addOpcode("ASL [{W}]",         "68 9F [W]");

  addOpcode("ASRA",              "47");

  addOpcode("ASRB",              "57");

  addOpcode("ASR <{B}",          "07 [L]");
  addOpcode("ASR {I}",           "67 [I]");
  addOpcode("ASR {W}",           "77 [W]");
  addOpcode("ASR [{W}]",         "67 9F [W]");

  addOpcode("BITA #{B}",         "85 [L]");
  addOpcode("BITA <{B}",         "95 [L]");
  addOpcode("BITA {I}",          "A5 [I]");
  addOpcode("BITA {W}",          "B5 [W]");
  addOpcode("BITA [{W}]",        "A5 9F [W]");

  addOpcode("BITB #{B}",         "C5 [L]");
  addOpcode("BITB <{B}",         "D5 [L]");
  addOpcode("BITB {I}",          "E5 [I]");
  addOpcode("BITB {W}",          "F5 [W]");
  addOpcode("BITB [{W}]",        "E5 9F [W]");

  addOpcode("CLRA",              "4F");

  addOpcode("CLRB",              "5F");

  addOpcode("CLR <{B}",          "0F [L]");
  addOpcode("CLR {I}",           "6F [I]");
  addOpcode("CLR {W}",           "7F [W]");
  addOpcode("CLR [{W}]",         "6F 9F [W]");

  addOpcode("CMPA #{B}",         "81 [L]");
  addOpcode("CMPA <{B}",         "91 [L]");
  addOpcode("CMPA {I}",          "A1 [I]");
  addOpcode("CMPA {W}",          "B1 [W]");
  addOpcode("CMPA [{W}]",        "A1 9F [W]");

  addOpcode("CMPB #{B}",         "C1 [L]");
  addOpcode("CMPB <{B}",         "D1 [L]");
  addOpcode("CMPB {I}",          "E1 [I]");
  addOpcode("CMPB {W}",          "F1 [W]");
  addOpcode("CMPB [{W}]",        "E1 9F [W]");

  addOpcode("CMPD #{W}",         "10 83 [W]");
  addOpcode("CMPD <{B}",         "10 93 [L]");
  addOpcode("CMPD {I}",          "10 A3 [I]");
  addOpcode("CMPD {W}",          "10 B3 [W]");
  addOpcode("CMPD [{W}]",        "10 A3 9F [W]");

  addOpcode("CMPS #{W}",         "11 8C [W]");
  addOpcode("CMPS <{B}",         "11 9C [L]");
  addOpcode("CMPS {I}",          "11 AC [I]");
  addOpcode("CMPS {W}",          "11 BC [W]");
  addOpcode("CMPS [{W}]",        "11 AC 9F [W]");

  addOpcode("CMPU #{W}",         "11 83 [W]");
  addOpcode("CMPU <{B}",         "11 93 [L]");
  addOpcode("CMPU {I}",          "11 A3 [I]");
  addOpcode("CMPU {W}",          "11 B3 [W]");
  addOpcode("CMPU [{W}]",        "11 A3 9F [W]");

  addOpcode("CMPX #{W}",         "8C [W]");
  addOpcode("CMPX <{B}",         "9C [L]");
  addOpcode("CMPX {I}",          "AC [I]");
  addOpcode("CMPX {W}",          "BC [W]");
  addOpcode("CMPX [{W}]",        "AC 9F [W]");

  addOpcode("CMPY #{W}",         "10 8C [W]");
  addOpcode("CMPY <{B}",         "10 9C [L]");
  addOpcode("CMPY {I}",          "10 AC [I]");
  addOpcode("CMPY {W}",          "10 BC [W]");
  addOpcode("CMPY [{W}]",        "10 AC 9F [W]");

  addOpcode("COMA",              "43");

  addOpcode("COMB",              "53");

  addOpcode("COM <{B}",          "03 [L]");
  addOpcode("COM {I}",           "63 [I]");
  addOpcode("COM {W}",           "73 [W]");
  addOpcode("COM [{W}]",         "63 9F [W]");

  addOpcode("CWAI #{B}",         "3C [L]");

  addOpcode("DAA",               "19");

  addOpcode("DECA",              "4A");

  addOpcode("DECB",              "5A");

  addOpcode("DEC <{B}",          "0A [L]");
  addOpcode("DEC {I}",           "6A [I]");
  addOpcode("DEC {W}",           "7A [W]");
  addOpcode("DEC [{W}]",         "6A 9F [W]");

  addOpcode("EORA #{B}",         "88 [L]");
  addOpcode("EORA <{B}",         "98 [L]");
  addOpcode("EORA {I}",          "A8 [I]");
  addOpcode("EORA {W}",          "B8 [W]");
  addOpcode("EORA [{W}]",        "A8 9F [W]");

  addOpcode("EORB #{B}",         "C8 [L]");
  addOpcode("EORB <{B}",         "D8 [L]");
  addOpcode("EORB {I}",          "E8 [I]");
  addOpcode("EORB {W}",          "F8 [W]");
  addOpcode("EORB [{W}]",        "E8 9F [W]");

  addOpcode("EXG {RP}",          "1E [L]");

  addOpcode("INCA",              "4C");

  addOpcode("INCB",              "5C");

  addOpcode("INC <{B}",          "0C [L]");
  addOpcode("INC {I}",           "6C [I]");
  addOpcode("INC {W}",           "7C [W]");
  addOpcode("INC [{W}]",         "6C 9F [W]");

  addOpcode("JMP <{B}",          "0E [L]");
  addOpcode("JMP {I}",           "6E [I]");
  addOpcode("JMP {W}",           "7E [W]");
  addOpcode("JMP [{W}]",         "6E 9F [W]");

  addOpcode("JSR <{B}",          "9D [L]");
  addOpcode("JSR {I}",           "AD [I]");
  addOpcode("JSR {W}",           "BD [W]");
  addOpcode("JSR [{W}]",         "AD 9F [W]");

  addOpcode("LDA #{B}",          "86 [L]");
  addOpcode("LDA <{B}",          "96 [L]");
  addOpcode("LDA {I}",           "A6 [I]");
  addOpcode("LDA {W}",           "B6 [W]");
  addOpcode("LDA [{W}]",         "A6 9F [W]");

  addOpcode("LDB #{B}",          "C6 [L]");
  addOpcode("LDB <{B}",          "D6 [L]");
  addOpcode("LDB {I}",           "E6 [I]");
  addOpcode("LDB {W}",           "F6 [W]");
  addOpcode("LDB [{W}]",         "E6 9F [W]");

  addOpcode("LDD #{W}",          "CC [W]");
  addOpcode("LDD <{B}",          "DC [L]");
  addOpcode("LDD {I}",           "EC [I]");
  addOpcode("LDD {W}",           "FC [W]");
  addOpcode("LDD [{W}]",         "EC 9F [W]");

  addOpcode("LDS #{W}",          "10 CE [W]");
  addOpcode("LDS <{B}",          "10 DE [L]");
  addOpcode("LDS {I}",           "10 EE [I]");
  addOpcode("LDS {W}",           "10 FE [W]");
  addOpcode("LDS [{W}]",         "10 EE 9F [W]");

  addOpcode("LDU #{W}",          "CE [W]");
  addOpcode("LDU <{B}",          "DE [L]");
  addOpcode("LDU {I}",           "EE [I]");
  addOpcode("LDU {W}",           "FE [W]");
  addOpcode("LDU [{W}]",         "EE 9F [W]");

  addOpcode("LDX #{W}",          "8E [W]");
  addOpcode("LDX <{B}",          "9E [L]");
  addOpcode("LDX {I}",           "AE [I]");
  addOpcode("LDX {W}",           "BE [W]");
  addOpcode("LDX [{W}]",         "AE 9F [W]");

  addOpcode("LDY #{W}",          "10 8E [W]");
  addOpcode("LDY <{B}",          "10 9E [L]");
  addOpcode("LDY {I}",           "10 AE [I]");
  addOpcode("LDY {W}",           "10 BE [W]");
  addOpcode("LDY [{W}]",         "10 AE 9F [W]");

  addOpcode("LEAX {I}",          "30 [I]");
  addOpcode("LEAY {I}",          "31 [I]");
  addOpcode("LEAS {I}",          "32 [I]");
  addOpcode("LEAU {I}",          "33 [I]");

  addOpcode("LSLA",              "48");

  addOpcode("LSLB",              "58");

  addOpcode("LSL <{B}",          "08 [L]");
  addOpcode("LSL {I}",           "68 [I]");
  addOpcode("LSL {W}",           "78 [W]");
  addOpcode("LSL [{W}]",         "68 9F [W]");

  addOpcode("LSRA",              "44");

  addOpcode("LSRB",              "54");

  addOpcode("LSR <{B}",          "04 [L]");
  addOpcode("LSR {I}",           "64 [I]");
  addOpcode("LSR {W}",           "74 [W]");
  addOpcode("LSR [{W}]",         "64 9F [W]");

  addOpcode("MUL",               "3D");

  addOpcode("NEGA",              "40");

  addOpcode("NEGB",              "50");

  addOpcode("NEG <{B}",          "00 [L]");
  addOpcode("NEG {I}",           "60 [I]");
  addOpcode("NEG {W}",           "70 [W]");
  addOpcode("NEG [{W}]",         "60 9F [W]");

  addOpcode("NOP",               "12");

  addOpcode("ORA #{B}",          "8A [L]");
  addOpcode("ORA <{B}",          "9A [L]");
  addOpcode("ORA {I}",           "AA [I]");
  addOpcode("ORA {W}",           "BA [W]");
  addOpcode("ORA [{W}]",         "AA 9F [W]");

  addOpcode("ORA #{B}",          "CA [L]");
  addOpcode("ORA <{B}",          "DA [L]");
  addOpcode("ORA {I}",           "EA [I]");
  addOpcode("ORA {W}",           "FA [W]");
  addOpcode("ORA [{W}]",         "EA 9F [W]");

  addOpcode("ORCC #{B}",         "1A [L]");

  addOpcode("PSHS {RL}",         "34 [L]");

  addOpcode("PSHU {RL}",         "36 [L]");

  addOpcode("PULS {RL}",         "35 [L]");

  addOpcode("PULU {RL}",         "37 [L]");

  addOpcode("ROLA",              "49");

  addOpcode("ROLB",              "59");

  addOpcode("ROL <{B}",          "09 [L]");
  addOpcode("ROL {I}",           "69 [I]");
  addOpcode("ROL {W}",           "79 [W]");
  addOpcode("ROL [{W}]",         "69 9F [W]");

  addOpcode("RORA",              "46");

  addOpcode("RORB",              "56");

  addOpcode("ROR <{B}",          "06 [L]");
  addOpcode("ROR {I}",           "66 [I]");
  addOpcode("ROR {W}",           "76 [W]");
  addOpcode("ROR [{W}]",         "66 9F [W]");

  addOpcode("RTI",               "3B");

  addOpcode("RTS",               "39");

  addOpcode("SBCA #{B}",         "82 [L]");
  addOpcode("SBCA <{B}",         "92 [L]");
  addOpcode("SBCA {I}",          "A2 [I]");
  addOpcode("SBCA {W}",          "B2 [W]");
  addOpcode("SBCA [{W}]",        "A2 9F [W]");

  addOpcode("SBCB #{B}",         "C2 [L]");
  addOpcode("SBCB <{B}",         "D2 [L]");
  addOpcode("SBCB {I}",          "E2 [I]");
  addOpcode("SBCB {W}",          "F2 [W]");
  addOpcode("SBCB [{W}]",        "E2 9F [W]");

  addOpcode("SEX",               "1D");

  addOpcode("STA <{B}",          "97 [L]");
  addOpcode("STA {I}",           "A7 [I]");
  addOpcode("STA {W}",           "B7 [W]");
  addOpcode("STA [{W}]",         "A7 9F [W]");

  addOpcode("STB <{B}",          "D7 [L]");
  addOpcode("STB {I}",           "E7 [I]");
  addOpcode("STB {W}",           "F7 [W]");
  addOpcode("STB [{W}]",         "E7 9F [W]");

  addOpcode("STD <{B}",          "DD [L]");
  addOpcode("STD {I}",           "ED [I]");
  addOpcode("STD {W}",           "FD [W]");
  addOpcode("STD [{W}]",         "ED 9F [W]");

  addOpcode("STS <{B}",          "10 DF [L]");
  addOpcode("STS {I}",           "10 EF [I]");
  addOpcode("STS {W}",           "10 FF [W]");
  addOpcode("STS [{W}]",         "10 EF 9F [W]");

  addOpcode("STU <{B}",          "DF [L]");
  addOpcode("STU {I}",           "EF [I]");
  addOpcode("STU {W}",           "FF [W]");
  addOpcode("STU [{W}]",         "EF 9F [W]");

  addOpcode("STX <{B}",          "9F [L]");
  addOpcode("STX {I}",           "AF [I]");
  addOpcode("STX {W}",           "BF [W]");
  addOpcode("STX [{W}]",         "AF 9F [W]");

  addOpcode("STY <{B}",          "10 9F [L]");
  addOpcode("STY {I}",           "10 AF [I]");
  addOpcode("STY {W}",           "10 BF [W]");
  addOpcode("STY [{W}]",         "10 AF 9F [W]");

  addOpcode("SUBA #{B}",         "80 [L]");
  addOpcode("SUBA <{B}",         "90 [L]");
  addOpcode("SUBA {I}",          "A0 [I]");
  addOpcode("SUBA {W}",          "B0 [W]");
  addOpcode("SUBA [{W}]",        "A0 9F [W]");

  addOpcode("SUBB #{B}",         "C0 [L]");
  addOpcode("SUBB <{B}",         "D0 [L]");
  addOpcode("SUBB {I}",          "E0 [I]");
  addOpcode("SUBB {W}",          "F0 [W]");
  addOpcode("SUBB [{W}]",        "E0 9F [W]");

  addOpcode("SUBD #{W}",         "83 [W]");
  addOpcode("SUBD <{B}",         "93 [L]");
  addOpcode("SUBD {I}",          "A3 [I]");
  addOpcode("SUBD {W}",          "B3 [W]");
  addOpcode("SUBD [{W}]",        "A3 9F [W]");

  addOpcode("SWI",               "3F");

  addOpcode("SWI2",              "10 3F");

  addOpcode("SWI3",              "11 3F");

  addOpcode("SYNC",              "13");

  addOpcode("TFR {RP}",          "1F [L]");

  addOpcode("TSTA",              "4D");

  addOpcode("TSTB",              "5D");

  addOpcode("TST <{B}",          "0D [L]");
  addOpcode("TST {I}",           "6D [I]");
  addOpcode("TST {W}",           "7D [W]");
  addOpcode("TST [{W}]",         "6D 9F [W]");

  addOpcode("BCC {W}",           "24 [D]");
  addOpcode("BCS {W}",           "25 [D]");
  addOpcode("BEQ {W}",           "27 [D]");
  addOpcode("BGE {W}",           "2C [D]");
  addOpcode("BGT {W}",           "2E [D]");
  addOpcode("BHI {W}",           "22 [D]");
  addOpcode("BHS {W}",           "24 [D]");
  addOpcode("BLE {W}",           "2F [D]");
  addOpcode("BLO {W}",           "25 [D]");
  addOpcode("BLS {W}",           "23 [D]");
  addOpcode("BLT {W}",           "2D [D]");
  addOpcode("BMI {W}",           "2B [D]");
  addOpcode("BNE {W}",           "26 [D]");
  addOpcode("BPL {W}",           "2A [D]");
  addOpcode("BRA {W}",           "20 [D]");
  addOpcode("BRN {W}",           "21 [D]");
  addOpcode("BRN",               "21 00");
  addOpcode("BSR {W}",           "8D [D]");
  addOpcode("BVC {W}",           "28 [D]");
  addOpcode("BVS {W}",           "29 [D]");

  addOpcode("LBCC {W}",          "10 24 [DW]");
  addOpcode("LBCS {W}",          "10 25 [DW]");
  addOpcode("LBEQ {W}",          "10 27 [DW]");
  addOpcode("LBGE {W}",          "10 2C [DW]");
  addOpcode("LBGT {W}",          "10 2E [DW]");
  addOpcode("LBHI {W}",          "10 22 [DW]");
  addOpcode("LBHS {W}",          "10 24 [DW]");
  addOpcode("LBLE {W}",          "10 2F [DW]");
  addOpcode("LBLO {W}",          "10 25 [DW]");
  addOpcode("LBLS {W}",          "10 23 [DW]");
  addOpcode("LBLT {W}",          "10 2D [DW]");
  addOpcode("LBMI {W}",          "10 2B [DW]");
  addOpcode("LBNE {W}",          "10 26 [DW]");
  addOpcode("LBPL {W}",          "10 2A [DW]");
  addOpcode("LBRA {W}",          "10 20 [DW]");
  addOpcode("LBRN {W}",          "10 21 [DW]");
  addOpcode("LBRN",              "10 21 00 00");
  addOpcode("LBSR {W}",          "10 8D [DW]");
  addOpcode("LBVC {W}",          "10 28 [DW]");
  addOpcode("LBVS {W}",          "10 29 [DW]");
  }

void init6309Opcodes() {
  if (loaded6309 != 0) return;
  loaded6309 = -1;
  addOpcode("ADCD #{W}",         "10 89 [W]");
  addOpcode("ADCD <{B}",         "10 99 [L]");
  addOpcode("ADCD {I}",          "10 A9 [I]");
  addOpcode("ADCD {W}",          "10 B9 [W]");
  addOpcode("ADCD [{W}]",        "10 A9 9F [W]");

  addOpcode("ADCR {RP}",         "10 31 [L]");

  addOpcode("ADDE #{B}",         "11 8B [L]");
  addOpcode("ADDE <{B}",         "11 9B [L]");
  addOpcode("ADDE {I}",          "11 AB [I]");
  addOpcode("ADDE {W}",          "11 BB [W]");
  addOpcode("ADDE [{W}]",        "11 AB 9F [W]");

  addOpcode("ADDF #{B}",         "11 CB [L]");
  addOpcode("ADDF <{B}",         "11 DB [L]");
  addOpcode("ADDF {I}",          "11 EB [I]");
  addOpcode("ADDF {W}",          "11 FB [W]");
  addOpcode("ADDF [{W}]",        "11 EB 9F [W]");

  addOpcode("ADDW #{W}",         "10 8B [W]");
  addOpcode("ADDW <{B}",         "10 9B [L]");
  addOpcode("ADDW {I}",          "10 AB [I]");
  addOpcode("ADDW {W}",          "10 BB [W]");
  addOpcode("ADDW [{W}]",        "10 AB 9F [W]");

  addOpcode("AIM #{B},<{B}",     "02 [L] + [L]");
  addOpcode("AIM #{B},{I}",      "62 [L] + [I]");
  addOpcode("AIM #{B},{W}",      "72 [L] + [W]");

  addOpcode("ADDR {RP}",         "10 30 [L]");

  addOpcode("ANDD #{W}",         "10 84 [W]");
  addOpcode("ANDD <{B}",         "10 94 [L]");
  addOpcode("ANDD {I}",          "10 A4 [I]");
  addOpcode("ANDD {W}",          "10 B4 [W]");
  addOpcode("ANDD [{W}]",        "10 A4 9F [W]");

  addOpcode("ANDR {RP}",         "10 34 [L]");

  addOpcode("ASLD",              "10 48");

  addOpcode("ASRD",              "10 47");

  addOpcode("BAND A,{B},{B},{B}", "11 30 40[BT] ++ [L]");
  addOpcode("BAND B,{B},{B},{B}", "11 30 80[BT] ++ [L]");
  addOpcode("BAND CC,{B},{B},{B}","11 30 00[BT] ++ [L]");

  addOpcode("BEOR A,{B},{B},{B}", "11 34 40[BT] ++ [L]");
  addOpcode("BEOR B,{B},{B},{B}", "11 34 80[BT] ++ [L]");
  addOpcode("BEOR CC,{B},{B},{B}","11 34 00[BT] ++ [L]");

  addOpcode("BIAND A,{B},{B},{B}", "11 31 40[BT] ++ [L]");
  addOpcode("BIAND B,{B},{B},{B}", "11 31 80[BT] ++ [L]");
  addOpcode("BIAND CC,{B},{B},{B}","11 31 00[BT] ++ [L]");

  addOpcode("BIEOR A,{B},{B},{B}", "11 35 40[BT] ++ [L]");
  addOpcode("BIEOR B,{B},{B},{B}", "11 35 80[BT] ++ [L]");
  addOpcode("BIEOR CC,{B},{B},{B}","11 35 00[BT] ++ [L]");

  addOpcode("BIOR A,{B},{B},{B}", "11 33 40[BT] ++ [L]");
  addOpcode("BIOR B,{B},{B},{B}", "11 33 80[BT] ++ [L]");
  addOpcode("BIOR CC,{B},{B},{B}","11 33 00[BT] ++ [L]");

  addOpcode("BOR A,{B},{B},{B}", "11 32 40[BT] ++ [L]");
  addOpcode("BOR B,{B},{B},{B}", "11 32 80[BT] ++ [L]");
  addOpcode("BOR CC,{B},{B},{B}","11 32 00[BT] ++ [L]");

  addOpcode("LDBT A,{B},{B},{B}", "11 36 40[BT] ++ [L]");
  addOpcode("LDBT B,{B},{B},{B}", "11 36 80[BT] ++ [L]");
  addOpcode("LDBT CC,{B},{B},{B}","11 36 00[BT] ++ [L]");

  addOpcode("STBT A,{B},{B},{B}", "11 37 40[BT] ++ [L]");
  addOpcode("STBT B,{B},{B},{B}", "11 37 80[BT] ++ [L]");
  addOpcode("STBT CC,{B},{B},{B}","11 37 00[BT] ++ [L]");
 
  addOpcode("BITD #{W}",         "10 85 [W]");
  addOpcode("BITD <{B}",         "10 95 [L]");
  addOpcode("BITD {I}",          "10 A5 [I]");
  addOpcode("BITD {W}",          "10 B5 [W]");
  addOpcode("BITD [{W}]",        "10 A5 9F [W]");

  addOpcode("BITMD #{B}",        "11 3C [L]");

  addOpcode("CLRD",              "10 4F");

  addOpcode("CLRE",              "11 4F");

  addOpcode("CLRF",              "11 5F");

  addOpcode("CLRW",              "10 5F");

  addOpcode("CMPE #{B}",         "11 81 [L]");
  addOpcode("CMPE <{B}",         "11 91 [L]");
  addOpcode("CMPE {I}",          "11 A1 [I]");
  addOpcode("CMPE {W}",          "11 B1 [W]");
  addOpcode("CMPE [{W}]",        "11 A1 9F [W]");

  addOpcode("CMPF #{B}",         "11 C1 [L]");
  addOpcode("CMPF <{B}",         "11 D1 [L]");
  addOpcode("CMPF {I}",          "11 E1 [I]");
  addOpcode("CMPF {W}",          "11 F1 [W]");
  addOpcode("CMPF [{W}]",        "11 E1 9F [W]");

  addOpcode("CMPW #{W}",         "10 81 [W]");
  addOpcode("CMPW <{B}",         "10 91 [L]");
  addOpcode("CMPW {I}",          "10 A1 [I]");
  addOpcode("CMPW {W}",          "10 B1 [W]");
  addOpcode("CMPW [{W}]",        "10 A1 9F [W]");

  addOpcode("CMPR {RP}",         "10 37 [L]");

  addOpcode("COMD",              "10 43");

  addOpcode("COME",              "11 43");

  addOpcode("COMF",              "11 53");

  addOpcode("COMW",              "10 53");

  addOpcode("DECD",              "10 4A");

  addOpcode("DECE",              "11 4A");

  addOpcode("DECF",              "11 5A");

  addOpcode("DECW",              "10 5A");

  addOpcode("DIVD #{B}",         "11 8D [L]");
  addOpcode("DIVD <{B}",         "11 9D [L]");
  addOpcode("DIVD {I}",          "11 AD [I]");
  addOpcode("DIVD {W}",          "11 BD [W]");
  addOpcode("DIVD [{W}]",        "11 AD 9F [W]");

  addOpcode("DIVQ #{W}",         "11 8E [W]");
  addOpcode("DIVQ <{B}",         "11 9E [L]");
  addOpcode("DIVQ {I}",          "11 AE [I]");
  addOpcode("DIVQ {W}",          "11 BE [W]");
  addOpcode("DIVQ [{W}]",        "11 AE 9F [W]");

  addOpcode("EIM #{B},<{B}",     "05 [L] + [L]");
  addOpcode("EIM #{B},{I}",      "65 [L] + [I]");
  addOpcode("EIM #{B},{W}",      "75 [L] + [W]");

  addOpcode("EORD #{W}",         "10 88 [W]");
  addOpcode("EORD <{B}",         "10 98 [L]");
  addOpcode("EORD {I}",          "10 A8 [I]");
  addOpcode("EORD {W}",          "10 B8 [W]");
  addOpcode("EORD [{W}]",        "10 A8 9F [W]");

  addOpcode("EORR {RP}",         "10 36 [L]");

  addOpcode("INCD",              "10 4C");

  addOpcode("INCE",              "11 4C");

  addOpcode("INCF",              "11 5C");

  addOpcode("INCW",              "10 5C");

  addOpcode("LDE #{B}",          "11 86 [L]");
  addOpcode("LDE <{B}",          "11 96 [L]");
  addOpcode("LDE {I}",           "11 A6 [I]");
  addOpcode("LDE {W}",           "11 B6 [W]");
  addOpcode("LDE [{W}]",         "11 A6 9F [W]");

  addOpcode("LDF #{B}",          "11 C6 [L]");
  addOpcode("LDF <{B}",          "11 D6 [L]");
  addOpcode("LDF {I}",           "11 E6 [I]");
  addOpcode("LDF {W}",           "11 F6 [W]");
  addOpcode("LDF [{W}]",         "11 E6 9F [W]");

  addOpcode("LDW #{W}",          "10 86 [W]");
  addOpcode("LDW <{B}",          "10 96 [L]");
  addOpcode("LDW {I}",           "10 A6 [I]");
  addOpcode("LDW {W}",           "10 B6 [W]");
  addOpcode("LDW [{W}]",         "10 A6 9F [W]");

  addOpcode("LDMD #{B}",         "11 3D [L]");

  addOpcode("LDQ #{Q}",          "CD [Q]");
  addOpcode("LDQ <{B}",          "10 DC [L]");
  addOpcode("LDQ {I}",           "10 EC [I]");
  addOpcode("LDQ {W}",           "10 FC [W]");
  addOpcode("LDQ [{W}]",         "10 EC 9F [W]");

  addOpcode("LSLD",              "10 48");

  addOpcode("LSRD",              "10 44");

  addOpcode("LSRW",              "10 54");

  addOpcode("MULD #{W}",         "11 8F [W]");
  addOpcode("MULD <{B}",         "11 9F [L]");
  addOpcode("MULD {I}",          "11 AF [I]");
  addOpcode("MULD {W}",          "11 BF [W]");
  addOpcode("MULD [{W}]",        "11 AF 9F [W]");

  addOpcode("NEGD",              "10 40");

  addOpcode("OIM #{B},<{B}",     "01 [L] + [L]");
  addOpcode("OIM #{B},{I}",      "61 [L] + [I]");
  addOpcode("OIM #{B},{W}",      "71 [L] + [W]");

  addOpcode("ORD #{W}",          "10 8A [W]");
  addOpcode("ORD <{B}",          "10 9A [L]");
  addOpcode("ORD {I}",           "10 AA [I]");
  addOpcode("ORD {W}",           "10 BA [W]");
  addOpcode("ORD [{W}]",         "10 AA 9F [W]");

  addOpcode("ORR {RP}",          "10 35 [L]");

  addOpcode("PSHSW",             "10 38");

  addOpcode("PSHUW",             "10 3A");

  addOpcode("PULSW",             "10 39");

  addOpcode("PULUW",             "10 3B");

  addOpcode("ROLD",              "10 49");

  addOpcode("ROLW",              "10 59");

  addOpcode("RORD",              "10 46");

  addOpcode("RORW",              "10 56");

  addOpcode("SBCD #{W}",         "10 82 [W]");
  addOpcode("SBCD <{B}",         "10 92 [L]");
  addOpcode("SBCD {I}",          "10 A2 [I]");
  addOpcode("SBCD {W}",          "10 B2 [W]");
  addOpcode("SBCD [{W}]",        "10 A2 9F [W]");

  addOpcode("SBCR {RP}",         "10 33 [L]");

  addOpcode("SEXW",              "14");

  addOpcode("STE <{B}",          "11 97 [L]");
  addOpcode("STE {I}",           "11 A7 [I]");
  addOpcode("STE {W}",           "11 B7 [W]");
  addOpcode("STE [{W}]",         "11 A7 9F [W]");

  addOpcode("STF <{B}",          "11 D7 [L]");
  addOpcode("STF {I}",           "11 E7 [I]");
  addOpcode("STF {W}",           "11 F7 [W]");
  addOpcode("STF [{W}]",         "11 E7 9F [W]");

  addOpcode("STW <{B}",          "10 97 [L]");
  addOpcode("STW {I}",           "10 A7 [I]");
  addOpcode("STW {W}",           "10 B7 [W]");
  addOpcode("STW [{W}]",         "10 A7 9F [W]");

  addOpcode("STQ <{B}",          "10 DD [L]");
  addOpcode("STQ {I}",           "10 ED [I]");
  addOpcode("STQ {W}",           "10 FD [W]");
  addOpcode("STQ [{W}]",         "10 ED 9F [W]");

  addOpcode("SUBE #{B}",         "11 80 [L]");
  addOpcode("SUBE <{B}",         "11 90 [L]");
  addOpcode("SUBE {I}",          "11 A0 [I]");
  addOpcode("SUBE {W}",          "11 B0 [W]");
  addOpcode("SUBE [{W}]",        "11 A0 9F [W]");

  addOpcode("SUBF #{B}",         "11 C0 [L]");
  addOpcode("SUBF <{B}",         "11 D0 [L]");
  addOpcode("SUBF {I}",          "11 E0 [I]");
  addOpcode("SUBF {W}",          "11 F0 [W]");
  addOpcode("SUBF [{W}]",        "11 E0 9F [W]");

  addOpcode("SUBW #{W}",         "10 80 [W]");
  addOpcode("SUBW <{B}",         "10 90 [L]");
  addOpcode("SUBW {I}",          "10 A0 [I]");
  addOpcode("SUBW {W}",          "10 B0 [W]");
  addOpcode("SUBW [{W}]",        "10 A0 9F [W]");

  addOpcode("SUBR {RP}",         "10 32 [L]");

  addOpcode("TIM #{B},<{B}",     "0B [L] + [L]");
  addOpcode("TIM #{B},{I}",      "6B [L] + [I]");
  addOpcode("TIM #{B},{W}",      "7B [L] + [W]");

  addOpcode("TSTD",              "10 4D");

  addOpcode("TSTE",              "11 4D");

  addOpcode("TSTF",              "11 5D");

  addOpcode("TSTW",              "10 5D");

  addOpcode("TFM {IR}+,{IR}+",   "11 38 [TF]");
  addOpcode("TFM {IR}-,{IR}-",   "11 39 [TF]");
  addOpcode("TFM {IR}+,{IR}",    "11 3A [TF]");
  addOpcode("TFM {IR},{IR}+",    "11 3B [TF]");
  }


void addIndex(char* op, char* trans) {
  strcpy(indexes[numIndexes], op);
  strcpy(indexTranslations[numIndexes], trans);
  numIndexes++;
  if (numIndexes > 128) {
    printf("Index table full\n");
    exit(1);
    }
  }

void initIndexes() {
  numIndexes = 0;
  addIndex("B,X",               "85");
  addIndex("A,X",               "86");
  addIndex("B,Y",               "A5");
  addIndex("A,Y",               "A6");
  addIndex("B,U",               "C5");
  addIndex("A,U",               "C6");
  addIndex("B,S",               "E5");
  addIndex("A,S",               "E6");
  addIndex("[B,X]",             "95");
  addIndex("[A,X]",             "96");
  addIndex("[B,Y]",             "B5");
  addIndex("[A,Y]",             "B6");
  addIndex("[B,U]",             "D5");
  addIndex("[A,U]",             "D6");
  addIndex("[B,S]",             "F5");
  addIndex("[A,S]",             "F6");

  addIndex("{5},X",             "0[5]");
  addIndex(",X++",              "81");
  addIndex(",X+",               "80");
  addIndex(",-X",               "82");
  addIndex(",--X",              "83");
  addIndex(",X",                "84");
  addIndex("{B},X",             "88 [L]");
  addIndex("{W},X",             "89 [W]");
  addIndex("D,X",               "8B");
  addIndex("{B},PC",            "8C [L]");
  addIndex("{W},PC",            "8D [W]");
  addIndex("[,X++]",            "91");
  addIndex("[,--X]",            "93");
  addIndex("[,X]",              "94");
  addIndex("[{B},X]",           "98 [L]");
  addIndex("[{W},X]",           "99 [W]");
  addIndex("[D,X]",             "9B");
  addIndex("[{B},PC]",          "9C [L]");
  addIndex("[{W},PC]",          "9D [W]");

  addIndex("{5},Y",             "2[5]");
  addIndex(",Y++",              "A1");
  addIndex(",Y+",               "A0");
  addIndex(",-Y",               "A2");
  addIndex(",--Y",              "A3");
  addIndex(",Y",                "A4");
  addIndex("{B},Y",             "A8 [L]");
  addIndex("{W},Y",             "A9 [W]");
  addIndex("D,Y",               "AB");
  addIndex("[,Y++]",            "B1");
  addIndex("[,--Y]",            "B3");
  addIndex("[,Y]",              "B4");
  addIndex("[{B},Y]",           "B8 [L]");
  addIndex("[{W},Y]",           "B9 [W]");
  addIndex("[D,Y]",             "BB");

  addIndex("{5},U",             "4[5]");
  addIndex(",U++",              "C1");
  addIndex(",U+",               "C0");
  addIndex(",-U",               "C2");
  addIndex(",--U",              "C3");
  addIndex(",U",                "C4");
  addIndex("{B},U",             "C8 [L]");
  addIndex("{W},U",             "C9 [W]");
  addIndex("D,U",               "CB");
  addIndex("[,U++]",            "D1");
  addIndex("[,--U]",            "D3");
  addIndex("[,U]",              "D4");
  addIndex("[{B},U]",           "D8 [L]");
  addIndex("[{W},U]",           "D9 [W]");
  addIndex("[D,U]",             "DB");

  addIndex("{5},S",             "6[5]");
  addIndex(",S++",              "E1");
  addIndex(",S+",               "E0");
  addIndex(",-S",               "E2");
  addIndex(",--S",              "E3");
  addIndex(",S",                "E4");
  addIndex("{B},S",             "E8 [L]");
  addIndex("{W},S",             "E9 [W]");
  addIndex("D,S",               "EB");
  addIndex("[,S++]",            "F1");
  addIndex("[,--S]",            "F3");
  addIndex("[,S]",              "F4");
  addIndex("[{B},S]",           "F8 [L]");
  addIndex("[{W},S]",           "F9 [W]");
  addIndex("[D,S]",             "FB");
  }

char* trim(char* buffer) {
  while (*buffer == ' ' || *buffer == '\t') buffer++;
  return buffer;
  }

char* nextWord(char*buffer) {
  while (*buffer != 0 && *buffer != ' ' && *buffer != '\t') buffer++;
  return trim(buffer);
  }

void writeOutput() {
  int  i;
  char buffer[256];
  char tmp[4];
  sprintf(buffer,":%04x",outAddress);
  for (i=0; i<outCount; i++) {
    sprintf(tmp," %02x",outBytes[i]);
    strcat(buffer,tmp);
    }
  fprintf(outFile,"%s\n",buffer);
  outCount = 0;
  outAddress = address;
  }

void output(byte value) {
  int  i;
  char tmp[4];
  codeGenerated++;
  address++;
  instructionBytes++;
  sprintf(tmp," %02x",value);
  strcat(listLine,tmp);
  if (instructionBytes == 4) {
    strcat(listLine,"  ");
    strcat(listLine, sourceLine);
    }
  if ((instructionBytes % 4) == 0) {
    if (pass == 2) {
      if (showList != 0) printf("%s\n",listLine);
      if (createListFile != 0) fprintf(listFile,"%s\n",listLine);
      }
    strcpy(listLine,"             ");
    }
  if (pass == 2) {
    outBytes[outCount++] = value;
    if (outCount == 16) {
      writeOutput();
      }
    }
  }

int findLabelNumber(char* name) {
  int i;
  int j;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0 &&
        strcasecmp(labelProcs[i], module) == 0)
      return i;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0 &&
        strcasecmp(labelProcs[i], "*") == 0)
      return i;
  return -1;
  }

word findLabel(char* name, char* err) {
  int i;
  int j;
  *err = 0;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0 &&
        strcasecmp(labelProcs[i], module) == 0) {
      usedLocal = -1;
      for (j=0; j<numExternals; j++)
        if (externals[j] == i) {
          usedExternal = j;
          }
      return labelValues[i];
      }
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0 &&
        strcasecmp(labelProcs[i], "*") == 0) {
      for (j=0; j<numExternals; j++)
        if (externals[j] == i) {
          usedExternal = j;
          }
      return labelValues[i];
      }
  if (pass == 1) return 0xffff;
  *err = 0xff;
  printf("****ERROR: Label not found: %s\n",name);
  errors++;
  return 0;
  }

int addLabel(char* name, word value) {
  int i;
  if (pass == 2) return 0;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0 &&
        strcasecmp(labelProcs[i], module) == 0) {
      printf("****ERROR: Duplicate label: %s\n",name);
      errors++;
      return -1;
      }
  numLabels++;
  if (numLabels == 1) {
    labelNames = (char**)malloc(sizeof(char*));
    labelValues = (word*)malloc(sizeof(word));
    labelProcs = (char**)malloc(sizeof(char*));
    labelLine = (int*)malloc(sizeof(int));
    }
  else {
    labelNames = (char**)realloc(labelNames,sizeof(char*)*numLabels);
    labelValues = (word*)realloc(labelValues,sizeof(word)*numLabels);
    labelProcs = (char**)realloc(labelProcs,sizeof(char*)*numLabels);
    labelLine = (int*)realloc(labelLine,sizeof(int)*numLabels);
    }
  labelNames[numLabels-1] = (char*)malloc(strlen(name)+1);
  labelProcs[numLabels-1] = (char*)malloc(strlen(module)+1);
  strcpy(labelNames[numLabels-1], name);
  strcpy(labelProcs[numLabels-1], module);
  labelValues[numLabels-1] = value;
  labelLine[numLabels-1] = lineCount;
  return 0;
  }

void setLabel(char* name, word value) {
  int i;
  for (i=0; i<numLabels; i++)
    if (strcasecmp(labelNames[i], name) == 0) {
      labelValues[i] = value;
      return;
      }
  numLabels++;
  if (numLabels == 1) {
    labelNames = (char**)malloc(sizeof(char*));
    labelValues = (word*)malloc(sizeof(word));
    labelLine = (int*)malloc(sizeof(int));
    }
  else {
    labelNames = (char**)realloc(labelNames,sizeof(char*)*numLabels);
    labelValues = (word*)realloc(labelValues,sizeof(word)*numLabels);
    labelLine = (int*)realloc(labelLine,sizeof(int)*numLabels);
    }
  labelNames[numLabels-1] = (char*)malloc(strlen(name)+1);
  strcpy(labelNames[numLabels-1], name);
  labelValues[numLabels-1] = value;
  labelLine[numLabels-1] = lineCount;
  }

void addExternal(char* name) {
  int i;
  if (pass == 2) return;
  addLabel(name, 0);
  numExternals++;
  if (numExternals == 1)
    externals = (int*)malloc(sizeof(int));
  else
    externals = (int*)realloc(externals,sizeof(int)*numExternals);
  externals[numExternals-1] = findLabelNumber(name);
  }

void addDefine(char *def, char* value) {
  int i;
  for (i=0; i<numDefines; i++)
    if (strcmp(defines[i], def) == 0) {
      printf("****ERROR: %s is defined more than once\n");
      errors++;
      return;
      }
  numDefines++;
  if (numDefines == 1) {
    defines = (char**)malloc(sizeof(char*));
    defineValues = (char**)malloc(sizeof(char*));
    }
  else {
    defines = (char**)realloc(defines,sizeof(char*)*numDefines);
    defineValues = (char**)realloc(defineValues,sizeof(char*)*numDefines);
    }
  defines[numDefines-1] = (char*)malloc(strlen(def) + 1);
  defineValues[numDefines-1] = (char*)malloc(strlen(value) + 1);
  strcpy(defines[numDefines-1], def);
  strcpy(defineValues[numDefines-1], value);
  }

char* findDefine(char*def) {
  int i;
  for (i=0; i<numDefines; i++)
    if (strcmp(defines[i], def) == 0) {
      return defineValues[i];
      }
  return NULL;
  }

char* evaluate(char* expr, word* ret) {
  int  i;
  word nstack[256];
  int  nsp;
  byte ostack[256];
  int  osp;
  int  flag;
  char err;
  char token[128];
  int  pos;
  char isHex;
  char hexChar;
  word dec;
  word hex;
  word value;
  byte op;
  char ntype;
  *ret = 0;
  evalErrors = 0;
  usedExternal = -1;
  usedLocal = -1;
  extType = 'W';
  osp = 0;
  nsp = 0;
  flag = 0;
  if (*expr == '-') {
    nstack[nsp++] = 0;
    ostack[osp++] = OP_SUB;
    expr++;
    }
  while (flag == 0) {
    hexChar = 'N';
    isHex = 'N';
    ntype = 'W';
    dec = 0;
    hex = 0;
    while (*expr == ' ') expr++;
    while (*expr == '(') {
      ostack[osp++] = OP_OP;
      expr++;
      }
    while (*expr == ' ') expr++;
    if (*expr == '<') {
      ntype = 'L';
      expr++;
      extType = 'L';
      }
    if (*expr == '>') {
      ntype = 'H';
      expr++;
      extType = 'H';
      }
    if (*expr == '$' && 
        ((*(expr+1) >= '0' && *(expr+1) <= '9') ||
         (*(expr+1) >= 'a' && *(expr+1) <= 'f') ||
         (*(expr+1) >= 'A' && *(expr+1) <= 'F')
        )) {
      isHex = 'Y';
      expr++;
      }
    if (strncmp(expr, "[month]", 7) == 0) {
      value = buildMonth;
      expr += 7;
      }
    else if (strncmp(expr, "[day]", 5) == 0) {
      value = buildDay;
      expr += 5;
      }
    else if (strncmp(expr, "[year]", 6) == 0) {
      value = buildYear;
      expr += 6;
      }
    else if (strncmp(expr, "[hour]", 6) == 0) {
      value = buildHour;
      expr += 6;
      }
    else if (strncmp(expr, "[minute]", 8) == 0) {
      value = buildMinute;
      expr += 8;
      }
    else if (strncmp(expr, "[second]", 8) == 0) {
      value = buildSecond;
      expr += 8;
      }
    else if (strncmp(expr, "[build]", 7) == 0) {
      value = buildNumber;
      expr += 7;
      }
    else if (*expr == '$') {
      value = address;
      expr++;
      }
    else if (*expr == '%') {
      expr++;
      isHex = 'N';
      value = 0;
      while (*expr == '0' || *expr == '1' || *expr == '_') {
        if (*expr == '0') value <<= 1;
        if (*expr == '1') value = (value << 1) | 1;
        expr++;
        }
      }
    else if ((*expr >= '0' && *expr <= '9') || isHex == 'Y') {
      while ((*expr >= '0' && *expr <= '9') ||
             (*expr >= 'a' && *expr <= 'f') ||
             (*expr >= 'A' && *expr <= 'F')) {
        if (*expr >= '0' && *expr <= '9') {
          dec = (dec * 10) + (*expr - '0');
          hex = (hex * 16) + (*expr - '0');
          }
        if (*expr >= 'a' && *expr <= 'f') {
          hexChar = 'Y';
          hex = (hex * 16) + (*expr - 87);
          }
        if (*expr >= 'A' && *expr <= 'F') {
          hexChar = 'Y';
          hex = (hex * 16) + (*expr - 55);
          }
        expr++;
        }
      if (*expr == 'h' || *expr == 'H') {
        isHex = 'Y';
        expr++;
        }
      if (isHex == 'Y') {
        value = hex;
        }
      else if (hexChar == 'N') {
        value = dec;
        }
      else {
        printf("****ERROR: Expression error\n");
        *ret = 0;
        evalErrors = 1;
        return expr;
        }
      }
    else if ((*expr >= 'a' && *expr <= 'z') ||
             (*expr >= 'A' && *expr <= 'Z') ||
             *expr == '_') {
      pos = 0;
      while ((*expr >= 'a' && *expr <= 'z') ||
             (*expr >= 'A' && *expr <= 'Z') ||
             (*expr >= '0' && *expr <= '9') ||
             *expr == '_') token[pos++] = *expr++;
      token[pos] = 0;
      value = findLabel(token, &err);
      if (err != 0) evalErrors = 1;
      }
    else if (*expr == '\'') {
      expr++;
      value = *expr++;
      while (*expr != 0 && *expr != '\'') expr++;
      if (*expr == '\'') expr++;
      }
    else {
      evalErrors = 1;
      return expr;
      }
    if (ntype == 'W') nstack[nsp++] = value;
    if (ntype == 'H') nstack[nsp++] = (value >> 8) & 0xff;
    if (ntype == 'L') nstack[nsp++] = value & 0xff;
    while (*expr == ' ' || *expr == '\t') expr++;
    op = OP_CP;
    while (op == OP_CP) {
      if (*expr == 0) op = OP_END;
      else if (*expr == '+') op = OP_ADD;
      else if (*expr == '-') op = OP_SUB;
      else if (*expr == '*') op = OP_MUL;
      else if (*expr == '/') op = OP_DIV;
      else if (*expr == ')') op = OP_CP;
      else if (*expr == '<' && *(expr+1) == '<') { op = OP_SHL; expr++; }
      else if (*expr == '>' && *(expr+1) == '>') { op = OP_SHR; expr++; }
      else if (*expr == '<' && *(expr+1) == '>') { op = OP_NE; expr++; }
      else if (*expr == '<' && *(expr+1) == '=') { op = OP_LE; expr++; }
      else if (*expr == '>' && *(expr+1) == '=') { op = OP_GE; expr++; }
      else if (*expr == '&' && *(expr+1) == '&') { op = OP_LAND; expr++; }
      else if (*expr == '|' && *(expr+1) == '|') { op = OP_LOR; expr++; }
      else if (*expr == '>') op = OP_GT;
      else if (*expr == '<') op = OP_LT;
      else if (*expr == '=') op = OP_EQ;
      else if (*expr == '&') op = OP_AND;
      else if (*expr == '|') op = OP_OR;
      else if (*expr == '^') op = OP_XOR;
      else {
        op = OP_END;
        flag = 0xff;
        }
      if (*expr != 0 && op != OP_END) expr++;
      while (osp > 0 && (ostack[osp-1] & 0xf0) >= (op & 0xf0)) {
        if (ostack[osp-1] == OP_ADD) { nstack[nsp-2] += nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_SUB) { nstack[nsp-2] -= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_MUL) { nstack[nsp-2] *= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_DIV) { nstack[nsp-2] /= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_SHL) { nstack[nsp-2] <<= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_SHR) { nstack[nsp-2] >>= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_AND) { nstack[nsp-2] &= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_OR) { nstack[nsp-2] |= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_XOR) { nstack[nsp-2] ^= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_NE) { nstack[nsp-2] = nstack[nsp-2] != nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_EQ) { nstack[nsp-2] = nstack[nsp-2] == nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_GE) { nstack[nsp-2] = nstack[nsp-2] >= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_LE) { nstack[nsp-2] = nstack[nsp-2] <= nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_GT) { nstack[nsp-2] = nstack[nsp-2] > nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_LT) { nstack[nsp-2] = nstack[nsp-2] < nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_LAND) { nstack[nsp-2] = nstack[nsp-2] && nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_LOR) { nstack[nsp-2] = nstack[nsp-2] || nstack[nsp-1]; nsp--; osp--; }
        else if (ostack[osp-1] == OP_OP) {
          osp--;
          op = OP_STOP;
          }
        }
      if (op == OP_STOP) op = OP_CP;
      while (*expr == ' ' || *expr == '\t') expr++;
      }
    ostack[osp++] = op;
    if (*expr == 0) flag = 0xff;
    }
  if (nsp != 1) {
    printf("****ERROR: Expression did not reduce to single term\n");
    evalErrors = 1;
    }
  *ret = nstack[0];
  return expr;
  }

char upcase(char in) {
  if (in >= 'a' && in <= 'z') in -= 32;
  return in;
  }

int match(char* pattern, char* input) {
  int i;
  word value;
  char *temp;
  while (*pattern == ' ' || *pattern == '\t') pattern++;
  while (*input == ' ' || *input == '\t') input++;
  while (*pattern != 0) {
    while (*pattern == ' ' || *pattern == '\t') pattern++;
    while (*input == ' ' || *input == '\t') input++;
    if (strncasecmp(pattern,"{B}",3) == 0) {
      temp = evaluate(input, &value);
      if (evalErrors != 0) return 0;
      if (value >= 256) return 0;
      args[argCount++] = value;
      input = temp;
      pattern += 3;
      }
    else if (strncasecmp(pattern,"{W}",3) == 0) {
      temp = evaluate(input, &value);
      if (evalErrors != 0) return 0;
      args[argCount++] = value;
      input = temp;
      pattern += 3;
      }
    else if (strncasecmp(pattern, "{Q}", 3) == 0) {
      temp = get32(input);
      if (evalErrors != 0) return 0;
      input = temp;
      pattern += 3;
      }
    else if (strncasecmp(pattern,"{I}",3) == 0) {
      indexNumber = 0xffff;
      for (i=0; i<numIndexes; i++)
        if (match(indexes[i], input) != 0) {
          indexNumber = i;
          return -1;
          }
      if (indexNumber == 0xffff) return 0;
      while (*pattern != 0) pattern++;
      while (*input != 0) input++;
      }
    else if (strncasecmp(pattern,"{5}",3) == 0) {
      temp = evaluate(input, &value);
      if (evalErrors != 0) return 0;
      if (value == 0x10) return 0;
      if ((value & 0xffe0) != 0xffe0 &&
          (value & 0xffe0) != 0x0000) return 0;
      args[argCount++] = value;
      input = temp;
      pattern += 3;
      }
    else if (strncasecmp(pattern,"{IR}",4) == 0) {
      while (*input == ' ' || *input == '\t') input++;
      if (*input == 'x' || *input == 'X') {
        args[argCount++] = 0x01;
        input++;
        pattern += 4;
        }
      else if (*input == 'y' || *input == 'Y') {
        args[argCount++] = 0x02;
        input++;
        pattern += 4;
        }
      else if (*input == 'u' || *input == 'U') {
        args[argCount++] = 0x03;
        input++;
        pattern += 4;
        }
      else if (*input == 's' || *input == 'S') {
        args[argCount++] = 0x04;
        input++;
        pattern += 4;
        }
      else if (*input == 'd' || *input == 'D') {
        args[argCount++] = 0x00;
        input++;
        pattern += 4;
        }
      else return 0;
      }
    else if (strncasecmp(pattern,"{RP}",4) == 0) {
      args[argCount++] = 0;
      while (*input == ' ' || *input == '\t') input++;
      if (*input == 'a' || *input == 'A') {
        args[argCount-1] |= 0x80;
        input++;
        }
      else if (*input == 'b' || *input == 'B') {
        args[argCount-1] |= 0x90;
        input++;
        }
      else if (*input == 'x' || *input == 'X') {
        args[argCount-1] |= 0x10;
        input++;
        }
      else if (*input == 'y' || *input == 'Y') {
        args[argCount-1] |= 0x20;
        input++;
        }
      else if (*input == 'u' || *input == 'U') {
        args[argCount-1] |= 0x30;
        input++;
        }
      else if (*input == 's' || *input == 'S') {
        args[argCount-1] |= 0x40;
        input++;
        }
      else if (*input == 'd' || *input == 'D') {
        args[argCount-1] |= 0x00;
        input++;
        }
      else if (strncasecmp(input, "cc",2) == 0) {
        args[argCount-1] |= 0xa0;
        input += 2;
        }
      else if (strncasecmp(input, "dp",2) == 0) {
        args[argCount-1] |= 0xb0;
        input += 2;
        }
      else if (strncasecmp(input, "pc",2) == 0) {
        args[argCount-1] |= 0x50;
        input += 2;
        }
      else return 0;
      while (*input == ' ' || *input == '\t') input++;
      if (*input != ',') return 0;
      input++;
      while (*input == ' ' || *input == '\t') input++;
      if (*input == 'a' || *input == 'A') {
        args[argCount-1] |= 0x08;
        input++;
        }
      else if (*input == 'b' || *input == 'B') {
        args[argCount-1] |= 0x09;
        input++;
        }
      else if (*input == 'x' || *input == 'X') {
        args[argCount-1] |= 0x01;
        input++;
        }
      else if (*input == 'y' || *input == 'Y') {
        args[argCount-1] |= 0x02;
        input++;
        }
      else if (*input == 'u' || *input == 'U') {
        args[argCount-1] |= 0x03;
        input++;
        }
      else if (*input == 's' || *input == 'S') {
        args[argCount-1] |= 0x04;
        input++;
        }
      else if (strncasecmp(input, "dp",2) == 0) {
        args[argCount-1] |= 0x0b;
        input += 2;
        }
      else if (*input == 'd' || *input == 'D') {
        args[argCount-1] |= 0x00;
        input++;
        }
      else if (strncasecmp(input, "cc",2) == 0) {
        args[argCount-1] |= 0x0a;
        input += 2;
        }
      else if (strncasecmp(input, "pc",2) == 0) {
        args[argCount-1] |= 0x05;
        input += 2;
        }
      else return 0;
      while (*input == ' ' || *input == '\t') input++;
      if (*input != 0) return 0;
      return -1;
      }
    else if (strncasecmp(pattern,"{RL}",4) == 0) {
      args[argCount++] = 0;
      while (*input != 0) {
        while (*input == ' ' || *input == '\t') input++;
        if (*input == 'a' || *input == 'A') {
          args[argCount-1] |= 0x02;
          input++;
          }
        else if (*input == 'b' || *input == 'B') {
          args[argCount-1] |= 0x04;
          input++;
          }
        else if (*input == 'x' || *input == 'X') {
          args[argCount-1] |= 0x10;
          input++;
          }
        else if (*input == 'y' || *input == 'Y') {
          args[argCount-1] |= 0x20;
          input++;
          }
        else if (*input == 's' || *input == 'S') {
          args[argCount-1] |= 0x40;
          input++;
          }
        else if (*input == 'u' || *input == 'U') {
          args[argCount-1] |= 0x40;
          input++;
          }
        else if (strncasecmp(input, "cc",2) == 0) {
          args[argCount-1] |= 0x01;
          input+=2;
          }
        else if (strncasecmp(input, "dp",2) == 0) {
          args[argCount-1] |= 0x08;
          input+=2;
          }
        else if (strncasecmp(input, "pc",2) == 0) {
          args[argCount-1] |= 0x80;
          input+=2;
          }
        else return 0;
        while (*input == ' ' || *input == '\t') input++;
        if (*input != 0 && *input != ',') return 0;
        if (*input == ',') {
          input++;
          }
        }
      return -1;
      }
    else {
      if (upcase(*pattern) != upcase(*input)) return 0;
      pattern++;
      input++;
      if (*pattern == ' ' && *input != ' ' && *input != '\t') return 0;
      }
    }
// printf("Possible match\n");
  while (*input == ' ' || *input == '\t') input++;
  if (*input == 0 || *input == ';') return -1;
// printf("Not Matched!!!\n");
  return 0;
  }

int lookupInstruction(char* input) {
  int i;
  usedExternal = -1;
  for (i=0; i<numOpcodes; i++) {
    argCount = 0;
    if (match(opcodes[i], input) != 0) return i;
    }
  return -1;
  }

void translateInstruction(char* trans) {
  int valid;
  byte b;
  word a;
  valid = 0;
  b = 0;
  while (*trans != 0) {
    if (strncasecmp(trans, "[L]", 3) == 0) {
      if (valid) output(b);
      if (usedExternal >= 0 && pass == 2) {
        if (pass == 2) fprintf(outFile,"\\%s %04x\n",labelNames[externals[usedExternal]],address);
        }
      output(args[argNumber] & 0xff);
      valid = 0;
      b = 0;
      trans += 3;
      }
    else if (strncasecmp(trans, "[H]", 3) == 0) {
      if (valid) output(b);
      if (usedExternal >= 0 && pass == 2) {
        if (pass == 2) fprintf(outFile,"/%s %04x %02x\n",labelNames[externals[usedExternal]],address,args[argNumber] & 0xff);
        }
      output(args[argNumber] >> 8);
      valid = 0;
      b = 0;
      trans += 3;
      }
    else if (strncasecmp(trans, "[Q]", 3) == 0) {
      if (valid) output(b);
      output(args[argNumber] >> 8);
      output(args[argNumber] & 0xff);
      output(args[argNumber+1] >> 8);
      output(args[argNumber+1] & 0xff);
      valid = 0;
      trans += 3;
      }
    else if (strncasecmp(trans, "[BT]", 4) == 0) {
      b |= ((args[argNumber] & 0x7) << 3) | (args[argNumber+1] & 0x7);
      valid = -1;
      trans += 4;
      }
    else if (strncasecmp(trans, "[TF]", 4) == 0) {
      if (valid) output(b);
      b |= (args[argNumber] << 4) | args[argNumber+1];
      valid = -1;
      trans += 4;
      }
    else if (strncasecmp(trans, "[DW]", 4) == 0) {
      if (valid) output(b);
      if (usedExternal >= 0 && pass == 2) {
        fprintf(outFile,"?%s %04x\n",labelNames[externals[usedExternal]],address);
        printf("???WARNING: Using relative addresses as EXTRN will likely not produce the expected result\n");
        }
      a = args[argNumber] - (address+2);
      output(a >> 8);
      output(a & 0xff);
      valid = 0;
      b = 0;
      trans += 4;
      }
    else if (strncasecmp(trans, "[D]", 3) == 0) {
      if (valid) output(b);
      if (usedExternal >= 0 && pass == 2) {
        fprintf(outFile,"\\%s %04x\n",labelNames[externals[usedExternal]],address);
        printf("???WARNING: Using relative addresses as EXTRN will likely not produce the expected result\n");
        }
      a = args[argNumber] - (address+1);
      output(a & 0xff);
      valid = 0;
      b = 0;
      trans += 3;
      }
    else if (strncasecmp(trans, "[W]", 3) == 0) {
      if (valid) output(b);
      if (usedExternal >= 0 && pass == 2) {
        if (pass == 2) fprintf(outFile,"?%s %04x\n",labelNames[externals[usedExternal]],address);
        }
      if (usedLocal >= 0 && pass == 2) {
        fixups[numFixups] = address;
        fixupTypes[numFixups] = 'W';
        fixupLowOffset[numFixups] = 0;
        numFixups++;
        }
      output(args[argNumber] >> 8);
      output(args[argNumber] & 0xff);
      valid = 0;
      b = 0;
      trans += 3;
      }
    else if (strncasecmp(trans, "[I]", 3) == 0) {
      if (valid) output(b);
      translateInstruction(indexTranslations[indexNumber]);
      valid = 0;
      b = 0;
      trans += 3;
      }
    else if (strncasecmp(trans, "[5]", 3) == 0) {
      if (valid) b <<= 4;
      b |= (args[argNumber] & 0x1f);
      output(b);
      valid = 0;
      b = 0;
      trans += 3;
      }
    else if (*trans >= '0' && *trans <= '9') {
      b = (b << 4) | (*trans - '0');
      valid = -1;
      trans++;
      }
    else if (*trans >= 'a' && *trans <= 'f') {
      b = (b << 4) | (*trans - 87);
      valid = -1;
      trans++;
      }
    else if (*trans >= 'A' && *trans <= 'F') {
      b = (b << 4) | (*trans - 55);
      valid = -1;
      trans++;
      }
    else if (*trans == '+') {
      if (valid) output(b);
      b = 0;
      valid = 0;
      argNumber++;
      trans++;
      }
    else if (*trans == ' ') {
      if (valid) output(b);
      b = 0;
      valid = 0;
      trans++;
      }
    }
  if (valid) output(b);
  }

void defReplace(char* line) {
  char  buffer[1024];
  char *pchar;
  int i;
  for (i=0; i<numDefines; i++) {
    while ((pchar = strstr(line, defines[i])) != NULL) {
      strncpy(buffer,line,pchar-line);
      buffer[pchar-line] = 0;
      strcat(buffer,defineValues[i]);
      strcat(buffer,pchar+strlen(defines[i]));
      strcpy(line,buffer);
      }
    }
  }

char* nextLine(char* line) {
  int   i;
  char* ret;
  int   flag;
  char  buffer[1024];
  int   pos;
  char *pchar;
  word  value;
  flag = -1;
  while (flag) {
    ret = fgets(line, 1024, sourceFile[fileNumber]);
    lineCount++;
    lineNumber[fileNumber]++;
    if (ret != NULL) {
      while (strlen(ret) > 0 && line[strlen(ret)-1] <= ' ')
        line[strlen(ret)-1] = 0;
      flag = 0;
      if (*ret == '#') {
        if (fileNumber == 0)
          sprintf(listLine,"[%05d] ",lineNumber[fileNumber]);
        else
          sprintf(listLine,"<%05d> ",lineNumber[fileNumber]);
        while (strlen(listLine) < 25) strcat(listLine," ");
        strcat(listLine,"  ");
        strcat(listLine,ret);
        if (pass == 2) {
          if (showList != 0) printf("%s\n",listLine);
          if (createListFile != 0) fprintf(listFile,"%s\n",listLine);
          }
        flag = -1;
        if (strncmp(ret,"#include ",9) == 0) {
          ret += 9;
          while (*ret == ' ' || *ret == '\t') ret++;
          pos = 0;
          while (*ret != 0 && *ret > ' ')
            buffer[pos++] = *ret++;
          buffer[pos] = 0;
          fileNumber++;
          lineNumber[fileNumber] = 0;
          sourceFile[fileNumber] = fopen(buffer,"r");
          if (sourceFile[fileNumber] == NULL) {
            }
          }
        if (strncmp(ret,"#define ",8) == 0) {
          ret += 8;
          while (*ret == ' ' || *ret == '\t') ret++;
          pos = 0;
          while (*ret != 0 && *ret > ' ')
            buffer[pos++] = *ret++;
          buffer[pos] = 0;
          while (*ret == ' ' || *ret == '\t') ret++;
          if (*ret == 0) addDefine(buffer,"1");
            else addDefine(buffer, ret);
          }
        if (strncmp(ret,"#ifdef ",7) == 0) {
          ret += 7;
          while (*ret == ' ' || *ret == '\t') ret++;
          pos = 0;
          while (*ret != 0 && *ret > ' ')
            buffer[pos++] = *ret++;
          buffer[pos] = 0;
          pchar = findDefine(buffer);
          if (pchar != NULL) {
            numNests++;
            nests[numNests] = 'Y';
            }
          else {
            numNests++;
            nests[numNests] = 'N';
            }
          }
        if (strncmp(ret,"#ifndef ",8) == 0) {
          ret += 8;
          while (*ret == ' ' || *ret == '\t') ret++;
          pos = 0;
          while (*ret != 0 && *ret > ' ')
            buffer[pos++] = *ret++;
          buffer[pos] = 0;
          pchar = findDefine(buffer);
          if (pchar != NULL) {
            numNests++;
            nests[numNests] = 'N';
            }
          else {
            numNests++;
            nests[numNests] = 'Y';
            }
          }
        if (strncmp(ret,"#if ",4) == 0) {
          ret += 4;
          while (*ret == ' ' || *ret == '\t') ret++;
          defReplace(ret);
          evaluate(ret, &value);
          if (value != 0) {
            numNests++;
            nests[numNests] = 'Y';
            }
          else {
            numNests++;
            nests[numNests] = 'N';
            }
          }
        if (strncmp(ret,"#endif",6) == 0) {
          if (numNests > 0) numNests--;
          else {
            printf("Error: Unmatched #endif\n");
            errors++;
            }
          }
        if (strncmp(ret,"#else",5) == 0) {
          if (numNests > 0)
            nests[numNests] = (nests[numNests] == 'Y') ? 'N' : 'Y';
          else {
            printf("Error: Unmatched #else\n");
            errors++;
            }
          }
        }
      else if (nests[numNests] != 'Y') {
        flag = -1;
        }
      else {
        defReplace(ret);
        }
      }
    else {
      if (fileNumber == 0) flag = 0;
      else {
        fclose(sourceFile[fileNumber]);
        fileNumber--;
        flag = -1;
        }
      }
    }
  return ret;
  }

int assemblyPass(char* sourceName) {
  int  o;
  int  i;
  word value;
  char *pchar;
  char *pline;
  char  err;
  FTOI ftoi;
  char line[1024];
  sourceFile[0] = fopen(sourceName, "r");
  if (sourceFile[0] == NULL) {
    printf("Error: Could not open: %s\n",sourceName);
    return -1;
    }
  lineNumber[0] = 0;
  fileNumber = 0;
  lineCount = 0;
  address = 0;
  outCount = 0;
  outAddress = 0;
  codeGenerated = 0;
  numDefines = 0;
  nests[0] = 'Y';
  numNests = 0;
  strcpy(module,"*");
  inProc = 0;
  while (nextLine(line)) {
    strcpy(sourceLine, line);
    if (strncmp(line,".6309",5) == 0) {
      use6309 = -1;
      init6309Opcodes();
      }
    if (strncmp(line,".list",5) == 0) showList = -1;
    if (strncmp(line,".sym",4) == 0) showSymbols = -1;
    if (strncmp(line,".link ",6) == 0) {
      if (pass == 2) {
        fprintf(outFile,"%s\n",line+6);
        }
      }
    if (strncmp(line,".sym",4) == 0) showSymbols = -1;
    if (strncmp(line,".align word", 11) == 0) {
      if (outCount != 0) writeOutput();
      address = (address + 1) & 0xfffe;
      outAddress = address;
      }
    if (strncmp(line,".align dword", 12) == 0) {
      if (outCount != 0) writeOutput();
      address = (address + 3) & 0xfffc;
      outAddress = address;
      }
    if (strncmp(line,".align qword", 12) == 0) {
      if (outCount != 0) writeOutput();
      address = (address + 7) & 0xfff8;
      outAddress = address;
      }
    if (strncmp(line,".align para", 11) == 0) {
      if (outCount != 0) writeOutput();
      address = (address + 15) & 0xfff0;
      outAddress = address;
      }
    if (strncmp(line,".align 32", 9) == 0) {
      if (outCount != 0) writeOutput();
      address = (address + 31) & 0xffe0;
      outAddress = address;
      }
    if (strncmp(line,".align 64", 9) == 0) {
      if (outCount != 0) writeOutput();
      address = (address + 63) & 0xffc0;
      outAddress = address;
      }
    if (strncmp(line,".align 128", 10) == 0) {
      if (outCount != 0) writeOutput();
      address = (address + 127) & 0xff80;
      outAddress = address;
      }
    if (strncmp(line,".align page", 11) == 0) {
      if (outCount != 0) writeOutput();
      address = (address + 255) & 0xff00;
      outAddress = address;
      }
    if (line[0] == '.') strcpy(line,"");
    pchar = strchr(line, ';');
    if (pchar != NULL) {
      *pchar = 0;
      while (strlen(line) > 0 && line[strlen(line)-1] <= ' ')
        line[strlen(line)-1] = 0;
      }
    pline = line;
    if (*pline != 0 && *pline != ' ' && *pline != '\t') {
      i = 0;
      while (*pline != ' ' && *pline != '\t' && *pline != ':' && *pline != 0)
        label[i++] = *pline++;
      label[i] = 0;
      }
    else strcpy(label, "");
    if (*pline == ':') pline++;
    while (*pline != 0 && *pline <= ' ') pline++;
    if (strlen(label) > 0 || strlen(pline) > 0) {
      if (fileNumber == 0)
        sprintf(listLine,"[%05d] %04x:",lineNumber[fileNumber],address);
      else
        sprintf(listLine,"<%05d> %04x:",lineNumber[fileNumber],address);
      if (strlen(label) > 0) addLabel(label, address);

      instructionBytes = 0;
      if (strlen(pline) > 0) {
        if (strncasecmp(pline,"org",3) == 0) {
          if (outCount != 0) writeOutput();
          pline = nextWord(pline);
          evaluate(pline, &address);
          outAddress = address;
          }
        else if (strncasecmp(pline,"extrn",5) == 0) {
          pline = nextWord(pline);
          addExternal(pline);
          }
        else if (strncasecmp(pline,"proc",4) == 0) {
          if (inProc) {
            printf("***Error: PROC encountered inside of another PROC %s\n",pline);
            errors++;
            }
          else {
            pline = nextWord(pline);
            if (outCount != 0) writeOutput();
            address = 0;
            outAddress = 0;
            inProc = -1;
            strcpy(module, pline);
            if (pass == 1) addLabel(pline, 0);
            if (pass == 2) {
              fprintf(outFile,"{%s\n",pline);
              }
            numFixups = 0;
            }
          }
        else if (strcasecmp(pline,"endp") == 0) {
          if (inProc == 0) {
            printf("***ERROR: ENDP encountered outside PROC\n");
            errors++;
            }
          inProc = 0;
          if (outCount != 0) writeOutput();
          if (pass == 2) {
            for (i=0; i<numFixups; i++) {
              if (fixupTypes[i] == 'W')
                fprintf(outFile,"+%04x\n",fixups[i]);
              if (fixupTypes[i] == 'H') {
                if (fixupLowOffset[i] != 0)
                  fprintf(outFile,"^%04x %02x\n",fixups[i],fixupLowOffset[i]);
                else
                  fprintf(outFile,"^%04x\n",fixups[i]);
                }
              if (fixupTypes[i] == 'L')
                fprintf(outFile,"v%04x\n",fixups[i]);
              }
            fprintf(outFile,"}\n");
            }
          }
        else if (strncasecmp(pline,"public",6) == 0) {
          if (pass == 2) {
            pline = nextWord(pline);
            i = findLabelNumber(pline);
            if (i < 0) {
              printf("****ERROR: Symbol not found: %s\n",pline);
              errors++;
              }
            else {
              numPublics++;
              if (numPublics == 1)
                publics = (int*)malloc(sizeof(int));
              else
                publics = (int*)realloc(publics,sizeof(int)*numPublics);
              publics[numPublics-1] = i;
              }
            }
          }
        else if (strncasecmp(pline,"ds",2) == 0) {
          if (outCount != 0) writeOutput();
          pline = nextWord(pline);
          evaluate(pline, &value);
          address += value;
          outAddress = address;
          }
        else if (strncasecmp(pline,"db",2) == 0 ||
                 strncasecmp(pline,".byte",5) == 0 ||
                 strncasecmp(pline,"byte",4) == 0) {
          pline = nextWord(pline);
          pchar = pline;
          while (*pchar != 0) {
            if (*pchar == '"') {
              pchar++;
              while (*pchar != 0 && *pchar != '"') {
                output(*pchar);
                pchar++;
                }
              if (*pchar == '"') pchar++;
              }
            else {
              pchar = evaluate(pchar, &value);
              output(value & 0xff);
              }
            while (*pchar == ' ') pchar++;
            if (*pchar == ',') pchar++;
            while (*pchar == ' ') pchar++;
            }
          }
        else if (strncasecmp(pline,"dw",2) == 0 ||
                 strncasecmp(pline,"word",4) == 0 ||
                 strncasecmp(pline,".word",5) == 0) {
          pline = nextWord(pline);
          pchar = pline;
          while (*pchar != 0) {
            pchar = evaluate(pchar, &value);
            output((value >> 8) & 0xff);
            output(value & 0xff);
            while (*pchar == ' ') pchar++;
            if (*pchar == ',') pchar++;
            while (*pchar == ' ') pchar++;
            }
          }
        else if (strncasecmp(pline,"df",2) == 0) {
          pline = nextWord(pline);
          ftoi.f = atof(pline);
          output((ftoi.i >> 24) & 0xff);
          output((ftoi.i >> 16) & 0xff);
          output((ftoi.i >> 8) & 0xff);
          output(ftoi.i & 0xff);
          }
        else if (strncasecmp(pline,"end",3) == 0) {
          if (outCount != 0) writeOutput();
          pline = nextWord(pline);
          evaluate(pline, &startAddress);
          }
        else if (strncasecmp(pline,"equ",3) == 0 ||
                 strncasecmp(pline,".equ",4) == 0) {
          pline = nextWord(pline);
          evaluate(pline, &value);
          if (strlen(label) > 0) setLabel(label, value);
          }
        else {
          indexNumber = 0xffff;
          o = lookupInstruction(pline);
          if (o >= 0) {
// printf("-->%s\n",opcodes[o]);
// if (indexNumber != 0xffff) printf("   %s\n",indexes[indexNumber]);
            argNumber = 0;
            translateInstruction(translations[o]);
            }
          else {
            printf("****ERROR: Invalid instruction\n");
            printf("   [%05d] %s\n",lineCount,sourceLine);
            errors++;
            }
          }
        }
      if (instructionBytes < 4) {
        while (strlen(listLine) < 25) strcat(listLine," ");
        strcat(listLine,"  ");
        strcat(listLine,sourceLine);
        }
      if (instructionBytes < 4 || ((instructionBytes % 4) != 0) && instructionBytes != 4)
        if (pass == 2) {
          if (showList != 0) printf("%s\n",listLine);
          if (createListFile != 0) fprintf(listFile,"%s\n",listLine);
          }
      }
    else {
      if (fileNumber == 0)
        sprintf(listLine,"[%05d] ",lineNumber[fileNumber]);
      else
        sprintf(listLine,"<%05d> ",lineNumber[fileNumber]);
      while (strlen(listLine) < 27) strcat(listLine," ");
      strcat(listLine, sourceLine);
      if (pass == 2) {
        if (showList != 0) printf("%s\n",listLine);
        if (createListFile != 0) fprintf(listFile,"%s\n",listLine);
        }
      }
    }
  while (fileNumber > 0) {
    fclose(sourceFile[fileNumber--]);
    }
  fclose(sourceFile[0]);
  for (i=0; i<numDefines; i++) {
    free(defines[i]);
    free(defineValues[i]);
    }
  if (numDefines > 0) {
    free(defines);
    free(defineValues);
    }
  return errors;
  }

void assembleFile(char* sourceName) {
  int   i;
  char *pchar;
  char buffer[1024];
  char tmp[1024];
  FILE *buildFile;
  strcpy(baseName, sourceName);
  pchar = strchr(baseName,'.');
  if (pchar != NULL) *pchar = 0;
  strcpy(listName, baseName);
  strcat(listName, ".lst");
  strcpy(outName, baseName);
  strcat(outName, ".prg");

  printf("Source file: %s\n",sourceName);
  errors = 0;
  numLabels = 0;
  numExternals = 0;
  numReferences = 0;
  numPublics = 0;
  startAddress = 0xffff;

  strcpy(tmp, baseName);
  strcat(tmp,".build");
  buildFile = fopen(tmp, "r");
  if (buildFile == NULL) {
    buildNumber = 1;
    }
  else {
    fgets(buffer, 32, buildFile);
    buildNumber = atoi(buffer) + 1;
    fclose(buildFile);
    }
  buildFile = fopen(tmp,"w");
  fprintf(buildFile,"%d\n",buildNumber);
  fclose(buildFile);

  pass = 1;
  if (assemblyPass(sourceName) != 0) {
    printf("Errors encountered. Assembly aborted\n");
    }
  else {
    pass = 2;
    outFile = fopen(outName, "w");
    fprintf(outFile,".big\n");
    if (createListFile != 0) listFile = fopen(listName, "w");
    assemblyPass(sourceName);
    if (outBytes > 0) writeOutput();
    if (startAddress != 0xffff)
      fprintf(outFile,"@%04x\n",startAddress);
    if (numReferences > 0) {
      for (i=0; i<numReferences; i++) {
        fprintf(outFile,"?%s %04x\n",externals[references[i]],referenceAddress[i]);
        }
      }
    if (numPublics > 0) {
      for (i=0; i<numPublics; i++) {
        fprintf(outFile,"=%s %04x\n",labelNames[publics[i]],labelValues[publics[i]]);
        }
      }
    fclose(outFile);
    if (showSymbols != 0) {
      printf("\n");
      if (createListFile) fprintf(listFile,"\n");
      for (i=0; i<numLabels; i++) {
        sprintf(buffer,"%-16s %-16s %04x <%05d> \n",labelNames[i],labelProcs[i],labelValues[i],labelLine[i]);
        printf("%s",buffer);
        if (createListFile) fprintf(listFile,"%s",buffer);
        }
      printf("\n");
      if (createListFile) fprintf(listFile,"\n");
      }
    }
  printf("Lines assembled: %d\n",lineCount);
  printf("Errors         : %d\n",errors);
  printf("Code generated : %d\n",codeGenerated);
  if (createListFile != 0 && pass == 2) {
    fprintf(listFile,"Lines assembled: %d\n",lineCount);
    fprintf(listFile,"Errors         : %d\n",errors);
    fprintf(listFile,"Code generated : %d\n",codeGenerated);
    }
  if (createListFile != 0 && pass == 2) fclose(listFile);
  printf("\n");
  for (i=0; i<numLabels; i++) {
    free(labelNames[i]);
    }
  if (numExternals > 0) free(externals);
  if (numPublics > 0) free(publics);
  if (numReferences > 0) {
    free(references);
    free(referenceAddress);
    }
  if (numLabels > 0) {
    free(labelNames);
    free(labelValues);
    free(labelLine);
    }
  }

int main(int argc, char **argv) {
  int i;
  time_t tv;
  struct tm dt;
  printf("Asm/09 1.0 by Michael H. Riley\n\n");
  initOpcodes();
  initIndexes();
  showList = 0;
  showSymbols = 0;
  createListFile = 0;
  numSourceFiles = 0;
  use6309 = 0;
  loaded6309 = 0;
  tv = time(NULL);
  localtime_r(&tv, &dt);
  buildMonth = dt.tm_mon + 1;
  buildDay = dt.tm_mday;
  buildYear = dt.tm_year + 1900;
  buildHour = dt.tm_hour;
  buildMinute = dt.tm_min;
  buildSecond = dt.tm_sec;
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i],"-l") == 0) showList = -1;
    else if (strcmp(argv[i],"-L") == 0) createListFile = -1;
    else if (strcmp(argv[i],"-s") == 0) showSymbols = -1;
    else if (strcmp(argv[i],"-6309") == 0) use6309 = -1;
    else {
      numSourceFiles++;
      if (numSourceFiles == 1)
        sourceNames = (char**)malloc(sizeof(char*));
      else
        sourceNames = (char**)realloc(sourceNames,sizeof(char*) * numSourceFiles);
      sourceNames[numSourceFiles-1] = (char*)malloc(strlen(argv[i])+1);
      strcpy(sourceNames[numSourceFiles-1], argv[i]);
      }
    }
  if (numSourceFiles == 0) {
    printf("No source file specified\n");
    exit(1);
    }
  if (use6309) init6309Opcodes();
  for (i=0; i<numSourceFiles; i++)
    assembleFile(sourceNames[i]);
  return 0;
  }

