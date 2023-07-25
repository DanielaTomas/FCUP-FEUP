maximo :: IO()
maximo = do xs <- maximo'
            putStrLn (show (maximum (xs)))

maximo' :: IO [Int]
maximo' = do x <- getLine
             let n = read x in
               if n == 0 then
                    return []
               else do xs <- maximo'
                       return (n:xs)
