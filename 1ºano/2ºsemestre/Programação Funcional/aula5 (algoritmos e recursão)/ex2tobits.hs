toBitsRev :: Int -> [Int]
toBitsRev 0 = []
toBitsRev n | n < 0     = error "numero negativo"
            | otherwise = m : toBitsRev d
                        where m = mod n 2
                              d = div n 2

toBits :: Int -> [Int]
toBits n = reverse (toBitsRev n)
