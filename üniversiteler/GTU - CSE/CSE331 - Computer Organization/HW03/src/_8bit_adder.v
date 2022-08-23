module _8bit_adder(sum, carry_out, a, b, carry_in);
input [7:0] a;
input [7:0] b;
input carry_in;
output [7:0] sum;
output carry_out;
wire carry_temp;

_4bit_adder four_bit_adder1(sum[3:0], carry_temp, a[3:0], b[3:0], carry_in),
            four_bit_adder2(sum[7:4], carry_out, a[7:4], b[7:4], carry_temp);

endmodule