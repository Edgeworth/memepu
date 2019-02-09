module chip7404(
    input  [5:0] A,
    output [5:0] Y
);

    always_comb begin
        Y = ~A;
    end

endmodule
