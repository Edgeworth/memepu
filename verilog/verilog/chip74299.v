module chip74299(
//    input logic [2:0]  S,
//    input logic [2:0]  N_OE,
    input              N_MR,
//    input              DSR,
//    input              DSL,
    input              CP,
    output logic [8:0] IO
);
    initial begin
        if (N_MR == 0)
            IO = 0;
    end

    always_ff @(posedge CP or edge N_MR) begin
        if (N_MR == 0)
            IO <= 0;
        else
            IO <= 55;
    end

endmodule
