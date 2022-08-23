module register(read_data1, read_data2, write_data, read_reg1, read_reg2, write_reg, reg_write, clk);

output reg[31:0] read_data1, read_data2;
input [31:0] write_data;
input [2:0] read_reg1, read_reg2, write_reg; // they are 3bits since hw says that the register address is 3 bits
input reg_write, clk;

// there are 8 registers with 32 bits each
reg [31:0] registers[7:0];

always @(*) begin
    read_data1 <= registers[read_reg1];
    read_data2 <= registers[read_reg2];
end

// write to register when only clk is at negative edge
always @(negedge clk) begin
    if (reg_write) begin
        registers[write_reg] <= write_data;
    end
end

endmodule