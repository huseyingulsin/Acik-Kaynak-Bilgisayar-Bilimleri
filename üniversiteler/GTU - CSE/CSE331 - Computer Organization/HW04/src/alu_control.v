module alu_control(alu_output, func, alu_op);

output [2:0] alu_output;
input [2:0] func, alu_op;

wire [2:0] alu_op_not, func_not;
wire r_and, r_add, r_sub, r_xor, r_nor, r_or;
wire addi, andi, ori, nori, beq, bne, slti, lw, sw;
wire r_type, r_type_not;

// take not of alu_op
not alu_op_not0(alu_op_not[0], alu_op[0]);
not alu_op_not1(alu_op_not[1], alu_op[1]);
not alu_op_not2(alu_op_not[2], alu_op[2]);

// take not of func
not func_not0(func_not[0], func[0]);
not func_not1(func_not[1], func[1]);
not func_not2(func_not[2], func[2]);

// determine r_type
// r_type -> Alu_OP = 010
and is_r_type(r_type, alu_op_not[2], alu_op[1], alu_op_not[0]);
not not_r_type(r_type_not, r_type);

// determine r_type instructions
// r_and -> Func = 000
and is_r_and(r_and, r_type, func_not[2], func_not[1], func_not[0]);
// r_add -> Func = 001
and is_r_add(r_add, r_type, func_not[2], func_not[1], func[0]);
// r_sub -> Func = 010
and is_r_sub(r_sub, r_type, func_not[2], func[1], func_not[0]);
// r_xor -> Func = 011
and is_r_xor(r_xor, r_type, func_not[2], func[1], func[0]);
// r_nor -> Func = 100
and is_r_nor(r_nor, r_type, func[2], func_not[1], func_not[0]);
// r_or -> Func = 101
and is_r_or(r_or, r_type, func[2], func_not[1], func[0]);

// determine i type instructions
// addi -> ALU_OP = 111
and is_addi(addi, r_type_not, alu_op[2], alu_op[1], alu_op[0]);
// andi -> ALU_OP = 110
and is_andi(andi, r_type_not, alu_op[2], alu_op[1], alu_op_not[0]);
// ori -> ALU_OP = 101
and is_ori(ori, r_type_not, alu_op[2], alu_op_not[1], alu_op[0]);
// nori -> ALU_OP = 100
and is_nori(nori, r_type_not, alu_op[2], alu_op_not[1], alu_op_not[0]);

// determine slti, bne, beq, lw, sw
// SLTI -> ALU_OP = 001
and is_slti(slti, r_type_not, alu_op_not[2], alu_op_not[1], alu_op[0]);
// BNE || BEQ -> ALU_OP = 011
and is_beq(beq, r_type_not, alu_op_not[2], alu_op[1], alu_op[0]);
and is_bne(bne, beq, 1'b1);
// LW -> ALU_OP = 000 and SW -> ALU_OP = 000
and is_lw(lw, r_type_not, alu_op_not[2], alu_op_not[1], alu_op_not[0]);
and is_sw(sw, lw, 1'b1);

// assign alu_output
// ALU_OP[2] is true when and, nor, or, andi, ori, nori, slti is true
or alu_output2(alu_output[2], r_and, r_nor, r_or, andi, ori, nori, slti, 1'b0);
// ALU_OP[1] is true when and, sub, or, andi, ori, beq, bne is true
or alu_output1(alu_output[1], r_and, r_sub, r_or, andi, ori, beq, bne, 1'b0);
// ALU_OP[0] is true when xor, nor, or, nori, ori, beq, bne is true
or alu_output0(alu_output[0], r_xor, r_nor, r_or, nori, ori, beq, bne, 1'b0);


endmodule