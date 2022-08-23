`define DELAY 20
module _32bit_xor_testbench();
reg [31:0] a, b;
wire [31:0] res;

// XOT stands for xor testbench
_32bit_xor XOT(res, a, b);

initial begin
a = 32'hFFFFFFFF; b = 32'hFFFFFFFF;
#`DELAY;
a = 32'h05453FAF; b = 32'h00000001;
#`DELAY;
a = 32'h00000000; b = 32'h00000001;
#`DELAY;
a = 32'h00000000; b = 32'hFFFFFFFF;
end

initial
begin
$monitor("XOR: time = %2d, a =%8h, b=%8h, result=%8h", $time, a, b, res);
end
 
endmodule