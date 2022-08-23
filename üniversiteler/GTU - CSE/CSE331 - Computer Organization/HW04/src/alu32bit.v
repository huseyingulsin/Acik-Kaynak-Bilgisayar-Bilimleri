// those constants are used in some places
`define ZERO 1'b0
`define ZERO_32BITS 32'b0 
`define ONE 1'b1
`define ONE_32BITS 32'b1
`define FFFF 32'hFFFFFFFF

module alu32bit(res, a, b, s0, s1, s2);
input [31:0] a, b;
input s0, s1, s2;
output [31:0] res;
// operations
wire [31:0] add_RES, xor_RES, sub_RES, mult_RES, slt_RES, nor_RES, and_RES, or_RES;
// temp 32 bit variables to calculate sub and less than
wire [31:0] ones_complement, twos_complement;
// temp variables to use some cases
wire carry_out_sum, carry_out_sub, carry_out_slt, slt_helper, twos_comploment_carry_out, mult_garbage;

// add operation
_32bit_adder add_func(add_RES, carry_out_sum, a, b, 1'b0);

// xor operation
_32bit_xor xor_func(xor_RES, a, b);

// sub operation
// first take ones_complement of second param (b)
_32bit_xor ones_complement_func(ones_complement, b, 32'hFFFFFFFF);
// then take twos_complement of ones_complement
_32bit_adder twos_complement_func(twos_complement, twos_comploment_carry_out, ones_complement, 32'b1, 1'b0);
// it is now negative, than add them together
_32bit_adder sub_func(sub_RES, carry_out_sub, twos_complement, a, 1'b0);

// mult operation
// not implemnted, so I used adder
_32bit_adder mult_func(mult_RES, mult_garbage, a, b);

// slt operation
// first take most significant bit of sub_RES 
and(slt_helper, sub_RES[31], 1'b1);
// then use adder to calculate
_32bit_adder slt_func(slt_RES, carry_out_slt, 32'b0, 32'b0, slt_helper);

// nor operation
_32bit_nor nor_func(nor_RES, a, b);

// and operation
_32bit_and and_func(and_RES, a, b);

// or operation
_32bit_or or_func(or_RES, a, b);

// finally use 8x1Mux to decide which operation to use

// this lines are a bit hardcoded but I don't know how to do it better
_8x1Mux mux0 (res[0], or_RES[0], nor_RES[0], mult_RES[0], xor_RES[0], and_RES[0], slt_RES[0], sub_RES[0], add_RES[0], s0, s1, s2);
_8x1Mux mux1 (res[1], or_RES[1], nor_RES[1], mult_RES[1], xor_RES[1], and_RES[1], slt_RES[1], sub_RES[1], add_RES[1], s0, s1, s2);
_8x1Mux mux2 (res[2], or_RES[2], nor_RES[2], mult_RES[2], xor_RES[2], and_RES[2], slt_RES[2], sub_RES[2], add_RES[2], s0, s1, s2);
_8x1Mux mux3 (res[3], or_RES[3], nor_RES[3], mult_RES[3], xor_RES[3], and_RES[3], slt_RES[3], sub_RES[3], add_RES[3], s0, s1, s2);
_8x1Mux mux4 (res[4], or_RES[4], nor_RES[4], mult_RES[4], xor_RES[4], and_RES[4], slt_RES[4], sub_RES[4], add_RES[4], s0, s1, s2);
_8x1Mux mux5 (res[5], or_RES[5], nor_RES[5], mult_RES[5], xor_RES[5], and_RES[5], slt_RES[5], sub_RES[5], add_RES[5], s0, s1, s2);
_8x1Mux mux6 (res[6], or_RES[6], nor_RES[6], mult_RES[6], xor_RES[6], and_RES[6], slt_RES[6], sub_RES[6], add_RES[6], s0, s1, s2);
_8x1Mux mux7 (res[7], or_RES[7], nor_RES[7], mult_RES[7], xor_RES[7], and_RES[7], slt_RES[7], sub_RES[7], add_RES[7], s0, s1, s2);
_8x1Mux mux8 (res[8], or_RES[8], nor_RES[8], mult_RES[8], xor_RES[8], and_RES[8], slt_RES[8], sub_RES[8], add_RES[8], s0, s1, s2);
_8x1Mux mux9 (res[9], or_RES[9], nor_RES[9], mult_RES[9], xor_RES[9], and_RES[9], slt_RES[9], sub_RES[9], add_RES[9], s0, s1, s2);
_8x1Mux mux10 (res[10], or_RES[10], nor_RES[10], mult_RES[10], xor_RES[10], and_RES[10], slt_RES[10], sub_RES[10], add_RES[10], s0, s1, s2);
_8x1Mux mux11 (res[11], or_RES[11], nor_RES[11], mult_RES[11], xor_RES[11], and_RES[11], slt_RES[11], sub_RES[11], add_RES[11], s0, s1, s2);
_8x1Mux mux12 (res[12], or_RES[12], nor_RES[12], mult_RES[12], xor_RES[12], and_RES[12], slt_RES[12], sub_RES[12], add_RES[12], s0, s1, s2);
_8x1Mux mux13 (res[13], or_RES[13], nor_RES[13], mult_RES[13], xor_RES[13], and_RES[13], slt_RES[13], sub_RES[13], add_RES[13], s0, s1, s2);
_8x1Mux mux14 (res[14], or_RES[14], nor_RES[14], mult_RES[14], xor_RES[14], and_RES[14], slt_RES[14], sub_RES[14], add_RES[14], s0, s1, s2);
_8x1Mux mux15 (res[15], or_RES[15], nor_RES[15], mult_RES[15], xor_RES[15], and_RES[15], slt_RES[15], sub_RES[15], add_RES[15], s0, s1, s2);
_8x1Mux mux16 (res[16], or_RES[16], nor_RES[16], mult_RES[16], xor_RES[16], and_RES[16], slt_RES[16], sub_RES[16], add_RES[16], s0, s1, s2);
_8x1Mux mux17 (res[17], or_RES[17], nor_RES[17], mult_RES[17], xor_RES[17], and_RES[17], slt_RES[17], sub_RES[17], add_RES[17], s0, s1, s2);
_8x1Mux mux18 (res[18], or_RES[18], nor_RES[18], mult_RES[18], xor_RES[18], and_RES[18], slt_RES[18], sub_RES[18], add_RES[18], s0, s1, s2);
_8x1Mux mux19 (res[19], or_RES[19], nor_RES[19], mult_RES[19], xor_RES[19], and_RES[19], slt_RES[19], sub_RES[19], add_RES[19], s0, s1, s2);
_8x1Mux mux20 (res[20], or_RES[20], nor_RES[20], mult_RES[20], xor_RES[20], and_RES[20], slt_RES[20], sub_RES[20], add_RES[20], s0, s1, s2);
_8x1Mux mux21 (res[21], or_RES[21], nor_RES[21], mult_RES[21], xor_RES[21], and_RES[21], slt_RES[21], sub_RES[21], add_RES[21], s0, s1, s2);
_8x1Mux mux22 (res[22], or_RES[22], nor_RES[22], mult_RES[22], xor_RES[22], and_RES[22], slt_RES[22], sub_RES[22], add_RES[22], s0, s1, s2);
_8x1Mux mux23 (res[23], or_RES[23], nor_RES[23], mult_RES[23], xor_RES[23], and_RES[23], slt_RES[23], sub_RES[23], add_RES[23], s0, s1, s2);
_8x1Mux mux24 (res[24], or_RES[24], nor_RES[24], mult_RES[24], xor_RES[24], and_RES[24], slt_RES[24], sub_RES[24], add_RES[24], s0, s1, s2);
_8x1Mux mux25 (res[25], or_RES[25], nor_RES[25], mult_RES[25], xor_RES[25], and_RES[25], slt_RES[25], sub_RES[25], add_RES[25], s0, s1, s2);
_8x1Mux mux26 (res[26], or_RES[26], nor_RES[26], mult_RES[26], xor_RES[26], and_RES[26], slt_RES[26], sub_RES[26], add_RES[26], s0, s1, s2);
_8x1Mux mux27 (res[27], or_RES[27], nor_RES[27], mult_RES[27], xor_RES[27], and_RES[27], slt_RES[27], sub_RES[27], add_RES[27], s0, s1, s2);
_8x1Mux mux28 (res[28], or_RES[28], nor_RES[28], mult_RES[28], xor_RES[28], and_RES[28], slt_RES[28], sub_RES[28], add_RES[28], s0, s1, s2);
_8x1Mux mux29 (res[29], or_RES[29], nor_RES[29], mult_RES[29], xor_RES[29], and_RES[29], slt_RES[29], sub_RES[29], add_RES[29], s0, s1, s2);
_8x1Mux mux30 (res[30], or_RES[30], nor_RES[30], mult_RES[30], xor_RES[30], and_RES[30], slt_RES[30], sub_RES[30], add_RES[30], s0, s1, s2);
_8x1Mux mux31 (res[31], or_RES[31], nor_RES[31], mult_RES[31], xor_RES[31], and_RES[31], slt_RES[31], sub_RES[31], add_RES[31], s0, s1, s2);

endmodule