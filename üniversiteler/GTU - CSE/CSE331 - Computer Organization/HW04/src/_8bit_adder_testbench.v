`define DELAY 20
module _8bit_adder_testbench();
reg [7:0] a, b;
reg carry_in;
wire [7:0] sum;
wire carry_out;

_8bit_adder EAT(sum, carry_out, a, b, carry_in);

initial begin
a = 8'h00; b = 8'h00; carry_in = 1'b0;
#`DELAY;
a = 8'h01; b = 8'h00; carry_in = 1'b0;
#`DELAY;
a = 8'h05; b = 8'h41; carry_in = 1'b1;
end

initial
begin
$monitor("time = %2d, a =%2h, b=%2h, carry_in=%1b, sum=%2h, carry_out=%1b", $time, a, b, carry_in, sum, carry_out);
end
 
endmodule