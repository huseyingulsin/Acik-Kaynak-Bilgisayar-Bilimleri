`define DELAY 20
module _32bit_and_testbench();
reg [31:0] a, b;
wire [31:0] res;

// AT stands for and testbench
_32bit_and AT(res, a, b);

initial begin
a = 32'hFFFFFFFF; b = 32'hFFFFFFFF;
#`DELAY;
a = 32'h05453FAF; b = 32'h00000001;
#`DELAY;
a = 32'h00000001; b = 32'h00000001;
#`DELAY;
a = 32'h00000000; b = 32'hFFFFFFFF;
#`DELAY;
a = 32'h05453FAF; b = 32'h12441511;
#`DELAY;
a = 32'h0000FFFF; b = 32'h0;
end

initial
begin
$monitor("time = %2d, a =%8h, b=%8h, result=%8h", $time, a, b, res);
end
 
endmodule