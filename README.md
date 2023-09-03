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
![synthesisflow](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/99e7c3b6-a473-48fe-a035-dbd1dfd45dfb)

* A ".lib" file, also known as a library file, is a crucial component in digital circuit design that contains information about the characteristics and behavior of standard cells, macros, and other functional elements used in integrated circuits. These files store data such as timing information, power consumption, and logical functionality for various input conditions. The data is organized in tables, providing details on how these cells operate at different voltage, temperature, and load conditions. ".lib" files serve as a reference for synthesis, optimization, and other design processes, aiding in selecting the best components to implement a design while considering factors like speed, power, and area.
* Why do we need deifferent flavors of gate?
  Diverse gate flavors are essential in digital circuit design to cater to varying design objectives. These flavors, known as standard cells, address factors like speed, power consumption, and area efficiency. High-speed gates prioritize rapid signal propagation, low-power gates minimize energy use, and area-efficient gates reduce space requirements. In order to make a faster circuit, the clock frequency should be high. For that the time period of the clock should be as low as possible. However, in a sequential circuit, clock period depends on three factors so that data is not lost or to be glitch free.
![gate flavor](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/35fa9d89-f82d-4dbb-b1e2-89c66684ac56)
For the below circuit the three factors are

+ Clock to Q of flipflop A
+ Propagation delay of combinational circuit
+ Setuptime of flipflop B 

* Faster cells vs slower cells: Faster cells prioritize speed and rapid signal propagation, making them suitable for applications that demand quick data processing and response times. Slower cells, on the other hand, prioritize power efficiency and reduce signal switching activity, making them suitable for designs that emphasize lower power consumption.

Load in digital circuit is of Capacitence. Faster the charging or dicharging of capacitance, lesser is the celll delay. However, for a quick charge/ discharge of capacitor, we need transistors capable of sourcing more current i.e, we need WIDE TRANSISTORS.

Wider transistors have lesser delay but consume more area and power. Narrow transistors are other way around. Faster cells come with a cost of area and power.

Selection of cells: The selection of cells, also known as standard cells, is a critical decision in digital circuit design. It involves choosing the appropriate library cells that best match the functional requirements, performance targets, power constraints, and area limitations of a design. By strategically picking the right cells for each logic function, designers can optimize the overall performance, power efficiency, and physical layout of the circuit. We'll need to guide the Synthesizer to choose the flavour of cells that is optimum for implementation of logic circuit. Keeping in view of previous observations of faster vs slower cells,to avoid hold time violations, larger circuits, sluggish circuits, we offer guidance to synthesizer in the form of Constraints.

Synthesis illustration:
![syn illustration](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/f29761ce-dae2-4ad7-a0ac-5bc56f64b80a)


### Labs using Yosys and Sky130 PDKs
**Invoking Yosys**
* To invoke yosys type the command `yosys`
![yosys](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c271c043-c692-4a68-bad4-75e4c2716ef7)

Reading the .lib, design files and choosing the module to synthesize.

![yosys1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/66ac72ac-c6d6-4917-b335-0e63587f3b98)
Generating Netlist:
![yosys2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/7f0d7a8a-b45c-4829-bed0-9b89061dd3a6)
![yosys3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/5e267d55-22a0-4561-8b5a-ff79633cf952)

Synthesis results and synthesized circuit for multiplexer:
![yosys4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/51c12634-2245-4f2e-9212-535f1ef4d5b8)

Netlist code:
![yosys5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/4c256bfd-ce29-48a9-a3dc-8b6f41ab154e)
![yosys6](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/25d1d34a-bfb8-44c7-82c6-d98d12320f90)
![yosys7](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/f2aeaba7-038a-4466-91f0-46873d5ec7ec)
![yosys8](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c563f936-4b77-4211-95d5-f98288f788b0)

</details>
<details>
  <summary>DAY2:Timing libs, heirarchical vs flat synthesis and efficient flop coding styles</summary>
  
### Introduction to timing .libs:
* To view the contents in the .lib
![lib1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/b174a68f-3f35-4a07-808c-3b1def5ba788)


* The first line in the file library ("sky130_fd_sc_hd__tt_025C_1v80")  :

  + tt : indicates variations due to process and here it indicates Typical Process.
  + 025C : indicates the variations due to temperatures where the silicon will be used.
  + 1v80 : indicates the variations due to the voltage levels where the silicon will be incorporated.

