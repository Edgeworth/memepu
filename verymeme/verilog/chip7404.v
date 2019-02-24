module chip7404(
    input /*u*/ wire [5:0] A,
    output /*u*/ wire [5:0] Y
);

    assign Y = ~A;

    `ifdef FORMAL
    always_comb begin
        assert (Y == ~A);
    end
    `endif
endmodule
