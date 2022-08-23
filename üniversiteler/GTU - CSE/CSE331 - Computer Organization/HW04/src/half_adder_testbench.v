`define DELAY 20
module half_adder_testbench(); 
reg a, b;
wire sum, carry_out;

half_adder hatb (sum, carry_out, a, b);

initial begin
a = 1'b0; b = 1'b0;
#`DELAY;
a = 1'b1; b = 1'b0;
#`DELAY;
a = 1'b0; b = 1'b1;
#`DELAY;
a = 1'b1; b = 1'b1;
end
 
 
initial
begin
$monitor("time = %2d, a =%1b, b=%1b, sum=%1b, carry_out=%1b", $time, a, b, sum, carry_out);
end

initial begin
$monitor("time = %2d, a =%4b, b=%4b, carry_in=%1b, sum=%4b, carry_out=%1b", $time, a, b, carry_in, sum, carry_out);
end
 
endmodule