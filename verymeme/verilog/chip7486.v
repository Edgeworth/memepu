module chip7486(
    input /*u*/ wire [3:0] A,
    input /*u*/ wire [3:0] B,
    output /*u*/ wire [3:0] Y
);

    assign Y = A ^ B;

    `ifdef FORMAL
    always_comb begin
        assert (Y == (A ^ B));
    end
    `endif
endmodule