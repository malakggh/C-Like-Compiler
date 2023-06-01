printing tree
    (CODE
        (FUNC
            main
            (ARGS
                NONE
            )
            (RET VOID)
            (BODY-DONE
                (VAR 
                    i1xpromax1
                    Type: REAL
                )
            )
        )
        (FUNC
            hello
            (ARGS
                (DD2,REAL)
            )
            (RET CHAR)
            (BODY-DONE
                (VAR 
                    i1xpromax2
                    Type: REAL
                )
                (RET 2.0)
            )
        )
        (FUNC
            xoo
            (ARGS
                (AA2,BB2,INT)
                (Asx2,BOOL)
            )
            (RET CHAR)
            (BODY-DONE
                    (FUNC
                        xoo2
                        (ARGS
                            (DD2,REAL)
                        )
                        (RET REAL)
                        (BODY-DONE
                                (FUNC
                                    ret_B
                                    (ARGS
                                        NONE
                                    )
                                    (RET INT)
                                    (BODY-DONE
                                        (RET 1)
                                    )
                                )
                            (VAR 
                                x
                                dx
                                Type: INT
                            )
                            (VAR 
                                i1
                                i3
                                i
                                ioi
                                y
                                ret_b
                                ret_z3
                                Type: REAL
                            )
                            (IF-DONE
                                ( ==
                                    dx
                                    5
                                )
                                (BLOCK-DONE
                                    (FOR
                                        (FOR-INIT
                                            (=i1
                                                0)
                                            ( <
                                                i1
                                                10
                                            )
                                        
                                            (=i3
                                                ( +
                                                    i
                                                    1
                                                )
                                            )
                                        )
                                        (FOR-BLOCK
                                            (BLOCK-DONE
                                                (VAR 
                                                    x
                                                    a
                                                    Type: INT
                                                )
                                                (VAR 
                                                    ioi
                                                    Type: BOOL
                                                )
                                                (=x
                                                    ( +
                                                        2
                                                        a
                                                    )
                                                )
                                            )
                                        
                                        )
                                    )
                                )
                            
                            )
                            (IF-DONE
                                ( ==
                                    x
                                    5
                                )
                                (=ioi
                                    2)
                            
                            )
                            (BLOCK-DONE
                                (VAR 
                                    z
                                    b
                                    a
                                    q
                                    c
                                    ret_z
                                    ret_a
                                    Type: INT
                                )
                                (IF-DONE
                                    ( ==
                                        x
                                        5
                                    )
                                    (RET ( +
        ret_a
        function call ret_B(function call xoo2(),function call xoo(),ret_z,function call xoo())
    )
                                    )
                                
                                )
                                (BLOCK-DONE
                                    (VAR 
                                        ququ
                                        Type: REAL
                                    )
                                    (IF-DONE
                                        ( ==
                                            x
                                            2
                                        )
                                        (BLOCK-DONE
                                            (BLOCK-DONE
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
                                (BLOCK-DONE
                                    (VAR 
                                        ququ_bro2
                                        Type: REAL
                                    )
                                    (=b
                                        function call ret_B(( +
        ( +
            a
            q
        )
    
        2
    )
    ,b,c))
                                )
                            )
                            (RET ( +
        ret_b
        function call ret_B(ret_z3,function call xoo())
    )
                            )
                        )
                    )
                (VAR 
                    abc
                    vb
                    ret_d
                    ret_c
                    l
                    m
                    i
                    Type: INT
                )
                (VAR 
                    k
                    Type: CHAR
                )
                (VAR 
                    x
                    j
                    Type: BOOL
                )
                (IF-DONE
                    ( &&
                        ( ||
                            !
                            ( ==
                                k
                                function call hello()
                            )
                        
                            ( !=
                                x
                                FALSE
                            )
                        
                        )
                    
                        ( <
                            ( +
                                l
                                m
                            )
                        
                            i
                        )
                    
                    )
                    (RET ret_c)
                
                )
                (RET ( +
        ret_d
        function call hello(2)
    )
                )
            )
        )
        (FUNC
            hello4
            (ARGS
                (DD2,REAL)
            )
            (RET REAL)
            (BODY-DONE
                (VAR 
                    i1xpromax
                    Type: REAL
                )
                (RET 2.0)
            )
        )
    )
done printing tree
