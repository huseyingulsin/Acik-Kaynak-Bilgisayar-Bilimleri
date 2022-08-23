module _32bit_or (result, a, b);
input [31:0] a,b;
output [31:0] result;

// this lines are a bit hardcoded but I don't know how to do it better

or or0 (result[0], a[0], b[0]);
or or1 (result[1], a[1], b[1]);
or or2 (result[2], a[2], b[2]);
or or3 (result[3], a[3], b[3]);
or or4 (result[4], a[4], b[4]);
or or5 (result[5], a[5], b[5]);
or or6 (result[6], a[6], b[6]);
or or7 (result[7], a[7], b[7]);
or or8 (result[8], a[8], b[8]);
or or9 (result[9], a[9], b[9]);
or or10 (result[10], a[10], b[10]);
or or11 (result[11], a[11], b[11]);
or or12 (result[12], a[12], b[12]);
or or13 (result[13], a[13], b[13]);
or or14 (result[14], a[14], b[14]);
or or15 (result[15], a[15], b[15]);
or or16 (result[16], a[16], b[16]);
or or17 (result[17], a[17], b[17]);
or or18 (result[18], a[18], b[18]);
or or19 (result[19], a[19], b[19]);
or or20 (result[20], a[20], b[20]);
or or21 (result[21], a[21], b[21]);
or or22 (result[22], a[22], b[22]);
or or23 (result[23], a[23], b[23]);
or or24 (result[24], a[24], b[24]);
or or25 (result[25], a[25], b[25]);
or or26 (result[26], a[26], b[26]);
or or27 (result[27], a[27], b[27]);
or or28 (result[28], a[28], b[28]);
or or29 (result[29], a[29], b[29]);
or or30 (result[30], a[30], b[30]);
or or31 (result[31], a[31], b[31]);

endmodule