* It also displays the units of various parameters.
![lib2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/79eb3909-22f6-4ccc-8c9f-d71e1e9ed184)


* It gives the features of the cells

* To enable line number `:se nu`

* To view all the cells `:g//`

* To view any instance `:/instance`

* Since there are 5 inputs, for all the 32 possible combinations, it gives the delay, power and all the other parameters for each cell.

* The below image shows the power consumption and area comparision.
<img width="911" alt="lib3" src="https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9e538d6f-e72b-4dd3-bbc5-a65a3e6a5e29">

### Heirarchical vs Flat Synthesis:
* Hierarchical Synthesis: Hierarchical synthesis is a methodology used to create complex digital systems by dividing them into manageable, interconnected modules or blocks. Each module is designed and synthesized independently, adhering to well-defined interfaces for communication and data exchange. These modules are then organized hierarchically, with higher-level modules incorporating lower-level ones, ultimately forming the complete digital system.

* The file we used in this lab is `multiple_modules.v`

  `cd home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/verilog_files`
  `gvim multiple_modules.v`
  
<img width="321" alt="heir1" src="https://github.com/NishitaNJ/pes_asic_class/assets/142140741/3a6996f9-66e5-4155-b6d5-ee018334127c">

* `multiple_modules` instantiates `sub_module1` and `sub_module2`

* Launch `yosys`

* read the library file `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`

* read the verilog file  `read_verilog multiple_modules.v`

* `synth -top multiple_modules` to set it as top module
![hier1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/d218b9c7-c86d-43af-a770-244bf9275c80)
![hier2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9191d849-f1bb-4ffd-bbaa-96f089e45a11)


* `abc -liberty home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`

* To view the netlist `show multiple_modules`

![hier3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/fe53e3c2-e0be-47e7-8120-f37b13a47752)


* Here it shows `sub_module1` and `sub_module2` instead of AND gate and OR gate.
* `write_verilog -noattr multiple_modules_hier.v`
* `!gvim multiple_modules_hier.v`
* These commands will generate the netlist.
![hier4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9282ca70-193b-40a1-815f-a931c678c2c1)
![hier5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/580bcb0e-3a2a-4ecb-93f3-efc9eee1ce19)

* Flat Synthesis: Flat synthesis refers to a design approach where the entire system is synthesized as a single, non-hierarchical entity, without breaking it down into smaller, interconnected modules or blocks. In this method, all components and their interconnections are synthesized together in a single flat structure.
* To run flat synthesis type the command `flatten`
* Then open the netlist:
    + `write_verilog -noattr multiple_modules_flat.v`
    + `!gvim multiple_modules_flat.v` this will generate the netlist.
![flat1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/f2d3e82d-14fd-4d3a-a26d-a093dd91e915)
![flat2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8d732d7f-07fa-46ab-adc2-67825f3a18ae)

* Synthesizing a submodule level:
  + while synthesizing at a submodule level we see only a single sub module.
  + `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `read_verilog multiple_modules.v`
  + `synth -top sub_module1`
  + `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `show`
  + The below image consists of a single AND gate.

![flat3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a474a620-5b9f-494b-a96a-f639913df86a)

* We use submodule level synthesis when we have multiple instances of the same module. This is generally used in cases where we have massive designs so that we get best optimized results.

### Various Flop coding styles and optimization:
#### Why Flops and flop coding styles:
* Flip-flops are crucial in digital system design as they serve as the backbone for storing binary states, synchronized to clock signals. They enable sequential logic, memory storage, control signal generation, and timing control in digital systems. Flip-flops play a vital role in isolating clock domains, meeting timing constraints, and ensuring testability. Overall, they are fundamental components that enable the reliable and synchronized operation of digital systems, making them indispensable in modern digital design.
* A flip-flop (often abbreviated as "flop") is a fundamental building block in digital circuit design.
* It's a type of sequential logic element that stores binary information (0 or 1) and can change its output based on clock signals and input values.
* In a combinational circuit, the output changes after the propagation delay of the circuit once inputs are changed.
* During the propagation of data, if there are different paths with different propagation delays, then a glitch might occur.
* There will be multiple glitches for multiple combinational circuits.
* Hence, we need flops to store the data from the combinational circuits.
* When a flop is used, the output of combinational circuit is stored in it and it is propagated only at the posedge or negedge of the clock so that the next combinational circuit gets a glitch free input thereby stabilising the output.
* We use control pins like set and reset to initialise the flops.
* They can be synchronous and asynchronous.
* D Flip-Flop with Asynchronous Reset
  + When the reset is high, the output of the flip-flop is forced to 0, irrespective of the clock signal.
  + Else, on the positive edge of the clock, the stored value is updated at the output.
  + `gvim dff_asyncres_syncres.v`

