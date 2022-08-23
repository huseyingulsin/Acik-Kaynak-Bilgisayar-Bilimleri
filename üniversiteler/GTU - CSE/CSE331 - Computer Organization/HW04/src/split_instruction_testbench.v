`define DELAY 20
module split_instruction_testbench();

wire [3:0] opcode;
wire [2:0] rs, rt, rd, func;
wire [5:0] imm;
reg [15:0] instruction;

split_instruction split_test(opcode, rs, rt, rd, func, imm, instruction);

initial begin
  
//  
instruction = 16'b0110_0001_1101_0011;
#`DELAY;
instruction = 16'b0100_1001_0101_1011;
#`DELAY;
instruction = 16'b1111_1001_1100_0111;
#`DELAY;
instruction = 16'b1111_1111_1111_1111;
#`DELAY;
instruction = 16'b0000_0000_0000_0000;

end

initial begin
$monitor("time=%2d, instruction=%16b,  opcode=%4b,  rs=%3b,  rt=%3b,  rd=%3b,  function=%3b,  immediate=%6b"
            ,$time, instruction, opcode, rs, rt, rd, func, imm);
end



endmodule