import Stack

calcular :: String -> Integer
calcular s = calcularAux (words s) empty

calcularAux :: [String] -> Stack Integer -> Integer
calcularAux [] stk = top stk
calcularAux (x:xs) stk | x == "+"  = calcularAux xs (push (n1 + n2) rm)
                       | x == "-"  = calcularAux xs (push (n1 - n2) rm)
                       | x == "*"  = calcularAux xs (push (n1 * n2) rm)
                       | x == "/"  = calcularAux xs (push (div n1 n2) rm)
                       | otherwise = calcularAux xs (push (read x) stk)
                       where n1 = top (pop stk)
                             n2 = top stk
                             rm = pop (pop stk)