![dff1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a7b6ed2c-0e0e-4790-87de-e286c0e54de6)

* D Flip_Flop with Asynchronous Set
  + When the set is high, the output of the flip-flop is forced to 1, irrespective of the clock signal.
  + Else, on positive edge of the clock, the stored value is updated at the output.
  + `gvim dff_async_set.v`

![dff2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c120a2a0-00fa-4e70-8d02-5ece3c9b24b0)

* D Flip-Flop with Synchronous Reset
  + When the reset is high on the positive edge of the clock, the output of the flip-flop is forced to 0.
  + Else, on the positive edge of the clock, the stored value is updated at the output.
  + `gvim dff_syncres.v`

![dff3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/93fd1826-631c-4f08-bb3b-59bb16e0fa77)

* D Flip-Flop with Asynchronous Reset and Synchronous Reset
  + When the asynchronous resest is high, the output is forced to 0.
  + When the synchronous reset is high at the positive edge of the clock, the output is forced to 0.
  + Else, on the positive edge of the clock, the stored value is updated at the output.
  + Here, it is a combination of both synchronous and asynchronous reset DFF.
  + `gvim dff_asyncres_syncres.v`

![dff4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/3f4ca6cb-4e78-4982-9155-0615b439ff20)

#### Lab flop synthesis simulation:
* D Flip-Flop with Asynchronous Reset
  + Simulation
    - `cd /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/verilog_files`
    - `iverilog dff_asyncres.v tb_dff_asyncres.v`
    - `./a.out`
    - `gtkwave tb_dff_asyncres.vcd`
    
  ![flop1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8997f306-4e52-4c45-aa61-4969b1743dae)

  + Synthesis
    - `cd /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/verilog_files`
    - `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog dff_asyncres.v`
    - `synth -top dff_asyncres`
    - `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `show`
    
  ![flop4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/95b2a8d1-74fa-457f-af98-26d6c2c5a8e1)

* D Flip_Flop with Asynchronous Set
  + Simulation
    - `cd /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/verilog_files`
    - `iverilog dff_async_set.v tb_dff_async_set.v`
    - `./a.out`
    - `gtkwave tb_dff_async_set.vcd`
  ![flop2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9dcf3638-b91a-4f8c-85f6-58417587c99a)

  + Synthesis
    - `cd /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/verilog_files`
    - `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog dff_async_set.v`
    - `synth -top dff_async_set`
    - `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `show`
    
  ![flop5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/1203c8fd-3a64-4794-b1a0-083bc80a3579)

* D Flip-Flop with Synchronous Reset
  + Simulation
    - `cd /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/verilog_files`
    - `iverilog dff_syncres.v tb_dff_syncres.v`
    - `./a.out`
    - `gtkwave tb_dff_syncres.vcd`
  ![flop3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/6a1d0345-d508-4733-b4fc-76ad10944059)

  + Synthesis
    - `cd /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/verilog_files`
    - `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog dff_syncres.v`
    - `synth -top dff_syncres`
    - `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `show`

  ![flop6](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/850b9c19-61f4-4378-94fc-5c3c5680a2f4)

#### Interesting Optimizations:
* `gvim mult_2.v`

![io1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/4af49b93-384a-486e-a51c-39a50b5d5cae)

* `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
* `read_verilog mult_2.v`
* `synth -top mul2`

![io2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/fec19b12-1248-4c88-ba55-0bda7c337e87)

* `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
* `show`

![io3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/0f86155e-7573-481a-b122-94234c81f8cd)

* `write_verilog -noattr mul2_netlist.v`
* `!gvim mul2_netlist.v`

![io4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/bdc9c818-1726-49d6-a20e-1c301e967e5a)

* `gvim mult_8.v`

![io5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/f61918bf-cf4d-4b8f-8684-5617545f8095)

* `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`  
* `read_verilog mult_8.v`
* `synth -top mult8`

![io6](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9b412e4f-bdc1-4275-99fd-9a692d008c13)

* `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
* `show`

