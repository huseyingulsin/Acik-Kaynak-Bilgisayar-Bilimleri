`define DELAY 20
module MiniMIPS_testbench();

wire [31:0] result;
reg [15:0] instruction;
reg clk;

MiniMIPS myMisp(result, instruction, clk);

initial begin
// ! you should change file destination!

//$readmemb("D:\\Courses\\CSE331 - Computer Organization\\HWs\\#4\\Oguz_Muhammed_1801042634_restored\\data.mem", myMisp.data.mem);

$readmemb("D:\\Courses\\CSE331 - Computer Organization\\HWs\\#4\\Oguz_Muhammed_1801042634_restored\\reg.mem", myMisp.regist.registers);


instruction = 16'b0000_011_101_100_001;  // s3 = s1 + s2
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0000_011_101_100_010;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0000_011_101_100_100;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0000_011_101_100_011;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0000_011_101_100_111;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0000_011_101_100_110;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0000_011_101_100_101;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0000_011_101_100_000;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0010_011_101_100_111;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b1010_011_101_100_110;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0110_011_101_100_101;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b1110_011_101_100_000;
clk = 1'b0; #`DELAY; clk = 1'b1; #`DELAY;
instruction = 16'b0110_011_101_110_011;
clk = 1'b0; #`DELAY; clk = 1'b1;


//or you can take instructions from file
//readmemb("filename", instruction_set);

//for memory file read & write using followings
//$readmemb("registers.mem", mipsMOdulename.registerModuleName.registers);
//$writememb("registers_outp.mem", mipsMOdulename.registerModuleName.registers);

//Continue for all instruction types 
//Must be least 15*2=30 control lines (There must be at least 2 tests for each instruction)
//You can change the inside of the register.mem file as desired.

//end of the running, output files must be created/updated (register file & data file)

end

initial begin
$monitor("time=%2d, instruction=%16b, result=%32b, clk=%1b",$time, instruction, result, clk);
end


endmodule