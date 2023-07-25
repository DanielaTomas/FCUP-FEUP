injust :: [Int] -> Int
injust xs = length ([x | x <- xs, x >= 10, x < 15])
