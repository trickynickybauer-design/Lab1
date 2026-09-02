#include <stdio.h>
#include <stdint.h>
#include "telemetry.h"

/* ========================================================================= */
/*                           STUDENT STUBS SECTION                          */
/* ========================================================================= */
/* Constraints Reminder:                                                     */
/* - NO loops, NO if/else conditionals, NO ternary operators (? :)          */
/* - NO struct bit-fields, NO pointer casting, NO unions                    */
/* - NO multiplication (*), division (/), or modulus (%)                    */
/* ========================================================================= */

uint32_t pack_telemetry(uint32_t sys_id, uint32_t flags, uint32_t voltage, int32_t temp) {
    /* TODO: Implement your bitwise packing code here */
    return 0;
}

int32_t unpack_temperature(uint32_t packet) {
    /* TODO: Extract 12-bit signed temp and properly sign-extend it to 32-bit */
    return 0;
}

uint32_t unpack_voltage(uint32_t packet) {
    /* TODO: Extract 10-bit unsigned battery voltage */
    return 0;
}

uint32_t unpack_flags(uint32_t packet) {
    /* TODO: Extract 6-bit error flags */
    return 0;
}

uint32_t unpack_sys_id(uint32_t packet) {
    /* TODO: Extract 4-bit sub-system ID */
    return 0;
}


/* ========================================================================= */
/*                             LOCAL TEST HARNESS                            */
/* ========================================================================= */
#ifndef AUTOGRADER
int main() {
    uint32_t sys_id  = 11;    
    uint32_t flags   = 42;    
    uint32_t voltage = 853;   
    int32_t  temp    = -512;  

    uint32_t packed_packet = pack_telemetry(sys_id, flags, voltage, temp);
    
    printf("--- Encoding Telemetry Packet ---\n");
    printf("Expected Pack hex: 0xBABC5E00\n");
    printf("Actual Pack hex:   0x%08X\n\n", packed_packet);

    printf("--- Decoding Telemetry Packet ---\n");
    printf("System ID:   Expected %u, Got %u\n", sys_id,  unpack_sys_id(packed_packet));
    printf("Flags:       Expected %u, Got %u\n", flags,   unpack_flags(packed_packet));
    printf("Voltage:     Expected %u, Got %u\n", voltage, unpack_voltage(packed_packet));
    printf("Temperature: Expected %d, Got %d\n", temp,    unpack_temperature(packed_packet));

    return 0;
}
#endif
