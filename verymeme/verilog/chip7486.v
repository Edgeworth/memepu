module chip7486(
    input  [3:0] A,
    input  [3:0] B,
    output [3:0] Y
);

    always_comb begin
        Y = A ^ B;
    end
endmodule