module control(reg_dest, branch, mem_read, mem_to_reg, alu_op, mem_write, alu_src, reg_write, opcode);

output reg_dest, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
output [2:0] alu_op;
input [3:0] opcode;

// used as temp values to determine situations
wire [3:0] opcode_not;
wire r_type, i_type, lw, sw, bne, beq, not_reg_write;
wire addi, andi, ori, nori, slti;

// take not of opcode
not opcode_not0(opcode_not[0], opcode[0]);
not opcode_not1(opcode_not[1], opcode[1]);
not opcode_not2(opcode_not[2], opcode[2]);
not opcode_not3(opcode_not[3], opcode[3]);

// if opcode_not all values is 1, r_type is true
and is_r_type(r_type, opcode_not[0], opcode_not[1], opcode_not[2], opcode_not[3]);



// operation detections

// ADDI -> OPCODE 0001
and is_addi(addi, opcode_not[3], opcode_not[2], opcode_not[1], opcode[0]);
// ANDI -> OPCODE 0010
and is_andi(andi, opcode_not[3], opcode_not[2], opcode[1], opcode_not[0]);
// ORI -> OPCODE 0011
and is_ori(ori, opcode_not[3], opcode_not[2], opcode[1], opcode[0]);
// NORI -> OPCODE 0100
and is_nori(nori, opcode_not[3], opcode[2], opcode_not[1], opcode_not[0]);
// BEQ -> OPCODE 0101
and is_beq(beq, opcode_not[3], opcode[2], opcode_not[1], opcode[0]);
// BNE -> OPCODE 0110
and is_bne(bne, opcode_not[3], opcode[2], opcode[1], opcode_not[0]);
// SLTI -> OPCODE 0111
and is_slti(slti, opcode_not[3], opcode[2], opcode[1], opcode[0]);
// LW -> OPCODE 1000
and is_lw(lw, opcode[3], opcode_not[2], opcode_not[1], opcode_not[0]);
// SW -> OPCODE 1001
and is_sw(sw, opcode[3], opcode_not[2], opcode_not[1], opcode[0]);


// alu-op detections

// one of them is true, it means i-type
or is_i_type(i_type, addi, andi, ori, nori);
// alu_op[2] is only true when i_type is true
and alu_op2(alu_op[2], i_type, 1'b1);
or alu_op1(alu_op[1], r_type, addi, andi, beq, bne);
or alu_op0(alu_op[0], addi, ori, slti, beq, bne);

// if r_type is 1, reg_dest is true
and is_reg_dest(reg_dest, r_type);
// branch is true when bne or beq is true
or is_branch(branch, bne, beq);
// mem_read is true when lw is true
and is_mem_read(mem_read, lw, 1'b1);
// mem_to_reg is true when lw is true
and is_mem_to_reg(mem_to_reg, lw, 1'b1);
// mem_write is true when sw is true
and is_mem_write(mem_write, sw, 1'b1);
// if r_type is 0, aluSrc is true
not is_alu_src(alu_src, r_type);
// reg_write is true when a operation is true rather than beq, bne or sw
or is_reg_write(reg_write, r_type, addi, andi, ori, nori, slti, lw);



endmodule