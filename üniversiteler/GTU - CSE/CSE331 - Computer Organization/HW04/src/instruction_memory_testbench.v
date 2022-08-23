`define DELAY 20
module instruction_memory_testbench();

wire [15:0] instruction;
reg [7:0] read_address;
reg clk;

instruction_memory ins_mem(instruction, read_address, clk);

initial begin
// ! you should change file destination!

// read file
$readmemb("D:\\Courses\\CSE331 - Computer Organization\\HWs\\#4\\Oguz_Muhammed_1801042634_restored\\data.mem", ins_mem.mem);


read_address = 8'b0000_0001; // read instruction at address 1
clk = 1'b0;
#`DELAY;
clk = ~clk;
#`DELAY;

read_address = 8'b0000_0010; // read instruction at address 2
clk = ~clk;
#`DELAY;
clk = ~clk;
#`DELAY;

read_address = 8'b0000_0011; // read instruction at address 3
clk = ~clk;
#`DELAY;
clk = ~clk;

end

initial begin
$monitor("time=%2d, read_address=%2d, instruction=%16b, clk=%1b",$time, read_address, instruction, clk);
end
endmodule