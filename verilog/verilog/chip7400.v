module chip7400(
    input logic [4:0]  A,
    input logic [4:0]  B,
    output logic [4:0] Y
);

    always_comb begin
        Y = ~(A & B);
    end

endmodule