![io7](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/2c6acdd5-c3e2-42cd-8ec4-1ac1d01b28c4)

* `write_verilog -noattr mult8_netlist.v`
* `!gvim mult8_netlist.v`

![io8](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8915f7c4-76ac-4c18-b343-ab325abb6dcb)

</details>
<details>
  <summary>DAY3: Combinational and Sequential Optimizations</summary>
  
### Introduction to Optimizations:

* In digital logic there are two types of logic: Combinational and Sequential logic.
* Combinational logic: Combinational logic plays a fundamental role in digital system design, providing the foundation for the manipulation and processing of binary data. It consists of logic gates, such as AND, OR, and NOT gates, which are interconnected to perform specific functions based solely on the current input values, with no memory of past inputs.
  + Combinatinal logics are used mainly to squeez the logic to get the most optimized results.
  + Techniques for optimization:
    - Constant propagation in combinational logic design refers to the process of identifying and utilizing constant values within a combinational logic circuit to optimize its performance and reduce complexity. This technique is primarily used to streamline the circuit's operation by eliminating unnecessary logic gates and signal paths. This is a direct optimization technique.
    - Boolean logic optimization refers to the process of simplifying Boolean expressions and logic circuits to achieve specific objectives such as reducing gate count, minimizing propagation delays, and improving overall circuit performance.
* Sequential logic: Sequential logic is an integral component of digital system designs, serving as the foundation for creating systems that can process and store data over time. Unlike combinational logic, which relies solely on present inputs to generate outputs, sequential logic incorporates memory elements like flip-flops and registers to retain and manage past states.
  + Techniques for Optimization:
    - Basic:
      + Sequential Constant Propagation: Sequential constant propagation is an optimization technique used in digital system design, particularly in the context of sequential logic circuits. It builds upon the concept of constant propagation, which identifies and replaces variables or expressions with constant values during compilation or design.
    - Advanced:
      + State Optimization: State optimization, also known as state minimization or state reduction, is an optimization technique used in digital design to reduce the number of states in finite state machines (FSMs) while preserving the original functionality.
      + Retiming: Retiming is an optimization technique used in sequential logic design to improve the performance of digital circuits by strategically rearranging the placement of flip-flops (registers) without altering the functionality of the circuit. The primary goal of retiming is to minimize critical path delays, thereby enhancing the circuit's speed and meeting timing requirements.
      + Sequential logic cloning: Sequential logic cloning, also known as retiming-based cloning or register cloning, is a technique used in digital design to improve the performance of a circuit by duplicating or cloning existing registers (flip-flops) and introducing additional pipeline stages. This technique aims to balance the critical paths within a circuit and reduce its overall clock period, leading to improved timing performance and better overall efficiency.

### Combinational logic optimizations:
* opt_check
  + `gvim opt_check.v`
    
  ![cl1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c67a165a-b4ff-436d-ab71-0c54fe9a0656)

  + `yosys`
  + `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `read_verilog opt_check.v`
  + `synth -top opt_check`
    
  ![cl2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/1987e20d-b024-41d4-a85b-9ad518d828f6)

  + `opt_clean -purge`
  + `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `show`
    
  ![cl3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c05eb102-0bbf-408b-a246-1664da7e1538)

* opt_check2
  + `gvim opt_check2.v`
    
  ![cl4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/009a4cd1-2fcd-44e8-9466-ac1e927662bd)

  + `yosys`
  + `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `read_verilog opt_check2.v`
  + `synth -top opt_check2`
    
  ![cl5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/cc39ea28-d4e8-4dec-b29c-faa12fb16bdd)

  + `opt_clean -purge`
  + `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `show`
    
  ![cl6](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c0fabba9-7319-4647-bb0f-e65dd79c3647)

* opt_check3
  + `gvim opt_check3.v`
    
  ![cl7](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/996eb194-f218-4fca-a371-f7d2d579d7a2)

  + `yosys`
  + `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `read_verilog opt_check3.v`
  + `synth -top opt_check3`
    
  ![cl8](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/6cc3d5da-f91a-48f8-937d-700dfd4e4529)

  + `opt_clean -purge`
  + `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `show`
    
  ![cl9](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/43379af7-d030-46b2-ae47-d13d7a64239d)

