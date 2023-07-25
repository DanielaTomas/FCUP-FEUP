isort :: Ord a => [a] -> [a]
isort [] = []
isort (x:xs) = insert x (isort xs)

isort' l = foldr [] l
