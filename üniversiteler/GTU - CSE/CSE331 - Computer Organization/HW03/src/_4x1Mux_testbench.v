`define DELAY 20
module _4x1Mux_testbench(); 
reg  a, b, c, d, s0, s1, enable;
wire res;

// FXMT stands for FourMuxTestbench
_4x1Mux FMXT(res, a, b, c, d, s0, s1, enable);

initial begin
a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0; s0 = 1'b1; s1 = 1'b1; enable = 1'b1;
#`DELAY;
a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b0; s0 = 1'b1; s1 = 1'b1; enable = 1'b0;
#`DELAY;
a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b0; s0 = 1'b1; s1 = 1'b0; enable = 1'b0;
#`DELAY;
a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b0; s0 = 1'b1; s1 = 1'b1; enable = 1'b1;
end
 
 
initial
begin
$monitor("4XMUX Test: time = %2d, result=%1b a =%1b, b =%1b,c =%1b, d =%1b, s0 =%1b, s1 =%1b, en =%1b", $time,res,a, b, c, d, s0, s1, enable);
end
 
endmodule