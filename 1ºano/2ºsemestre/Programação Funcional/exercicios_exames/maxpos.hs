maxpos :: [Int] -> Int
maxpos [] = 0
maxpos [x] | x <= 0 = 0
           | otherwise = x
maxpos xs | maximum xs <= 0 = 0
          | otherwise = maximum xs
