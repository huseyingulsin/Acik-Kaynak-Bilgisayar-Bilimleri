module _4x1Mux(res, a,b,c,d, s0, s1, enable);
input a, b, c, d, s0, s1, enable;
output res;
wire s0_, s1_, temp_res, temp1, temp2, temp3, temp4;

// first take not of s0 and s1
not(s0_, s0);
not(s1_, s1);

// then do the mux
and(temp1, a, s0, s1);
and(temp2, b, s0, s1_);
and(temp3, c, s0_, s1);
and(temp4, d, s0_, s1_);

// then do the or
or(temp_res, temp1, temp2, temp3, temp4);

// then do the enable part (it is necessary for creating 8x1 mux)
and(res, temp_res, enable);

endmodule