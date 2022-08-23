`define DELAY 20
module register_testbench();

wire [31:0] read_data1, read_data2;
reg [31:0] write_data;
reg [2:0] read_reg1, read_reg2, write_reg; // they are 3bits since hw says that the register address is 3 bits
reg reg_write, clk;

register reg_test(read_data1, read_data2, write_data, read_reg1, read_reg2, write_reg, reg_write, clk);

initial begin
// ! you should change file destination!

// read file
$readmemb("D:\\Courses\\CSE331 - Computer Organization\\HWs\\#4\\Oguz_Muhammed_1801042634_restored\\reg.mem", reg_test.registers);

// write enable
// clock at positive edge
read_reg1 = 3'b000; // read from register 0
read_reg2 = 3'b001; // read from register 1
write_reg = 3'b010; // write to register 2
reg_write = 1'b1; // write enable
write_data = 32'b0101_0101_0101_0101_0101_0101_0101_0101; // write data
clk = 1'b1; // clock
#`DELAY;
// clock at negative edge
clk = 1'b0; // clock
#`DELAY;

// write disable
// clock at positive edge
write_reg = 3'b011; // write to register 2
reg_write = 1'b0; // write disable
clk = 1'b1; // clock
#`DELAY;
// clock at negative edge
clk = 1'b0; // clock

// ! you should change file destination!

// write to file to see the result
$writememb("D:\\Courses\\CSE331 - Computer Organization\\HWs\\#4\\Oguz_Muhammed_1801042634_restored\\reg_out.mem",reg_test.registers);
end

initial begin
$monitor("time=%2d, read_reg1=%2d,  read_reg2=%2d,  write_reg=%2d,  write_data=%32b, reg_write=%1b,   read_data1=%32b,   read_data2=%32b ,  clk=%2d "
            ,$time, read_reg1, read_reg2, write_reg, write_data, reg_write, read_data1, read_data2,clk);
end

endmodule