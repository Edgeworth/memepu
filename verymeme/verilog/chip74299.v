module chip74299(
    input [1:0] S,
    input [1:0] N_OE,
    input       N_MR,
    input       DSR,
    input       DSL,
    input       CP,
    inout [7:0] IO,
    output      Q0,
    output      Q7,
    // Testing. TODO: Replace with assertions or?
    output      ERR
);
    logic [7:0] shift_reg;

    initial begin
        if (N_MR == 0)
            shift_reg = 0;
    end

    always_comb begin
        Q0 = shift_reg[0];  // Expose shift reg MSB and LSB for chaining.
        Q7 = shift_reg[7];
        if (N_OE == 'b00)
            IO = shift_reg;
        else
            IO = 8'bZ;
    end

    always_ff @(posedge CP or edge N_MR) begin
        if (N_MR == 0)
            shift_reg <= 0;
        else begin
            case (S)
                2'b11:  // Parallel load
                    shift_reg <= IO;
                2'b01: begin  // Shift right (left from MSB is leftmost (datasheet) perspective)
                    shift_reg <= shift_reg << 1;
                    shift_reg[0] <= DSL;
                end
                2'b10: begin  // Shift left (right from MSB is leftmost (datasheet) perspective)
                    shift_reg <= shift_reg >> 1;
                    shift_reg[7] <= DSR;
                end
                2'b00:;  // Hold
            endcase
        end
    end

        // Testing
    always_comb begin
        ERR = 0;
        // Consider outputting while trying to load an error.
        if (N_OE == 'b00 && S == 2'b11)
            ERR = 1;
    end

endmodule
