# Lab 1: The Satellite Telemetry Packer 

## 1. Introduction
In real-world computer systems, hardware interfaces, embedded devices, and network protocols rarely organize data into clean 32-bit or 64-bit boundaries. To save bandwidth and storage space, multiple distinct metrics are often "packed" tightly into a single bitstream. 

In this lab, you will write a low-level C library to pack and unpack variable-width fields for an orbital satellite telemetry packet. This lab will build your intuition for bitwise arithmetic, masking, and machine-level data representations (especially Two's Complement sign extension).

## 2. Packet Architecture & Bit Layout
Your program will work with a unified 32-bit package (`uint32_t`). The data fields must be organized exactly according to the layout below. 

* **Bits 31–28 (4 bits):** Sub-System ID (Unsigned integer, range: 0 to 15)
* **Bits 27–22 (6 bits):** Status/Error Flags (Bitmask, range: 0 to 63)
* **Bits 21–12 (10 bits):** Battery Voltage (Unsigned integer, range: 0 to 1023)
* **Bits 11–0 (12 bits):** Temperature Reading (Signed Two's Complement integer, range: -2048 to +2047)

```text
 31      28 27    22 21          12 11                        0
+----------+--------+--------------+--------------------------+
|  Sys ID  | Flags  |   Voltage    |       Temperature        |
|  4 bits  | 6 bits |   10 bits    |         12 bits          |
+----------+--------+--------------+--------------------------+
```

## 3. Your Tasks
You must implement the following 5 functions inside `telemetry.c`:

1. `uint32_t pack_telemetry(uint32_t sys_id, uint32_t flags, uint32_t voltage, int32_t temp)`
   * Cleans each input argument to ensure it does not overflow its boundary.
   * Shifts and merges the fields into a single 32-bit integer payload.
2. `uint32_t unpack_sys_id(uint32_t packet)`
   * Extracts and returns the 4-bit Sub-System ID.
3. `uint32_t unpack_flags(uint32_t packet)`
   * Extracts and returns the 6-bit Status/Error flags.
4. `uint32_t unpack_voltage(uint32_t packet)`
   * Extracts and returns the 10-bit Battery Voltage.
5. `int32_t unpack_temperature(uint32_t packet)`
   * Extracts the 12-bit Temperature.
   * **Critical:** Because temperature is a signed 12-bit value embedded inside a 32-bit machine register, you must manually perform sign extension so that negative temperatures preserve their sign mathematically as a 32-bit `int32_t`.

## 4. Strict Coding Constraints
To ensure you learn the true mechanics of memory and processor operations, you must adhere to strict bit-level restrictions. Violating these constraints will result in a zero for the function, even if the output is correct.

* **No Control Flow:** You are strictly forbidden from using `if`, `else`, `switch`, `for`, `while`, or the ternary operator (`? :`). Your operations must be purely algorithmic.
* **No Macro Arithmetic:** You cannot use multiplication (`*`), division (`/`), or modulus (`%`). 
* **No Memory Magic:** You cannot use structural bit-fields (`struct`), pointers to cast memory types, or `union` wrappers to overlay the bits. 
* **Allowed Operations:** You may only use the bitwise operators (`&`, `|`, `^`, `~`, `<<`, `>>`) and standard integer addition or subtraction (`+`, `-`).

## 5. Compilation & Testing
To compile and execute your test suite, execute the following commands in your terminal:

```bash
gcc -Wall -Wextra -O0 telemetry.c -o telemetry
./telemetry
```

Ensure your implementation passes all assertions in the test harness without producing compilation warnings.

## 6. Submission
Once you complete your code, download it from GitHub and then upload it to the Lab 1 Canvas assignment. I will only grade whatever is submitted to Canvas.
