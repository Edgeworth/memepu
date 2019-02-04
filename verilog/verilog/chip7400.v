module chip7400(
    input logic [3:0]  A,
    input logic [3:0]  B,
    output logic [3:0] Y
);

    always_comb begin
        Y = ~(A & B);
    end

endmodule
