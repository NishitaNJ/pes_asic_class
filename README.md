# pes_asic_class
### Introduction:

RISC-V ISA(Instruction Set Architecture) is an assembly language through which we communication with the system using binary notations.

### Course Description:

1. RISC-V ISA
2. RTL & Synthesis of RISC-V based CPU core-picorv32
3. Physical design implementation of picorv32

#### Flow:

C Program -> comipiled into assembly language -> Machine Language -> Execution/Implementing in hardware

#### System software consists of:
1) Operating system: consists of HLL(High Level Language) like C,C++
2) Compiler: it consists of instruction sets which compiles the HLL into Assembly language.
3) Assembler: it takes the help of HDLs(Hardware Description Language) to convert it to binary form. 


#### Contents of this course:
  1. Pseudo instructions
  2. Base integer instructions RV64I
  3. Multiply extension RV64M
  4. Single & Double precision floating point extension RV64F & RV64D
  5. Application Binary Interface(ABI)
  6. Memory Allocation & Stack Pointer

<details>

<summary>DAY1</summary>

Write a C program to calculate sum of numbers from 1 to n.

* **Compiling using C**

![lab1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/dc061fd3-aa77-43b7-a895-ec8ad269d913)

leafpad - It is a simple open source text editor fot Linux similar to Notepad in Windows

![sumncode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/da0e7ecf-0612-4790-b80f-cfb5616e346a)


* **Compile using RISC-V simulator**

`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sumn.o sumn.c`  
  -O1 : This is an optimization flag that tells the compiler to optimize the generated code for performance. -O1 flag is a moderate level of optimization. 

![lab2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a172e2a2-2405-456f-8f67-1b23f2a474c2)

* **Optimization results when used -O1 optimization flag:**
![O1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/df255613-656e-4fbe-81cf-921391344ed1)

`riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sumn.o sumn.c`

  -Ofast : This is an optimization flag that specifies aggressive optimization settings for the generated code.
    
![Ofast](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/d2996d6d-c839-433d-af08-252c7ecc510f)

* **Optimization results when used -Ofast optimization flag:**
![Ofast2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/ad7c893e-684a-4c38-83a6-3d23e7f02da3)


* **Spike simulation**

  *Spike is a RISC-V ISA (Instruction Set Architecture) simulator designed to simulate RISC-V processors at various privilege levels. It's often used for development, debugging, and testing of RISC-V software without requiring actual hardware.*

`spike pk sumn.o`

-> spike: This command is used to invoke the spike simulator.

  -> pk: The proxy kernel is a small, simple kernel that serves as an interface between user level software and the simulator.

![spike](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/69bcb558-0c87-40a6-b072-8c6d00585288)

* **Debugging using Spike**

 *Debugging using Spike involves using the Spike simulator, along with GDB(GNU Debugger), to analyze and troubleshoot issues in RISC-V software*

 `spike -d pk sumn.o`
 
  -> -d : This flag enables the debug mode in Spike.
![debug](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/4a2d1c24-3c99-4417-95f5-e697ee1fa4fb)


![debug2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/82dcd3ce-d026-40ac-bb54-fc85917bd691)

</details>





![highestunsign](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8d1aee5d-24fe-4d5e-8d05-b1f7d07697af)

![unsigncode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/2ec49af7-268a-46b2-9cd1-fabca10b5afc)
![high64code](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a4a0718f-57e0-4d8f-9960-30452289746b)

![high64](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/36224727-516a-45df-92fc-911f6861aa2c)

![negcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/6a59bcfa-9662-43f8-a3dc-d3a7cd0c9122)

![checkcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/2d4bf0bb-7da8-4a4e-9a11-b528652fcfa9)

![check](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9944d42f-4fc2-48b9-8ee3-6faef3939b86)

![low64code](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a499670c-2651-486e-bac2-2d290694ec35)

![low64](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/bd771093-a521-4b48-bcc2-98e7fdf0af7c)

![correctsign](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/e36d8e8a-5351-485b-a3c3-c8faddaef8e0)

![correctcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/f2782b40-cfd3-4659-850f-af0c91b6287f)
![signed](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/16c3445e-c0e5-462d-af9e-736e60555415)

![signedcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/4871e00a-533d-4e49-b24c-bb7c06ac876d)



![neg](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9a301dca-2686-4465-bbc3-abf877b5f80d)










