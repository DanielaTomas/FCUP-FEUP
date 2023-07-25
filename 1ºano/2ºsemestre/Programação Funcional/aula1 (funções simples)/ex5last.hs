-- a)
funcaolast1 :: [a] -> a
funcaolast1 lista = head(drop ((length lista) - 1) lista) 

funcaolast2 :: [a] -> a
funcaolast2 lista = head (reverse lista)

-- b)
funcaoinit1 :: [a] -> [a]
funcaoinit1 lista = take ((length lista) - 1) lista

funcaoinit2 :: [a] -> [a]
funcaoinit2 lista = reverse (tail(reverse lista))
