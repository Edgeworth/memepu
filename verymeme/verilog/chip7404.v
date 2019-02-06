module chip7404(
    input logic [5:0]  A,
    output logic [5:0] Y
);

    always_comb begin
        Y = ~A;
    end

endmodule