* opt_check4
  + `gvim opt_check4.v`
    
  ![cl10](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/88eebe0a-98e0-4621-8920-1ad48c6cf30a)

  + `yosys`
  + `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `read_verilog opt_check4.v`
  + `synth -top opt_check4`
    
  ![cl11](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/d47c28c2-b8c8-4754-8bde-0f16cc87bcc3)

  + `opt_clean -purge`
  + `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `show`
    
  ![cl12](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/12e6a51c-5e44-4bb4-86d0-996fe4d1f083)

* multiple_module_opt
  + `gvim multiple_module_opt.v`
    
  ![cl13](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/5f2e1e68-8951-4b52-b9b2-d4efbfdea5c7)

  + `yosys`
  + `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `read_verilog multiple_module_opt.v`
  + `synth -top multiple_module_opt`
    
  ![cl14](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/0b021821-d11b-4404-b4ab-0663f633487b)

  + `flatten`
  + `opt_clean -purge`
  + `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `show`
  
  ![cl16](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/3c7e1f78-7174-45e6-9fa5-b185d3d4f9fa)

### Sequential Logic Optimizations:
* dff_const1
  + `gvim dff_const1.v`
  
  ![sl1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a074ee61-8414-490d-bfc5-637c9cfbe364)

  + Simulation:
    - `iverilog dff_const1.v tb_dff_const1.v`
    - `./a.out`
    - `gtkwave tb_dff_const1.vcd`

    ![sl2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/3939d23b-587e-42b9-8486-4952ad02c270)

  + Synthesis:
    - `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog dff_const1.v`
    - `synth -top dff_const1`
    
    ![sl3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/2ba27f98-9c07-4318-8f86-779f123eb867)

    - `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `show`

    ![sl4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/ba4628ae-a159-48d1-be5b-b120096e7e7e)

* dff_const2
  + `gvim dff_const2.v`
 
  ![sl5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/4e2298fb-991e-49e0-a753-827ac3a5229e)

  + Simulation:
    - `iverilog dff_const2.v tb_dff_const2.v`
    - `./a.out`
    - `gtkwave tb_dff_const2.vcd`
   
    ![sl6](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/dbb9cdb3-44b5-4abc-a484-fdde4c4570a6)

  + Synthesis:
    - `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog dff_const2.v`
    - `synth -top dff_const2`
    
    ![sl7](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a06284c4-f099-4991-86e1-930b03f857db)

    - `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `show`

    ![sl8](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/637246e0-b443-4bfd-a0b0-e8291a989d75)

* dff_const3
  + `gvim dff_const3.v`

  ![sl9](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c76a428c-0c55-4de2-9095-a2af80d08ca2)

  + Simulation:
    - `iverilog dff_const3.v tb_dff_const3.v`
    - `./a.out`
    - `gtkwave tb_dff_const3.vcd`
   
    ![sl10](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/75052408-1ecd-49b2-bd07-9fac380bdeee)

  + Synthesis:
    - `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog dff_const3.v`
    - `synth -top dff_const3`
   
    ![sl11](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/e5293aa8-f197-4de3-9275-629730ec353e)

    - `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `show`
   
    ![sl12](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/2e08c075-6412-49b8-a083-15c020832788)

* dff_const4
  + `gvim dff_const4.v`
 
  ![sl13](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/1d3d1d9b-2d7b-4d6e-b6ec-1958ca8a84df)

  + Simulation:
    - `iverilog dff_const4.v tb_dff_const4.v`
    - `./a.out`
    - `gtkwave tb_dff_const4.vcd`
   
    ![sl14](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/ed99d956-bc88-42c4-baec-85ea8841f05b)

  + Synthesis:
    - `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog dff_const4.v`
    - `synth -top dff_const4`
   
    ![sl15](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/191afb02-8cd0-4dc7-85a3-ad23e0ad3d47)

    - `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `show`

    ![sl16](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/1e513264-da58-41e7-8fb5-fb5d4b8fec94)

