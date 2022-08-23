`define DELAY 20
module alu_control_testbench();

wire [2:0] alu_output;
reg [2:0] func, alu_op;

alu_control alu_control_test(alu_output, func, alu_op);

initial begin

// r_type instructions
alu_op = 3'b010; // this stiuation is only happens when r_types

func = 3'b000; // and
#`DELAY;
func = 3'b001; // add
#`DELAY;
func = 3'b010; // sub
#`DELAY;
func = 3'b011; // xor
#`DELAY;
func = 3'b100; // nor
#`DELAY;
func = 3'b101; // or
#`DELAY;

// for remaining ones, function filed is not matter
func = 3'b000;

// i_type instructions
// i_type instructions alu_op starts with 1
alu_op = 3'b111; // addi
#`DELAY;
alu_op = 3'b110; // andi
#`DELAY;
alu_op = 3'b101; // ori
#`DELAY;
alu_op = 3'b100; // nori

#`DELAY;
// beq, bne, slti, sw, lw
// for those instructions, alu_op starts with 0
alu_op = 3'b011; // beq
#`DELAY;
alu_op = 3'b001; // bne
#`DELAY;
alu_op = 3'b001; // slti
#`DELAY;
alu_op = 3'b000; // sw
#`DELAY;
alu_op = 3'b000; // lw

end

initial begin
$monitor("time=%2d, alu_op=%3b, function=%3b, alu_output=%3b",$time, alu_op, func, alu_output);
end


endmodule