-- a)
merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge x [] = x
merge [] y = y
merge (x:xs) (y:ys) | x <= y    = x : merge xs (y:ys)
                    | otherwise = y : merge (x:xs) ys

-- b)
msort :: Ord a => [a] -> [a]
msort [] = []
msort [x] = [x]
msort xs = merge (msort m1) (msort m2)
             where (m1,m2) = metades xs

metades :: [a] -> ([a], [a])
metades lista = (take x lista, drop x lista)
        where x = div (length lista) 2
