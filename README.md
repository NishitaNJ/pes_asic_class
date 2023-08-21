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
#### Important Abbreviations:
* ISA - Instruction Set Architecture
* HDL - Hardware Description Language
* ABI - Application Binary Interface
* LUI - Load Upper Immediate
* ADDI - Add Immediate
* MSB - Most Significant Bit
* LSB - Least Significant Bit

<details>

<summary>DAY1 - Introduction to RISC-V ISA and GNU compiler toolchain</summary>
<details>
  <summary>SK2</summary>
  <details>
    <summary>LAB1</summary>  
  
Write a C program to calculate sum of numbers from 1 to n.

* **Compiling using C**

![lab1](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/dc061fd3-aa77-43b7-a895-ec8ad269d913)

leafpad - It is a simple open source text editor fot Linux similar to Notepad in Windows

![sumncode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/da0e7ecf-0612-4790-b80f-cfb5616e346a)

  </details>
<details>
  <summary>LAB2</summary>
  
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

</details>
<details>
  <summary>LAB3</summary>
  
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
</details>
<details>
  <summary>SK3</summary>
  <details>
    <summary>LAB1</summary>
  
* **64-bit Number System for Unsigned Numbers:**
  + In this session we learn about conversion from decimal to binary representation.
  + In terms of RISC-V, the entire 64-bit number is called DOUBLEWORD.
  + 8bits -> byte ; 4bytes -> word ; 8bytes or 2words -> Doubleword
  + RISC-V doubleword can represent '0' to '(2<sup>64</sup> -1)' unsigned numbers or positive numbers.
</details>
<details>
  <summary>LAB2</summary>

* **64-bit Number System for Signed Numbers:**
  + Representing negative numbers using two's compliment representation.
  + Representation:
    - First write the number in its binary form
    - find the two's compliment of this number by inverting it and adding 1 to it.
    - you will get the required result.
  + For positive numbers, MSB - '0'
  + For negative numbers, MSB - '1'
  + Positive numbers range from '0' to '(2<sup>63</sup> -1)'
  + Negative numbers range from '-1' to '(-2<sup>63</sup>)'
  + Instructions which operate on these numbers are called Base Integer Instructions (RV64I)
</details>

<details>
  <summary>LAB3</summary>
  
* **Getting the highest unsigned number:**

![highestunsign](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/8d1aee5d-24fe-4d5e-8d05-b1f7d07697af)

`vim unsigned.c` 
This command opens the vim text editor to create a file named unsigned.c for editing.

`riscv64-unknown-elf-gcc -Ofast -mabt=lp64 -march=rv64t -o unsigned.o unsigned.c`
This command compiles the source file using the RISC-V GCC Compiler.

![unsigncode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/2ec49af7-268a-46b2-9cd1-fabca10b5afc)

In this code:
  + We use the 'pow' function from the 'math.h' library to calculate the maximum values for unsigned long long int.
  + `unsigned long long int` is a data type in the C programming language that represents an integer value with extended range and no sign.
  + llu: The llu portion indicates that the argument provided to the function is an unsigned long long int. The l signifies a long integer, and lu indicates that it's an unsigned long integer.

* **Verifying if it is the highest unsigned number value:**

For verifying this we give a number higher than 64bit. Here in this example we are considering 125.

![high64code](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a4a0718f-57e0-4d8f-9960-30452289746b)

![high64](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/36224727-516a-45df-92fc-911f6861aa2c)

We are using `spike pk unsigned.c` for simulation.
  From the results we can observe that we are getting the same value as the previous example of 64bit. Hence it is the highest number.

* **To check for a value lesser than 64bits:**

![low64code](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/a499670c-2651-486e-bac2-2d290694ec35)

  + To verify this we have considered a value lesser than 64bit. Here in this example it is 20.

![low64](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/bd771093-a521-4b48-bcc2-98e7fdf0af7c)

From the obtained result it satisfies that for an unsigned number or positive number if the value is greater than 64 still we get the max value of 64bits only and not higher than that. And for a value less than 64 we get the required result.

* **Checking for unsigned numbers:**

![checkcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/2d4bf0bb-7da8-4a4e-9a11-b528652fcfa9)

To check the range of unsigned number we are multiplying it with (-1). `unsigned long long int max = (unsigned long long int)(pow(2, 20) *- 1);`

![check](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9944d42f-4fc2-48b9-8ee3-6faef3939b86)

We are getting a output as 0 because it is not displaying negative numbers.
  Hence from this we can verify that the range of Unsigned numbers is from '0' to '(2<sup>63</sup> -1)'

* **How to get a negative number:**

To get a negative number remove the term unsigned from the instructions.

![negcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/6a59bcfa-9662-43f8-a3dc-d3a7cd0c9122)

![neg](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/9a301dca-2686-4465-bbc3-abf877b5f80d)

Hence from the output we can observe that we are getting a negative result.

* **Getting the highest and lowest signed numbers:**

![signedcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/4871e00a-533d-4e49-b24c-bb7c06ac876d)

  + lld: The lld portion indicates that the argument provided to the function is a long long int. The l signifies a long integer, and ld indicates that it's a signed long integer.

![signed](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/16c3445e-c0e5-462d-af9e-736e60555415)

+ From this output we can observe that we are not getting the exact highest and lowest values of signed number.
+ Using `(int)(pow(2, 63) * -1)`:
  In this approach, we are calculating the negative value by multiplying -1 with the result of pow(2, 63). However, this calculation involves floating-point arithmetic, which can lead to imprecise results for very large integers due to the limitations of floating-point representation. This can result in incorrect values, especially when dealing with large exponents like 2<sup>63</sup>.

* **Debugging the above code:**

![correctcode](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/f2782b40-cfd3-4659-850f-af0c91b6287f)

  + Using `(int)(-pow(2, 63))`:
  In this approach, we are directly calculating the negative value by using the '-' operator with the result of pow(2, 63). While this also involves     floating-point arithmetic, the '-' operation is applied after the pow function calculates the result.

![correctsign](https://github.com/NishitaNJ/pes_asic_class/assets/142140741/e36d8e8a-5351-485b-a3c3-c8faddaef8e0)

Hence by correcting the previous code we obtained the required result. i.e. the highest and lowest values of signed numbers.

</details>
</details>
</details>






