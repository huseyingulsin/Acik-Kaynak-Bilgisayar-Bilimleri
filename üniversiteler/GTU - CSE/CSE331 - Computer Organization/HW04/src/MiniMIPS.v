module MiniMIPS(alu_result, instruction, clk);


// only recieves clk as input.
output [31:0] alu_result;
input [15:0] instruction;
input clk;


// ! since I giving instruction as input, it is not necessray to use instruction memory
// assigned at instruction memory
// wire [15:0] instruction;


// assigned at split_instruction
wire [3:0] opcode;
wire [2:0] rs, rt, rd, func;
wire [5:0] imm;
// assigned at control datapath
wire reg_dest, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
wire [2:0] alu_op;
// assigned at alu control
wire [2:0] alu_ctrl;
// assigned at sign_extend
wire [31:0] extended_imm;
// assigned at alu
// wire [31:0] alu_result;
// assigned at reg
wire [31:0] read_data1, read_data2;


reg [15:0] pc = 15'b0;

// ! since I giving instruction as input, it is not necessray to use instruction memory
// instruction_memory im(instruction, pc, clk);

split_instruction split(opcode, rs, rt, rd, func, imm, instruction);

control ctrl(reg_dest, branch, mem_read, mem_to_reg, alu_op, mem_write, alu_src, reg_write, opcode);

alu_control aluctrl(alu_ctrl, alu_op, func);

sign_extend signext(extended_imm, imm);

// read_data1, read_data2, write_data, read_reg1, read_reg2, write_reg, reg_write, clk
register regist(read_data1, read_data2, alu_result, rs, rt, rd, reg_write, clk);

alu32bit alu(alu_result, read_data1, read_data2, alu_ctrl[2], alu_ctrl[1], alu_ctrl[0]);


always @(negedge clk) begin
    // increment pc by 1 for every clck
    pc <= pc + 4'b0001;
end



endmodule