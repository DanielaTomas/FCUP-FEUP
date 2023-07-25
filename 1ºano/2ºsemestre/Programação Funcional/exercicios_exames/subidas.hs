subidas :: [Float] -> Int
subidas [] = 0
subidas [x] = 0
subidas (x:y:xs) | length (x:y:xs) <= 2 = 0
                 | otherwise = soma (x:y:xs)

soma :: [Float] -> Int
soma [] = 0
soma [x] = 0
soma (x:y:xs) | x < y = 1 + soma (y:xs)
            | otherwise = soma (y:xs)
