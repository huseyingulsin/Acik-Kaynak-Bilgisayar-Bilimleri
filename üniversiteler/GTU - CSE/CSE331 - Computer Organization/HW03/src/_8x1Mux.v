module _8x1Mux(res, a, b, c, d, e, f, g, h, s0, s1, s2);
input a, b, c, d, e, f, g, h,s0,s1,s2;
output res;
wire s2_, temp0, temp1;

// take s2 not
not(s2_, s2);

// merge 4x1 muxes
_4x1Mux Mux0 (temp0, a, b, c, d, s0, s1, s2);
_4x1Mux Mux1 (temp1, e, f, g, h, s0, s1, s2_);

// take result from temps
or(res, temp0, temp1);

endmodule

