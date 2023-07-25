divprop :: Integer -> [Integer]
divprop n = [x | x <- [1..n], mod n x == 0, x < n]

perfeitos :: Integer -> [Integer]
perfeitos n = [x | x <- [1..n], x == sum (divprop x)]
