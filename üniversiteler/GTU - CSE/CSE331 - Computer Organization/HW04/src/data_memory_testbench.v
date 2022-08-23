`define DELAY 20
module data_memory_testbench();

wire [31:0] read_data;
reg [31:0] write_data, address;
reg mem_read, mem_write, clk;

data_memory data_mem(read_data, address, write_data, mem_read, mem_write, clk);

always @(*) begin
    #`DELAY clk = ~clk;
end

initial begin
// ! you should change file destination!

$readmemb("D:\\Courses\\CSE331 - Computer Organization\\HWs\\#3\\Oguz_Muhammed_1801042634_restored\\data.mem", data_mem.mem);

clk = 1'b0;
// mem_read = 1;
write_data = 32'h0000_0000; // does not metter when mem_write = 0 
address = 8'b0000_0001; // read 1st address
mem_read = 1'b1; mem_write = 1'b0;
#`DELAY;
// mem_write = 1
write_data = 32'hFFFF_FFFF;
address = 32'b0000_0010; // write 2nd address
mem_read = 1'b0; mem_write = 1'b1;
#`DELAY;
// both of them 0
write_data = 32'h0000_0000; // does not metter when mem_write = 0
address = 8'b0;
mem_read = 1'b0; mem_write = 1'b0;

// ! you should change file destination!
$writememb("D:\\Courses\\CSE331 - Computer Organization\\HWs\\#4\\Oguz_Muhammed_1801042634_restored\\data_memory_out.mem", data_mem.mem);
end

initial begin
$monitor("time=%2d, address=%2d, write_data=%32b, read_data=%32b, mem_read=%1b,  mem_write=%1b, clk=%1b",$time,address, write_data, read_data, mem_read, mem_write, clk);
end

endmodule