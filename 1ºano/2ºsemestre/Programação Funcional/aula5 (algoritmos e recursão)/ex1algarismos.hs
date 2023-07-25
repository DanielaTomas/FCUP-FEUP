algarismosRev :: Int -> [Int]
algarismosRev n | n < 0  = error "número negativo"
                | n < 10 = [n]
                | otherwise = m : algarismosRev d
                       where m = mod n 10
                             d = div n 10

algarismos :: Int -> [Int]
algarismos n = reverse (algarismosRev n)
