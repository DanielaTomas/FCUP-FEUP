aproxPi1 :: Int -> Double
aproxPi1 n = sum (take n (zipWith (/) (cycle[4,-4]) [1,3..]))

aproxPi2 :: Int -> Double
aproxPi2 0 = 0
aproxPi2 n = 3 + sum (zipWith (/) (cycle[4,-4]) (denominadores (n-1)))

produto :: Int -> Double
produto n = fromInteger(toInteger(n*(n+1)*(n+2)))

denominadores :: Int -> [Double]
denominadores n = take n (map produto [2,4..])
