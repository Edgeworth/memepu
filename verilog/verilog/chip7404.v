module chip7404(
    input logic [6:0]  A,
    output logic [6:0] Y
);

    always_comb begin
        Y = ~A;
    end

endmodule
