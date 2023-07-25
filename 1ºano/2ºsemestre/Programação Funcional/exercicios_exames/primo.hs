primo :: Integer -> Bool
primo n = (length [x | x <- [1..floor((sqrt (fromIntegral n)))] , mod n x == 0]) == 1

gemeos :: Integer -> (Integer, Integer)
gemeos n = head ([(x,x+2) | x <- [n..], primo x, primo (x+2)])