* dff_const5
  + `gvim dff_const5.v`

  ![sl17](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/96a126e7-0d81-4719-9eed-b975430aca35)

  + Simulation:
    - `iverilog dff_const5.v tb_dff_const5.v`
    - `./a.out`
    - `gtkwave tb_dff_const5.vcd`
   
    ![sl18](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/b8e9126b-7ee2-48ca-986c-4e3820df7455)

  + Synthesis:
    - `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog dff_const5.v`
    - `synth -top dff_const5`
 
    ![sl19](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c8426bab-9f86-45bb-b18e-45f34b08a317)

    - `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `show`

    ![sl20](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/d3ffaa60-f9c9-4c01-a7f6-9c8dea8b52ea)

### Sequential optimizations for unused outputs:
* counter_opt
  + `gvim counter_opt.v`

  ![slu1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/45d8a94d-c735-4d3c-8ab6-7e4d10ae441e)

  + `yosys`
  + `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `read_verilog counter_opt.v`
  + `synth -top counter_opt`
 
  ![slu2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/f0638c22-663c-4e52-872f-7d79b1aab8e6)

  + `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `show`
 
  ![slu3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/1d74e28b-6d93-44b1-be6e-8a8bd2e2b4ad)

* counter_opt2
  + `gvim counter_opt2.v`
 
  ![slu4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/c257246a-dcd5-4afc-8e47-570d8e8f1849)

  + `yosys`
  + `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `read_verilog counter_opt2.v`
  + `synth -top counter_opt`
 
  ![slu5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/05bec9be-ad45-4250-9804-236b961240db)

  + `dfflibmap -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
  + `show`
 
  ![slu6](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/1ba80f4b-2475-473b-83d7-a5b18fd6bb22)

</details>

<details>
  <summary>DAY4: GLS, blocking vs non-blocking and Synthesis-Simulation mismatch</summary>

### GLS, Synthesis-Simulation mistmatch and blocking vs non-blocking statements:
* GLS: Gate Level Simulation
  + Gate-level simulation in digital system design refers to the process of simulating and analyzing the behavior of a digital system at the level of individual logic gates and flip-flops.
  + It involves modeling the logical and timing characteristics of these fundamental building blocks to verify the correctness, functionality, and timing constraints of the digital circuit.
  + This type of simulation is typically performed after the logic synthesis process, where a high-level description of the design is transformed into a netlist of gates and flip-flops.
  + We perform this to verify logical correctness of the design after synthesizing it. Also ensuring the timing of the design is met.
  
![GLS](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/985195a4-3238-4b29-9d2c-13696631d369)

* Synthesis-Simulation mismatch:
  + Synthesis simulation mismatch refers to discrepancies that can arise between the results of two crucial stages in digital design: synthesis and simulation. During synthesis, a high-level design description is transformed into a gate-level representation. Simulation then verifies the design's correctness. Mismatch issues can include timing errors, functional discrepancies, and optimization effects introduced during synthesis that affect simulation results.
  + This mismatch is a critical concern in digital design because it indicates that the actual hardware implementation might not perform as expected, potentially leading to functional or timing failures in the fabricated chip.
* Blocking and non-blocking statements:
  + Blocking statement: Blocking statements are executed sequentially in the order they appear in the code and have an immediate effect on signal assignments.
  + Non-blocking statement: Non-blocking assignments are used to model concurrent signal updates, where all assignments are evaluated simultaneously and then scheduled to be updated at the end of the time step.
  + Caveat with blocking statements:
    - Procedural Execution: Blocking statements are executed sequentially in the order they appear within a procedural block (such as an always block). This can lead to unexpected behavior if the order of execution matters and is not well understood.
    - Lack of Parallelism: Blocking statements do not accurately represent the parallel nature of hardware. In hardware, multiple signals can update concurrently, but blocking statements model sequential behavior. As a result, using blocking statements for modeling complex concurrent logic can lead to incorrect simulations.
    - Race Conditions: When multiple blocking assignments operate on the same signal within the same procedural block, a race condition can occur. The outcome of such assignments depends on their order of execution, which might lead to inconsistent or unpredictable behavior.
    - Limited Representation of Hardware: Hardware systems are inherently concurrent and parallel, but blocking statements do not capture this aspect effectively. Using blocking assignments to model complex combinational or sequential logic can lead to models that are difficult to understand, maintain, and debug.
    - Combinatorial Loops: Incorrect use of blocking statements can lead to unintentional combinational logic loops, which can result in simulation or synthesis errors.
    - Debugging Challenges: Debugging code with many blocking assignments can be challenging, especially when trying to track down timing-related issues.
    - Not Suitable for Flip-Flops: Blocking assignments are not suitable for modeling flip-flop behavior. Non-blocking assignments (<=) are generally preferred for modeling flip-flop updates to ensure accurate representation of concurrent behavior.
    - Sequential Logic Misrepresentation: Using blocking assignments to model sequential logic might not capture the intended behavior accurately. Sequential elements like registers and flip-flops are better represented using non-blocking assignments.
    - Synthesis Implications: The behavior of blocking assignments might not translate well during synthesis, leading to potential mismatches between simulation and synthesis results.

### Labs on GLS and Synthesis-Simulation mismatch:
* ternary_operator_mux
  + Opening the file: `gvim ternary_operator_mux.v`
 
  ![gls1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/e249394c-4af5-4473-bbac-52984f0b2aa5)

  + Simulation:
    - `iverilog ternary_operator_mux.v tb_ternary_operator_mux.v`
    - `./a.out` : this will generate a .vcd file
    - `gtkwave tb_ternary_operator_mux.vcd` : this will give us the gtk wavform.
   
    ![gls2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/af9ea4fe-88cd-4b3d-b711-d7977e909b1a)

  + Synthesis:
    - Invoke `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog ternary_operator_mux.v`
    - `synth -top ternary_operator_mux`
   
    ![gls3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/84b6dde2-2a7f-4a19-8a76-30771b44fad3)

    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `write_verilog ternary_operator_mux_net.v`
    - `show`
   
    ![gls4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/6288d9d9-1d02-44d7-9886-3c6f786fa008)

  + GLS:
    - `iverilog /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/my_lib/verilog_model/primitives.v /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/my_lib/verilog_model/sky130_fd_sc_hd.v ternary_operator_mux_net.v tb_ternary_operator_mux.v`
    - `./a.out`
    - `gtkwave tb_ternary_operator_mux.vcd`

    ![gls5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/18e46b5b-74e6-47dd-9fb6-3ea3b8af066e)

* bad_mux
  + Opening the file: `gvim bad_mux.v`
 
  ![gls6](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/86f71c4c-d6eb-48f2-a5e9-eab5241e5c29)

  + Simulation:
    - `iverilog bad_mux.v tb_bad_mux.v`
    - `./a.out` : this will generate a .vcd file
    - `gtkwave tb_bad_mux.vcd` : this will give us the gtk wavform.
   
    ![gls7](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8b315fca-5c07-4916-b9bf-4b8ee7669271)

  + Synthesis:
    - Invoke `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog bad_mux.v`
    - `synth -top bad_mux`
   
    ![gls8](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8d293be1-b0dc-4619-ae03-37e189685621)

    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `write_verilog bad_mux_net.v`
    - `show`
   
    ![gls9](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8323a8dd-5964-4645-b68f-5d160157547f)

  + GLS:
    - `iverilog /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/my_lib/verilog_model/primitives.v /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/my_lib/verilog_model/sky130_fd_sc_hd.v bad_mux_net.v tb_bad_mux.v`
    - `./a.out`
    - `gtkwave tb_bad_mux.vcd`
   
    ![gls10](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/d6f28444-4346-4101-bd69-892c43427b93)

### Labs on synthesis-simulation mismatch for blocking statements:

* blocking_caveat
  + Opening the file: `gvim blocking_caveat.v`
 
  ![ss1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/32f2e835-e5ae-45f6-9e33-80b7933b2a10)

  + Simulation:
    - `iverilog blocking_caveat.v tb_blocking_caveat.v`
    - `./a.out` : this will generate a .vcd file
    - `gtkwave tb_blocking_caveat.vcd` : this will give us the gtk wavform.
   
    ![ss2](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/030f1034-cf00-4f26-871b-f524c867759a)

  + Synthesis:
    - Invoke `yosys`
    - `read_liberty -lib /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `read_verilog blocking_caveat.v`
    - `synth -top blocking_caveat`
   
    ![ss3](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/df18e921-ec94-4375-9eb9-4fdbc575f515)

    - `abc -liberty /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/lib/sky130_fd_sc_hd__tt_025C_1v80.lib`
    - `write_verilog blocking_caveat_net.v`
    - `show`
   
    ![ss4](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/7bb667ef-3a0a-4745-8c1a-bf8416e2ab5f)

  + GLS:
    - `iverilog /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/my_lib/verilog_model/primitives.v /home/nishita_joshi/VLSI/sky130RTLDesignAndSynthesisWorkshop/my_lib/verilog_model/sky130_fd_sc_hd.v blocking_caveat_net.v tb_blocking_caveat.v`
    - `./a.out`
    - `gtkwave tb_blocking_caveat.vcd`
   
    ![ss5](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/7dd54569-86f0-4bf4-b33b-40c2273e18ff)

</details>
