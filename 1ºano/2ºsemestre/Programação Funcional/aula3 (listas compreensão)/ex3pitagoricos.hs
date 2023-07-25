pitagoricos :: Integer -> [(Integer,Integer,Integer)]
pitagoricos n = [(x,y,z) | x <- [1..n], y <- [1..n], z <- [1..n], z^2 == x^2 + y^2]
