module instruction_memory(instruction, read_address, clk);

// since our MiniMisp is supported for 16-bit instructions, we need to do like this
output reg [15:0] instruction; // assigned as reg since it will be used in @always
input [7:0] read_address; // 8 bits  enough since we have 256 instructions
input clk;

// each instruction 16-bits and I assume that there will be 256 instructions
reg [31:0] mem[255:0];

always @(posedge clk) begin
    instruction <= mem[read_address];
end

endmodule