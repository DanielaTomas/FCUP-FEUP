-- a)
binom :: Integer -> Integer -> Integer
binom n k = div (product [1..n]) ((product [1..k])*(product [1..(n-k)]))

-- b)
binom' :: Integer -> Integer -> Integer
binom' n k = product [1+n-k..n] `div` product [1..k]

{-
binom'' :: Integer -> Integer -> Integer
binom'' n k = if(k < (n-k))
              then div (product[n-k+1..n]) (product [1..k])
              else div (product[k+1..n]) (product [1..(n-k)])
-}
