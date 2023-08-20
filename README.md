# pes_asic_class
## Introduction:

RISC-V ISA(Instruction Set Architecture) is an assembly language through which we communication with the system using binary notations.

## Course Description:

1. RISC-V ISA
2. RTL & Synthesis of RISC-V based CPU core-picorv32
3. Physical design implementation of picorv32

## Flow:

C Program -> comipiled into assembly language -> Machine Language -> Execution/Implementing in hardware

## System software consists of:

1) Operating system: consists of HLL(High Level Language) like C,C++
2) Compiler: it consists of instruction sets which compiles the HLL into Assembly language.
3) Assembler: it takes the help of HDLs(Hardware Description Language) to convert it to binary form. 

## Contents of this course:
1. Pseudo instructions
2. Base integer instructions RV64I
3. Multiply extension RV64M
4. Single & Double precision floating point extension RV64F & RV64D
5. Application Binary Interface(ABI)
6. Memory Allocation & Stack Pointer

## DAY1

Write a C program to calculate sum of numbers from 1 to n.

Compiling using C

![lab1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/dc061fd3-aa77-43b7-a895-ec8ad269d913)


![sumncode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/da0e7ecf-0612-4790-b80f-cfb5616e346a)

Compile using RISC-V simulator

![lab2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a172e2a2-2405-456f-8f67-1b23f2a474c2)


![O1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/df255613-656e-4fbe-81cf-921391344ed1)


![Ofast](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/d2996d6d-c839-433d-af08-252c7ecc510f)


![Ofast2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/ad7c893e-684a-4c38-83a6-3d23e7f02da3)


Spike simulation

![spike](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/69bcb558-0c87-40a6-b072-8c6d00585288)

Debugging using Spike

![debug](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/4a2d1c24-3c99-4417-95f5-e697ee1fa4fb)


![debug2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/82dcd3ce-d026-40ac-bb54-fc85917bd691)
