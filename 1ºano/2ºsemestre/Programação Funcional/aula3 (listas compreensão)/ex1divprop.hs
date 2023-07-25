divprop :: Integer -> [Integer]
divprop n = [ x | x <- [1..n], mod n x == 0, x < n]
