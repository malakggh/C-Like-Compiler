exp code
t1 = c * 2
t2 = t1 + d
t3 = t2 / y
t4 = a == t3
printing tree
    (CODE
        (FUNC
            foo1
            (ARGS
                (a,b,c,INT)
                (c1,CHAR)
            )
            (RET BOOL)
            (BODY-DONE
                (VAR 
                    res
                    Type: BOOL
                )
                (BLOCK-DONE
                    (VAR 
                        x
                        q
                        Type: CHAR
                    )
                    (VAR 
                        y
                        Type: INT
                    )
                    (VAR 
                        count
                        Type: INT
                    )
                    (VAR 
                        a
                        b
                        c
                        d
                        Type: INT
                    )
                    (=count
                        7)
                    (IF-DONE
                        ( ==
                            a
                            ( /
                                ( +
                                    ( *
                                        c
                                        2
                                    )
                                
                                    d
                                )
                            
                                y
                            )
                        
                        )
                        (BLOCK-DONE
                            (=count
                                1)
                        )
                    
                    )
                )
                (RET res)
            )
        )
        (FUNC
            main
            (ARGS
                NONE
            )
            (RET VOID)
            (BODY-DONE
            )
        )
    )
done printing tree
