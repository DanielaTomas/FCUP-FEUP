mindiv :: Integer -> Integer
mindiv x
     let xfloat = (fromInteger x) :: Float in
     let xsqrt = sqrt xfloat in
     let xsqrti = round xsqrt in
       head ([ d | d <- [2..xsqrti], x `mod` d == 0] ++ [x])

isprime x = mindiv x == x
