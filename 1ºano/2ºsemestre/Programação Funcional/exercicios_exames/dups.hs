dups :: [a] -> [a]
dups [] = []
dups [x] = [x,x]
dups (x:y:xs) = x : x : y : (dups xs)
