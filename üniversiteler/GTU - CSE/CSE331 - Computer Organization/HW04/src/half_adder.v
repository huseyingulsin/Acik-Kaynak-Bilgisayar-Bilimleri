module half_adder(sum, carry_out, a, b);
input a, b;
output sum, carry_out;

xor sum_of_digits(sum, a, b);
and carry_of_sum(carry_out, a, b);

endmodule