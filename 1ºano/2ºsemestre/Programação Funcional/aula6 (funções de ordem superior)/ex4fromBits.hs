fromBits :: [Int] -> Int
fromBits l = snd (foldr aux (length l - 1,0) l)
         where
           aux :: Int -> (Int,Int) -> (Int,Int)
           aux (e,ac) b = (e-1, ac + 2^e * b)

fromBits :: [Int] -> Int
fromBits l = (foldr aux (0,0) l)
        where
          aux :: Int -> (Int,Int) -> (Int,Int)
          aux b (e,rr) = (e+1, rr + 2^e * b)
