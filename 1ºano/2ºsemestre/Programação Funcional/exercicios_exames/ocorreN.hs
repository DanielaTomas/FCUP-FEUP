ocorreN :: Eq a => a -> [a] -> Int -> Bool
ocorreN x l n = length [ y | y <- l, y == x] == n
