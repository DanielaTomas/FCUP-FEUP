binom :: Integer -> Integer -> Integer
binom n k = product [1+n-k..n] `div` product [1..k]

--definicao errada/incompleta
--pascal :: Integer -> [[Integer]]
--pascal 0 = [[1]]
--pascal n = (pascal (n-1)) ++ [[binom n k | k <- [1..n]]]

pascal :: Integer -> [[Integer]]
pascal n = [[binom l k | k <- [0..l]] | l <- [0..n]]
