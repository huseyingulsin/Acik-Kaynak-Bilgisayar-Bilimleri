`define DELAY 20
module _32bit_adder_testbanch();
reg [31:0] a, b;
reg carry_in;
wire [31:0] sum;
wire carry_out;

// TTT stands for twenty two bit adder testbench
_32bit_adder TTT(sum, carry_out, a, b, carry_in);

initial begin
a = 32'hFFFFFFFF; b = 32'hFFFFFFFF; carry_in = 1'b0;
#`DELAY;
a = 32'h05453FAF; b = 32'h00000001; carry_in = 1'b1;
#`DELAY;
a = 32'h00000001; b = 32'h00000001; carry_in = 1'b1;
#`DELAY;
a = 32'h00000001; b = 32'h00000001; carry_in = 1'b0;
end

initial
begin
$monitor("time = %2d, a =%8h, b=%8h, carry_in=%1b, sum=%8h, carry_out=%1b", $time, a, b, carry_in, sum, carry_out);
end
 
endmodule   