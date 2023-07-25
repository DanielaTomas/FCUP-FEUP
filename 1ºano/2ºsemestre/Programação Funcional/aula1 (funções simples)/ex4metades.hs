metades :: [a] -> ([a], [a])
metades lista = (take x lista, drop x lista)
        where x = div (length lista) 2

-- metades [1,2,3,4,5,6,7,8] == ([1,2,3,4], [5,6,7,8])
