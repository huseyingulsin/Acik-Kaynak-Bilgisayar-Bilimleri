module _32bit_nor(res, a, b);
input [31:0] a,b;
output [31:0] res;

// this lines are a bit hardcoded but I don't know how to do it better

nor nor0 (res[0], a[0], b[0]);
nor nor1 (res[1], a[1], b[1]);
nor nor2 (res[2], a[2], b[2]);
nor nor3 (res[3], a[3], b[3]);
nor nor4 (res[4], a[4], b[4]);
nor nor5 (res[5], a[5], b[5]);
nor nor6 (res[6], a[6], b[6]);
nor nor7 (res[7], a[7], b[7]);
nor nor8 (res[8], a[8], b[8]);
nor nor9 (res[9], a[9], b[9]);
nor nor10 (res[10], a[10], b[10]);
nor nor11 (res[11], a[11], b[11]);
nor nor12 (res[12], a[12], b[12]);
nor nor13 (res[13], a[13], b[13]);
nor nor14 (res[14], a[14], b[14]);
nor nor15 (res[15], a[15], b[15]);
nor nor16 (res[16], a[16], b[16]);
nor nor17 (res[17], a[17], b[17]);
nor nor18 (res[18], a[18], b[18]);
nor nor19 (res[19], a[19], b[19]);
nor nor20 (res[20], a[20], b[20]);
nor nor21 (res[21], a[21], b[21]);
nor nor22 (res[22], a[22], b[22]);
nor nor23 (res[23], a[23], b[23]);
nor nor24 (res[24], a[24], b[24]);
nor nor25 (res[25], a[25], b[25]);
nor nor26 (res[26], a[26], b[26]);
nor nor27 (res[27], a[27], b[27]);
nor nor28 (res[28], a[28], b[28]);
nor nor29 (res[29], a[29], b[29]);
nor nor30 (res[30], a[30], b[30]);
nor nor31 (res[31], a[31], b[31]);


endmodule