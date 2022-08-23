module data_memory(read_data, address, write_data, mem_read, mem_write, clk);

output reg [31:0] read_data; // assigned as reg since it will be used in @always
input [31:0] write_data;
input [7:0] address; // address is 8 bits since there is a 256 line
input mem_write, mem_read, clk;

// memory - size is 256 because instruction provided a 256 * 32 bit memory
reg [31:0] mem [256:0];

always @(*) begin
    if (mem_read) begin
        read_data <= mem[address];
    end
end

always @(posedge clk) begin
    if (mem_write) begin
        mem[address] <= write_data;
    end
end
    
endmodule