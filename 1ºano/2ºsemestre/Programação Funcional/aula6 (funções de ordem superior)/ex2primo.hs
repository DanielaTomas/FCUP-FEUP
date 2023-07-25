primo' :: Integer -> Bool
primo' n | n > 1     = not (any divide [2..floor (sqrt (fromIntegral n))])
         | otherwise = False
       where divide x = mod n x == 0

--primo :: Integer -> Bool
--primo n = all (any ndivide [2..floor (sqrt (fromIntegral n))])
  --    where ndivide x = mod n x /= 0
