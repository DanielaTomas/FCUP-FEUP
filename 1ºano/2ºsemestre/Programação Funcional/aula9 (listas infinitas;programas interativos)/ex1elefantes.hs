elefantes :: Int -> IO()
elefantes n = sequence_ [iterar x | x <- [2..n-1]]

iterar :: Int -> IO()
iterar n = putStrLn("Se " ++ show(n) ++ " elefantes incomodam muita gente,\n" ++ show(n+1) ++ " elefantes incomodam muito mais!")
