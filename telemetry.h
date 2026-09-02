#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <stdint.h>

/*
 * Bit Layout Specification (32-bit packet):
 * Bits 31-28: Sub-System ID (4 bits, unsigned)
 * Bits 27-22: Error Flags    (6 bits, bitmask)
 * Bits 21-12: Battery Voltage(10 bits, unsigned)
 * Bits 11-0 : Temperature    (12 bits, signed two's complement)
 */

/* Student Functions */
uint32_t pack_telemetry(uint32_t sys_id, uint32_t flags, uint32_t voltage, int32_t temp);
int32_t  unpack_temperature(uint32_t packet);
uint32_t unpack_voltage(uint32_t packet);
uint32_t unpack_flags(uint32_t packet);
uint32_t unpack_sys_id(uint32_t packet);

#endif /* TELEMETRY_H */
