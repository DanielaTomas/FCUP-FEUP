-- a)
curta :: [a] -> Bool
curta x | length x < 3 = True
        | otherwise = False

-- b)
curta' :: [a] -> Bool
curta' [] = True
curta' [_] = True
curta' [_,_] = True
curta' x = False
