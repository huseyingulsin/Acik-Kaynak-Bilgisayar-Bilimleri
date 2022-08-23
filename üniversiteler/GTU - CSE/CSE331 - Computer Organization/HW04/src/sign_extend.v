module sign_extend(extended_num, num);

output [31:0] extended_num;
input [5:0] num;

// I use and gate to extend the sign bit
// first take content of num and put it in extended_num
// then take the sign bit of num and put it in the sign bit of extended_num
and a0(extended_num[0], num[0], 1'b1);
and a1(extended_num[1], num[1], 1'b1);
and a2(extended_num[2], num[2], 1'b1);
and a3(extended_num[3], num[3], 1'b1);
and a4(extended_num[4], num[4], 1'b1);
and a5(extended_num[5], num[5], 1'b1);

// now extend the sign bit
and a6(extended_num[6], num[5], 1'b1);
and a7(extended_num[7], num[5], 1'b1);
and a8(extended_num[8], num[5], 1'b1);
and a9(extended_num[9], num[5], 1'b1);
and a10(extended_num[10], num[5], 1'b1);
and a11(extended_num[11], num[5], 1'b1);
and a12(extended_num[12], num[5], 1'b1);
and a13(extended_num[13], num[5], 1'b1);
and a14(extended_num[14], num[5], 1'b1);
and a15(extended_num[15], num[5], 1'b1);
and a16(extended_num[16], num[5], 1'b1);
and a17(extended_num[17], num[5], 1'b1);
and a18(extended_num[18], num[5], 1'b1);
and a19(extended_num[19], num[5], 1'b1);
and a20(extended_num[20], num[5], 1'b1);
and a21(extended_num[21], num[5], 1'b1);
and a22(extended_num[22], num[5], 1'b1);
and a23(extended_num[23], num[5], 1'b1);
and a24(extended_num[24], num[5], 1'b1);
and a25(extended_num[25], num[5], 1'b1);
and a26(extended_num[26], num[5], 1'b1);
and a27(extended_num[27], num[5], 1'b1);
and a28(extended_num[28], num[5], 1'b1);
and a29(extended_num[29], num[5], 1'b1);
and a30(extended_num[30], num[5], 1'b1);
and a31(extended_num[31], num[5], 1'b1);


endmodule