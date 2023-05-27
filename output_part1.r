assignment_st
################# Start of Scope 8888 #####################
Return Type: NONE
Nested Blocks: 0
Nested Functions: 0

---- Variables ----
varArr: [x-NONE, x-NONE, y-NONE, z-NONE]
---- Functions ----
funcsArr: []
################# End of Scope 8888 #######################
assignment_st
################# Start of Scope 8888 #####################
Return Type: NONE
Nested Blocks: 0
Nested Functions: 0

---- Variables ----
varArr: [b-NONE, a-NONE, q-NONE, b-NONE, c-NONE]
---- Functions ----
funcsArr: [{xoo, varArr: [], NONE}]
################# End of Scope 8888 #######################
assignment_st
################# Start of Scope 8888 #####################
Return Type: NONE
Nested Blocks: 0
Nested Functions: 0

---- Variables ----
varArr: [z-NONE, anna-NONE]
---- Functions ----
funcsArr: []
################# End of Scope 8888 #######################
################# Start of Scope 9999 #####################
Return Type: NONE
Nested Blocks: 0
Nested Functions: 0

---- Variables ----
varArr: []
---- Functions ----
funcsArr: [{xoo, varArr: [AA2-INT, BB2-INT, Asx2-BOOL], CHAR}]
################# End of Scope 9999 #######################
stack:
################# Start of Scope 0 #####################
Return Type: CHAR
Nested Blocks: 5
Nested Functions: 1

---- Variables ----
varArr: [AA2-INT, BB2-INT, Asx2-BOOL, abc-INT]
---- Functions ----
funcsArr: [{xoo2, varArr: [DD2-REAL], REAL}]
################# End of Scope 0 #######################
################# Start of Scope 1 #####################
Return Type: REAL
Nested Blocks: 5
Nested Functions: 0

---- Variables ----
varArr: [DD2-REAL, lol-INT, x-INT]
---- Functions ----
funcsArr: []
################# End of Scope 1 #######################
################# Start of Scope 2 #####################
Return Type: NONE
Nested Blocks: 4
Nested Functions: 0

---- Variables ----
varArr: [z-INT]
---- Functions ----
funcsArr: []
################# End of Scope 2 #######################
################# Start of Scope 3 #####################
Return Type: NONE
Nested Blocks: 0
Nested Functions: 0

---- Variables ----
varArr: [ququ_bro2-REAL]
---- Functions ----
funcsArr: []
################# End of Scope 3 #######################
################# Start of Scope 4 #####################
Return Type: NONE
Nested Blocks: 2
Nested Functions: 0

---- Variables ----
varArr: [ququ-REAL]
---- Functions ----
funcsArr: []
################# End of Scope 4 #######################
################# Start of Scope 5 #####################
Return Type: NONE
Nested Blocks: 1
Nested Functions: 0

---- Variables ----
varArr: []
---- Functions ----
funcsArr: []
################# End of Scope 5 #######################
################# Start of Scope 6 #####################
Return Type: NONE
Nested Blocks: 0
Nested Functions: 0

---- Variables ----
varArr: []
---- Functions ----
funcsArr: []
################# End of Scope 6 #######################
printing tree
    (CODE
        (FUNC
            xoo
            (ARGS
                (AA2,BB2,INT)
                (Asx2,BOOL)
            )
            (RET CHAR)
            (BODY
                    (FUNC
                        xoo2
                        (ARGS
                            (DD2,REAL)
                        )
                        (RET REAL)
                        (BODY
                            (VAR 
                                lol
                                Type: INT
                            )
                            (VAR 
                                x
                                Type: INT
                            )
                            (IF
                                ( ==
                                    x
                                    5
                                )
                                (RET 1)
                            
                            )
                            (BLOCK
                                (VAR 
                                    z
                                    Type: INT
                                )
                                (IF
                                    ( ==
                                        x
                                        5
                                    )
                                    (RET 1)
                                
                                )
                                (BLOCK
                                    (VAR 
                                        ququ
                                        Type: REAL
                                    )
                                    (IF
                                        ( ==
                                            x
                                            2
                                        )
                                        (BLOCK
                                            (BLOCK
                                                (=x
                                                    ( -
                                                        x
                                                        ( /
                                                            ( *
                                                                y
                                                                z
                                                            )
                                                        
                                                            3
                                                        )
                                                    
                                                    )
                                                )
                                            )
                                        )
                                    
                                    )
                                )
                                (BLOCK
                                    (VAR 
                                        ququ_bro2
                                        Type: REAL
                                    )
                                    (=b
                                        function call xoo(( +
        ( +
            a
            q
        )
    
        2
    )
    ,b,c))
                                    (=z
                                        anna)
                                )
                            )
                            (RET 0)
                        )
                    )
                (VAR 
                    abc
                    Type: INT
                )
                (IF
                    ( ==
                        x
                        5
                    )
                    (RET 1)
                
                )
                (RET 0)
            )
        )
    xoo)
done printing tree
