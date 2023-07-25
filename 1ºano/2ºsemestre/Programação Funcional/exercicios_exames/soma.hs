soma :: IO()
soma = do xs <- soma'
          putStrLn(show (sum xs))

soma' :: IO [Int]
soma' = do x <- getLine
           let n = read x in
             if (n == 0) then
                return []
             else do xs <- soma'
                     return (n:xs)
