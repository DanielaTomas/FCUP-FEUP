nub :: Eq a => [a] -> [a]
nub [] = []
nub (x:xs) = x : nub(apaga x xs)
        where apaga c l = [ y | y <- l, y /= c ]
