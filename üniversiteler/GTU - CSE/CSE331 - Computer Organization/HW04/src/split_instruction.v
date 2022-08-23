module split_instruction(opcode, rs, rt, rd, func, imm, instruction);

output [3:0] opcode;
output [2:0] rs, rt, rd, func;
output [5:0] imm;
input [15:0] instruction;

// first determiine opcode
and opcode0(opcode[3], instruction[15], 1'b1);
and opcode1(opcode[2], instruction[14], 1'b1);
and opcode2(opcode[1], instruction[13], 1'b1);
and opcode3(opcode[0], instruction[12], 1'b1);

// determine rs
and rs0(rs[2], instruction[11], 1'b1);
and rs1(rs[1], instruction[10], 1'b1);
and rs2(rs[0], instruction[9], 1'b1);

// determine rt
and rt0(rt[2], instruction[8], 1'b1);
and rt1(rt[1], instruction[7], 1'b1);
and rt2(rt[0], instruction[6], 1'b1);

// determine rd
and rd0(rd[2], instruction[5], 1'b1);
and rd1(rd[1], instruction[4], 1'b1);
and rd2(rd[0], instruction[3], 1'b1);

// determine func
and func0(func[2], instruction[2], 1'b1);
and func1(func[1], instruction[1], 1'b1);
and func2(func[0], instruction[0], 1'b1);

// determine imm
and imm0(imm[5], instruction[5], 1'b1);
and imm1(imm[4], instruction[4], 1'b1);
and imm2(imm[3], instruction[3], 1'b1);
and imm3(imm[2], instruction[2], 1'b1);
and imm4(imm[1], instruction[1], 1'b1);
and imm5(imm[0], instruction[0], 1'b1);


endmodule