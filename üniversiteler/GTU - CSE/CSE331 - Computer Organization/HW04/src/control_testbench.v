`define DELAY 20
module control_testbench();

wire reg_dest, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
wire [2:0] alu_op;
reg [3:0] opcode;

control control_test(reg_dest, branch, mem_read, mem_to_reg, alu_op, mem_write, alu_src, reg_write, opcode);

initial begin

// r-type
opcode = 4'b0000;
#`DELAY;

// addi
opcode = 4'b0001;
#`DELAY;

// andi
opcode = 4'b0010;
#`DELAY;

// ori
opcode = 4'b0011;
#`DELAY;

// nori
opcode = 4'b0100;
#`DELAY;

// beq
opcode = 4'b0101;
#`DELAY;

// bne
opcode = 4'b0110;
#`DELAY;

// slti
opcode = 4'b0111;
#`DELAY;

// lw
opcode = 4'b1000;
#`DELAY;

// sw
opcode = 4'b1001;

end

initial begin
$monitor("time=%2d,opcode=%4b, alu_op=%3b\n reg_dest=%1b, branch=%1b, mem_read=%1b, mem_to_reg=%1b, mem_wrt=%1b, alu_src=%1b, reg_wrt=%1b" ,$time, opcode, alu_op, reg_dest, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write);
end

endmodule