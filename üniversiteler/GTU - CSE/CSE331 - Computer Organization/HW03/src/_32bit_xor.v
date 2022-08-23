module _32bit_xor (res, a, b);
input [31:0] a, b;
output [31:0] res;

// this lines are a bit hardcoded but I don't know how to do it better

xor xor0 (res[0], a[0], b[0]);
xor xor1 (res[1], a[1], b[1]);
xor xor2 (res[2], a[2], b[2]);
xor xor3 (res[3], a[3], b[3]);
xor xor4 (res[4], a[4], b[4]);
xor xor5 (res[5], a[5], b[5]);
xor xor6 (res[6], a[6], b[6]);
xor xor7 (res[7], a[7], b[7]);
xor xor8 (res[8], a[8], b[8]);
xor xor9 (res[9], a[9], b[9]);
xor xor10 (res[10], a[10], b[10]);
xor xor11 (res[11], a[11], b[11]);
xor xor12 (res[12], a[12], b[12]);
xor xor13 (res[13], a[13], b[13]);
xor xor14 (res[14], a[14], b[14]);
xor xor15 (res[15], a[15], b[15]);
xor xor16 (res[16], a[16], b[16]);
xor xor17 (res[17], a[17], b[17]);
xor xor18 (res[18], a[18], b[18]);
xor xor19 (res[19], a[19], b[19]);
xor xor20 (res[20], a[20], b[20]);
xor xor21 (res[21], a[21], b[21]);
xor xor22 (res[22], a[22], b[22]);
xor xor23 (res[23], a[23], b[23]);
xor xor24 (res[24], a[24], b[24]);
xor xor25 (res[25], a[25], b[25]);
xor xor26 (res[26], a[26], b[26]);
xor xor27 (res[27], a[27], b[27]);
xor xor28 (res[28], a[28], b[28]);
xor xor29 (res[29], a[29], b[29]);
xor xor30 (res[30], a[30], b[30]);
xor xor31 (res[31], a[31], b[31]);

endmodule