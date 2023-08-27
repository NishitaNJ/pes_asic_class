<details>
  <summary> VLSI Physical Design for ASICs </summary>
 
## Objective
This GitHub repository focuses on VLSI Physical Design for ASICs using open-source tools. The main objective is to convert a logical design description (RTL - Register Transfer Level) into a physical layout suitable for integrated circuit fabrication. This transformation ensures that the circuit's functional representation translates into a physical form that meets design constraints, performance goals, and manufacturability standards. The entire flow is carried out using open source tools which includes the RISCV toolchain.

# SKILL OUTCOMES
+ Architectural Design
+ RTL Design / Behavioral Modeling
+ Floorplanning
+ placement
+ clock Tree Synthesis
+ Routing

# TABLE OF CONTENTS
## DAY 1 
**Introduction to RISCV ISA and GNU Compiler Toolchain**
+ Introduction to Basic Keywords
  - [Introduction](#introduction)
  - [From Application to Hardware](#from-apps-to-hardware)
  - [Detail Description of Course Content](#detail-description-of-course-content)

+ Labwork for RISCV Toolchain
  - [C Program](#c-program)
  - [RISCV GCC Compiler and Dissemble](#riscv-gcc-compiler-and-dissemble)
  - [Spike Simulation and Debug](#spike-simulation-and-debug)

+ Integer Number Representation  
  - [64-bit Unsigned Numbers](#64-bit-unsigned-numbers)
  - [64-bit Signed Numbers](#64-bit-signed-numbers)
  - [Labwork For Signed and Unsigned Numbers](#labwork-for-signed-and-unsigned-numbers)

## DAY 2 
**Introduction to ABI and Basic Verification Flow**
+ Application Binary Interface
  - [Introduction to ABI](#introduction-to-abi)
  - [Memory Allocation for Double Words](#memory-allocation-for-double-words)
  - [Load, Add and Store Instructions](#load,-add-and-store-instructions)
  - [32-Registers and their ABI Names](#32-registers-and-their-abi-names)

+ Labwork using ABI Function Calls
  - [Algorithm for C Program using ASM](#algorithm-for-c-program-using-asm)
  - [Review ASM Function Calls](#review-asm-function-calls)
  - [Simulate C Program using Function Call](#simulate-c-program-using-function-call)
# Introduction to Basic Keywords
## Introduction
- **ISA (Instruction Set Archhitecture)**
  - ISA defines the interface between a computer's hardware and its software, specifically how the processor and its components interact with the software instructions that drive the execution of tasks.
  - It encompasses a set of instructions, addressing modes, data types, registers, memory organization, and the mechanisms for executing and managing instructions.

- **RISC-V (Reduced Instruction Set Computing - Five)**.
  - It is an open-source Instruction Set Architecture (ISA) that has gained significant attention and adoption in the world of computer architecture and semiconductor design.
  - RISC architectures simplify the instruction set by focusing on a smaller set of instructions, each of which can be executed in a single clock cycle. This approach usually leads to faster execution of individual instructions. 



## From Apps to Hardware
1. **Apps:** Application software, often referred to simply as "applications" or "apps," is a type of computer software that is designed to perform specific tasks or functions for end-users.
2. **System software:** System software refers to a category of computer software that acts as an intermediary between the hardware components of a computer system and the user-facing application software. It provides essential services, manages hardware resources, and enables the execution of application programs. System software plays a critical role in maintaining the overall functionality, security, and performance of a computer system.'
3. **Operating System:** The operating system is a fundamental piece of software that manages hardware resources and provides various services for both users and application programs. It controls tasks such as memory management, process scheduling, file system management, and user interface interaction. Examples of operating systems include Microsoft Windows, macOS, Linux, and Android.

4. **Compiler:** A compiler is a type of software tool that translates high-level programming code written by developers into assembly-level language.

5. **Assembler:** An assembler is a software tool that translates assembly language code into machine code or binary code that can be directly executed by a computer's processor.

6. **RTL:** RTL serves as an abstraction level in the design process that represents the behavior of a digital circuit in terms of registers and the operations that transfer data between them.

 7. **Hardware:** Hardware refers to the physical components of a computer system or any electronic device. It encompasses all the tangible parts that make up a computing or electronic device and enable it to perform various tasks.

## Detail Description of Course Content
**Pseudo Instructions:** Pseudo-instructions are used to simplify programming, improve code readability, and reduce the number of explicit instructions a programmer needs to write. They are especially useful for common programming patterns that involve multiple instructions.
`Ex: li, mv`.

**Base Integer Instructions:** The term "base integer instructions" refers to the fundamental set of instructions that form the foundation for performing basic arithmetic, logical, and data movement operations.
`Ex: add, sub, and, or, xor, sll`.

**Multiply Extension Intructions:** The RISC-V architecture includes a set of multiply and multiply-accumulate (MAC) extension instructions that enhance the instruction set to perform efficient multiplication and multiplication-accumulate operations.
`Ex: mul, mulh, mulhu, mulhsu`.

**Single and Double Precision Floating Point Extension:** The RISC-V architecture includes floating-point extensions that provide support for both single-precision (32-bit) and double-precision (64-bit) floating-point arithmetic operations. These extensions are often referred to as the "F" and "D" extensions, respectively. Floating-point arithmetic is essential for handling real numbers with fractional parts and for performing accurate calculations involving decimal values.

**Application Binary Interface:** ABI stands for "Application Binary Interface." It is a set of rules and conventions that govern how software components interact with each other at the binary level. The ABI defines various aspects of program execution, including how function calls are made, how parameters are passed and returned, how memory is allocated and managed, and more.

**Memory Allocation and Stack Pointer** 
- Memory allocation refers to the process of assigning and managing memory segments for various data structures, variables, and objects used by a program. It involves allocating memory space from the system's memory pool and releasing it when it is no longer needed to prevent memory leaks.
- The stack pointer is a register used by a program to keep track of the current position of the program's execution on the call stack. 

# Labwork for RISCV Toolchain
## C Program
We wrote a C program for calculating the sum from 1 to n using a text editor, leafpad.

Using the gcc compiler, we compiled the program to get the output.

![sumncode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/da0e7ecf-0612-4790-b80f-cfb5616e346a)

![lab1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/dc061fd3-aa77-43b7-a895-ec8ad269d913)

## RISCV GCC Compiler and Dissemble

Using the riscv gcc compiler, we compiled the C program.

`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sumn.o sumn.c`

Using `ls -ltr sumn.c`, we can check that the object file is created.

To get the dissembled ALP code for the C program, 

`riscv64-unknown-elf-objdump -d sumn.o | less` .

In order to view the main section, type 
`/main`.
Here, since we used -O1 optimisation, the number of instructions are 15.

![O1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/df255613-656e-4fbe-81cf-921391344ed1)

When we use -Ofast optimisation, we can see that the number of instructions have been reduced to 12.

![Ofast2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/ad7c893e-684a-4c38-83a6-3d23e7f02da3)


- -Onumber : level of optimisation required
- -mabi : specifies the ABI (Application Binary Interface) to be used during code generation according to the requirements
- -march : specifies target architecture

In order to view the different options available for these fields, use the following commands

go to the directory where riscv64-unkonwn-elf is present

- -O1 : ``` riscv64-unkonwn-elf --help=optimizer```
- -mabi : ```riscv64-unknown-elf-gcc --target-help```
- -march : ```riscv64-unknown-elf-gcc --target-help```

For different instances,
- use the command ```riscv64-unknown-elf-objdump -d 1_to_N.o | less```
- use ``` /instance``` to search for an instance 
- press ENTER
- press ```n``` to search next occurance
- press ```N``` to search for previous occurance. 
- use ```esc :q``` to quit


## Spike Simulation and Debug

`spike pk sumn.o` is used to check whether the instructions produced are right to give the correct output.

![spike](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/69bcb558-0c87-40a6-b072-8c6d00585288)


`spike -d pk sumn.c` is used for debugging.

The contents of the registers can also be viewed.

![debug](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/4a2d1c24-3c99-4417-95f5-e697ee1fa4fb)

- press ENTER : to show the first line and successive ENTER to show successive lines
- reg 0 a2 : to check content of register a2 0th core
- q : to quit the debug process

# Integer Number Representation 

## Unsigned Numbers
- Unsigned numbers, also known as non-negative numbers, are numerical values that represent magnitudes without indicating direction or sign.
- Range: [0, (2^n)-1 ]

## Signed Numbers
- Signed numbers are numerical values that can represent both positive and negative magnitudes, along with zero.
- Range : Positive : [0 , 2^(n-1)-1]
          Negative : [-1 to 2^(n-1)]
 
## Labwork

We wrote a C program that shows the maximum and minimum values of 64bit unsigned numbers.

![unsigncode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/2ec49af7-268a-46b2-9cd1-fabca10b5afc)

![highestunsign](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8d1aee5d-24fe-4d5e-8d05-b1f7d07697af)


We wrote a C program that shows the maximum and minimum values of 64bit signed numbers.

![correctcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/f2782b40-cfd3-4659-850f-af0c91b6287f)

![correctsign](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/e36d8e8a-5351-485b-a3c3-c8faddaef8e0)

# Application Binary Interface
## Introduction to ABI
+ An Application Binary Interface (ABI) is a set of rules and conventions that dictate how binary code interacts with and communicates with other binary code, typically at the level of machine code or compiled code. In simpler terms, it defines the interface between two software components or systems that are written in different programming languages, compiled by different compilers, or running on different hardware architectures.
+ The ABI is crucial for enabling interoperability between different software components, such as different libraries, object files, or even entire programs. It allows components compiled independently and potentially on different platforms to work seamlessly together by adhering to a common set of rules for communication and data representation.
## Memmory Allocation for Double Words
64-bit number (or any multi-byte value) can be loaded into memory in little-endian or big-endian. It involves understanding the byte order and arranging the bytes accordingly
1. **Little-Endian:**
In little-endian representation, you store the least significant byte (LSB) at the lowest memory address and the most significant byte (MSB) at the highest memory address.
2. **Big-Endian:**
In big-endian representation, you store the most significant byte (MSB) at the lowest memory address and the least significant byte (LSB) at the highest memory address.

## Load, Add and Store Instructions
Load, Add, and Store instructions are fundamental operations in computer architecture and assembly programming. They are often used to manipulate data within a computer's memory and registers.
1. **Load Instructions:**
Load instructions are used to transfer data from memory to registers. They allow you to fetch data from a specified memory address and place it into a register for further processing.

Example `ld x6, 8(x5)`

In this Example
- `ld` is the load double-word instruction.
- `x6` is the destination register.
- `8(x5)` is the memory address pointed to by register `x5` (base address + offset).
2. **Store Instructions:**
Store instructions are used to write data from registers into memory.They store values from registers into memory addresses

Example `sd x8, 8(x9)`

In this Example
- `sd` is the store double-word instruction.
- `x8` is the source register.
- `8(x9)` is the memory address pointed to by register `x9` (base address + offset).
3. Add Instructions:
  Add instructions are used to perform addition operations on registers. They add the values of two source registers and store the result in a destination register.

Example `add x9, x10, x11`

In this Example
- `add` is the add instruction.
- `x9` is the destination register.
- `x10` and `x11` are the source registers.
## 32-Registers and their ABI Names
The choice of the number of registers in a processor's architecture, such as the RISC-V RV64 architecture with its 32 general-purpose registers, involves a trade-off between various factors. While modern processors can have more registers but increasing the number of registers could lead to larger instructions, which would take up more memory and potentially slow down instruction fetch and decode.
#### ABI Names
ABI names for registers serve as a standardized way to designate the purpose and usage of specific registers within a software ecosystem. These names play a critical role in maintaining compatibility, optimizing code generation, and facilitating communication between different software components. 

<img width="430" alt="abitypes" src="https://github.com/NishitaNJ/pes_asic_class/assets/142140741/19861510-ed7c-41d5-99ae-cd6112ae61be">

# Labwork using ABI Function Calls
## Algorithm for C Program using ASM
- Incorporating assembly language code into a C program can be done using inline assembly or by linking separate assembly files with your C code.
- When you call an assembly function from your C code, the C calling convention is followed, including pushing arguments onto the stack or passing them in registers as required.
- The program executes the assembly function, following the assembly instructions you've provided.

## Review ASM Function Calls
- We wrote C code in one file and your assembly code in a separate file.
- In the assembly file, we declared assembly functions with appropriate signatures that match the calling conventions of your platform.

**C Program**

![customcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/23cc427e-63fe-4270-a4fe-39ca47c51da9)

**Asseembly File**

![customload](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/b7758c8e-380a-4eb7-a4d2-c566b25f228a)

## Simulate C Program using Function Call
**Compilation:** To compile C code and Asseembly file use the command

`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o custom1to9.o custom1to9.c load.s` 

this would generate object file `custom1to9.o`.

**Execution:** To execute the object file run the command 

`spike pk custom1to9.o`

![customoutput](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/0c5cca82-634d-4c04-aeb3-65b302e9474a)

## Lab to Run C-Program on RISCV-CPU

`git clone https://github.com/kunalg123/riscv_workshop_collaterals.git`

`cd riscv_workshop_collaterals`

`ls -ltr`

`cd labs`

`ls -ltr`

`chmod 777 rv32im.sh`

`./rv32im.sh`

![pic1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/d5d01169-5433-4d0b-9f87-919c5decb1b9)

![pic2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/82703ec6-da83-42fa-a2f1-6546c54a917e)


</details>

# RTL DESIGN USING VERILOG WITH SKY130 TECHNOLOGY
## Objective
The objective of this course is to provide us with a comprehensive understanding of RTL (Register Transfer Level) design principles using the Verilog Hardware Description Language within the context of Sky130 technology.
## Table of Contents
+ Introduction to Verilog RTL Design and Synthesis
+ Timing libs, hierarchical vs flat synthesis and efficient flop coding styles
+ Combinational and sequential optimizations
+ GLS Blocking vs non-blocking and synthesis-simulation mismatch
## Skill Outcomes
Upon completing this course, we will emerge with a robust skill set in RTL design using Verilog with a focus on Sky130 technology. We will comprehend the fundamental concepts of digital logic design, including combinational and sequential circuits, and be able to model complex behaviors using Verilog. Moreover, we will gain insights into the distinctive attributes of Sky130 technology, enabling them to optimize designs for performance and power. Through hands-on experience and troubleshooting exercises, we will have cultivated their practical problem-solving skills, ready to tackle real-world design challenges and lay the groundwork for advanced digital design pursuits.
<details>
  <summary>DAY1:Introduction to Verilog RTL Design and Synthesis</summary>
  
### Introduction to open-source simulator iverilog

#### Introduction to iverilog design test bench:

This introduction to Iverilog Design Test Bench delves into the principles of creating effective and comprehensive test benches using the Iverilog tool. Throughout this course, we learn how to construct simulation environments that rigorously exercise your digital designs, ensuring their functional correctness and reliability before actual hardware implementation.

* Simulator: A simulator is a design used to check designs. The RTL design is actually the implementation of a spec. RTL design is checked for adherence to the spec by simulating the design. In this course we will be using iverilog simulator for simulating the design.

* Testbench: A test bench is a simulation environment essential for validating digital designs. It tests the design's functionality by subjecting it to diverse input scenarios and comparing its outputs against expected results. Comprising stimulus generation and results verification components, the test bench generates inputs, monitors outputs, and uses assertions to pinpoint discrepancies. This proactive process uncovers errors before physical implementation, saving time and resources. Test benches help ensure accurate and robust digital systems, with tools like Iverilog serving as platforms for their creation and execution.

* Design and testbench setup:

![test_setup](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/24292d10-93ee-47ba-ada5-add469ede710)

* iverilog based simulation flow:

![simulation flow](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/65cd8ac7-ae40-4414-8228-5953de8a95b0)

The Iverilog-based simulation flow employs the Iverilog simulator to validate digital designs described in Verilog. A Verilog description of the circuit and a separate test bench are created. After compilation, the simulator executes the simulation, evaluating signal values and logic computations over time. Recorded results are analyzed for correctness and discrepancies, aiding debugging and design refinement. Simulation reveals performance issues and guides optimization. This iterative process ensures design accuracy and reliability before physical implementation. Iverilog generates logs and reports, assisting in result interpretation and verification.

### Lab using iverilog and gtkwave
#### Introduction to lab:
![pic2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a6f0e729-7cc8-4326-8cad-d2db5353f815)
![pic1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/6a7c4355-701c-49e6-96b5-74135f39c6a0)

* `git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git` this particular code will allow us to git clone which will create a directory `sky130RTLDesignAndSynthesisWorkshop` which is used throughout this course.
* `my_lib` contains all the library files.
* `lib` contains the standard cell library which we use for synthesis.
* `verilog_models` this contains all the standard cell verilog models.
* `verilog_files` this contains all the source and testbench files.

#### Introduction to iverilog gtkwave:

![gtk1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9689473e-ea62-4841-ab47-8b4406fc34c6)

* `verilog_files` contains all the design files.
* `iverilog` is the command used used to load a design file. Here we are loading `iverilog good_mux.v tb_good_mux.v` where `tb_good_mux.v` is the testbench file.
* This will create an output file, `a.out`
* On executing, `./a.out` it will dump the vcd file.
* Now this vcd file is loaded into simulator using the command `gtkwave`
* `gtkwave tb_good_mux.vcd` this will give us the gtk wave form of the mux implemented in the file.
![gtk2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/6bbc3e9e-80fc-48df-bee1-cc724398369c)
* uut : unit under test
* dut : design under test
![gtk3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/e5583dd2-ee2c-4344-9dbb-b6df1a4fb52b)
* This is the code written to implement a multiplexer.

### Introduction to Yosys and logic synthesis
#### Introduction to Yosys:
* Yosys: Yosys is an open-source framework and toolchain for Verilog RTL synthesis. It offers a powerful set of tools for transforming high-level RTL code into a lower-level gate-level representation suitable for FPGA and ASIC implementations. Yosys provides an array of synthesis optimizations, technology mapping, and various analysis and transformation passes to enhance the efficiency and quality of synthesized designs. As a key player in the digital design and synthesis landscape, Yosys contributes to the development of efficient, reliable, and high-performance digital systems.
* Yosys is a synthesizer used to convert RTL to netlist.
![yosys flow](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/7608924b-e006-4479-837e-245d362dfb8b)
* `read_verilog` : reads the command
* `read_liberty` : reads the .lib file
* `write_verilog` : writes the netlist
* Netlist file is the representation of the design in the form of standard cells.

![verify](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/1144e39e-2973-4158-b355-cb2b46f7849f)
* Verification of Synthesized design: In order to make sure that there are no errors in the netlist, we'll have to verify the synthesized circuit.
* The gtkwave output for the netlist should match the output waveform for the RTL design file. As netlist and design code have same set of inputs and outputs, we can use the same testbench and compare the waveforms.

#### Introduction to logic synthesis:
* Logic synthesis is a pivotal phase in digital circuit design that bridges the gap between high-level functional descriptions and the physical realization of a design. It involves the transformation of Register Transfer Level (RTL) representations, often described using hardware description languages like Verilog or VHDL, into a lower-level gate-level implementation. The goal of logic synthesis is to optimize the design for factors such as area, performance, and power consumption while maintaining its intended functionality. Through a series of transformations, logic synthesis generates a network of logic gates that implement the desired behavior, enabling efficient and accurate translation from abstract concepts to practical, implementable hardware.
* RTL Design: RTL design, which stands for Register Transfer Level design, is a key methodology in digital circuit design where a digital system's behavior and functionality are described using a hardware description language (HDL) such as Verilog or VHDL. At the RTL level, the focus is on defining how data is transferred and manipulated between registers, representing the flow of information within the system. RTL design forms the basis for further stages of the design flow, including synthesis, simulation, and verification, enabling designers to architect complex digital systems with clarity and efficiency.
* Synthesis flow: The synthesis flow in digital circuit design transforms an RTL description written in hardware description languages (HDL) like Verilog into a gate-level netlist suitable for hardware implementation. This involves logic synthesis, technology mapping, and optimization steps to optimize factors such as performance and power consumption. Timing analysis ensures that timing constraints are met, followed by gate-level simulation for validation. The flow culminates in generating output files used in subsequent implementation stages. This process is a pivotal bridge between high-level design and physical hardware realization.
* A ".lib" file, also known as a library file, is a crucial component in digital circuit design that contains information about the characteristics and behavior of standard cells, macros, and other functional elements used in integrated circuits. These files store data such as timing information, power consumption, and logical functionality for various input conditions. The data is organized in tables, providing details on how these cells operate at different voltage, temperature, and load conditions. ".lib" files serve as a reference for synthesis, optimization, and other design processes, aiding in selecting the best components to implement a design while considering factors like speed, power, and area.
* Why do we need deifferent flavors of gate?
  Diverse gate flavors are essential in digital circuit design to cater to varying design objectives. These flavors, known as standard cells, address factors like speed, power consumption, and area efficiency. High-speed gates prioritize rapid signal propagation, low-power gates minimize energy use, and area-efficient gates reduce space requirements. In order to make a faster circuit, the clock frequency should be high. For that the time period of the clock should be as low as possible. However, in a sequential circuit, clock period depends on three factors so that data is not lost or to be glitch free.

</details>
