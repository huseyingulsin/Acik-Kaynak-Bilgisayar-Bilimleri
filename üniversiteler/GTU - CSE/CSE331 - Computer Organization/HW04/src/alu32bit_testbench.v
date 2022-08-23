`define DELAY 20
module alu32bit_testbench();
reg [31:0] a, b;
reg s0, s1, s2;
wire [31:0] res;

// ALUT stands for alu testbench
alu32bit ALUT(res, a, b, s0, s1, s2);

initial begin
// test or 111
a = 32'h05453FAF; b = 32'h00000001; s0 = 1; s1 = 1; s2 = 1;
#`DELAY;
a = 32'h0000FFFF; b = 32'h0; s0 = 1; s1 = 1; s2 = 1;
#`DELAY;
// teat nor 101
a = 32'h05453FAF; b = 32'hFFFFFFFF; s0 = 1; s1 = 0; s2 = 1;
#`DELAY;
a = 32'h0000FFFF; b = 32'h0000A541; s0 = 1; s1 = 0; s2 = 1;
#`DELAY;
// test mult 011 
// --
// test xor 001
a = 32'h05453FAF; b = 32'hFFFFFFFF; s0 = 0; s1 = 0; s2 = 1;
#`DELAY;
a = 32'h0000FFFF; b = 32'h0000A541; s0 = 0; s1 = 0; s2 = 1;
#`DELAY;
// test and 110
a = 32'h05453FAF; b = 32'h12441511; s0 = 1; s1 = 1; s2 = 0;
#`DELAY;
a = 32'h0000FFFF; b = 32'h0; s0 = 1; s1 = 1; s2 = 0;
#`DELAY;
// test SLT 100
a = 32'h00001010; b = 32'h00AA5100; s0 = 1; s1 = 0; s2 = 0;
#`DELAY;
a = 32'h0000FFFF; b = 32'h0; s0 = 1; s1 = 0; s2 = 0;
#`DELAY;
// test SUB 010
a = 32'h05453FAF; b = 32'h00100100; s0 = 0; s1 = 1; s2 = 0;
#`DELAY;
a = 32'h0000FFFF; b = 32'h00001111; s0 = 0; s1 = 1; s2 = 0;
#`DELAY;
// test ADD 000
a = 32'h00453FAF; b = 32'h00000011; s0 = 0; s1 = 0; s2 = 0;
#`DELAY;
a = 32'h0000FFFF; b = 32'h0; s0 = 0; s1 = 0; s2 = 0;
end

initial
begin
$monitor("ALU RESULTS: time = %2d, res = %8h, a =%8h, b= %8h, s0= %1b, s1= %1b, s2= %1b", $time,res, a, b, s0, s1, s2);
end
 

endmodule