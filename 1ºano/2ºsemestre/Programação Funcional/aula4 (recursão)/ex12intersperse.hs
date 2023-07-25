intersperse :: a -> [a] -> [a]
intersperse c [] = []
intersperse c (x:[]) = (x:[])
intersperse c (x:xs) = x : c : intersperse c xs
