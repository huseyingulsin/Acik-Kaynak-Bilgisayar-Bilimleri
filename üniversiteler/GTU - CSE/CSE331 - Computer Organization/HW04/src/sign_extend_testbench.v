`define DELAY 20
module sign_extend_testbench();

wire [31:0] extended;
reg [5:0] num;

sign_extend extend(extended, num);

initial begin

// num with most signifcant bit 1
num = 6'b1011_00;
#`DELAY;
// num with most signifcant bit 0
num = 6'b0101_00;
#`DELAY;
// num with most signifcant bit 1
num = 6'b1111_01;


end

initial begin
$monitor("time=%2d, number=%6b, extended_num=%32b",$time, num, extended);
end

endmodule