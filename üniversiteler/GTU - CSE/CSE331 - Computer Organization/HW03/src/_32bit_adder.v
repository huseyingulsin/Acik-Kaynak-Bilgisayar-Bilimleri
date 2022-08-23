module _32bit_adder(sum, carry_out, a, b, carry_in);
input [31:0] a, b;
input carry_in;
output [31:0] sum;
output carry_out;
wire carry_temp1, carry_temp2, carry_temp3;

_8bit_adder EA1(sum[7:0], carry_temp1, a[7:0], b[7:0], carry_in),
            EA2(sum[15:8], carry_temp2, a[15:8], b[15:8], carry_temp1),
            EA3(sum[23:16], carry_temp3, a[23:16], b[23:16], carry_temp2),
            EA4(sum[31:24], carry_out, a[31:24], b[31:24], carry_temp3);

endmodule