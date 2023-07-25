fromBits :: [Int] -> Int
fromBits [] = 0
fromBits (x : xs) = x * 2 ^ (length xs) + fromBits xs
