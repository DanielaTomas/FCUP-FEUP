dropSpace :: String -> String
dropSpace s = dropWhile espaco s
         where espaco c = c == ' '

takeWord :: String -> (String,String)
takeWord s = (palavra,resto)
       where
         nesp c  = c /= ' '
         palavra = takeWhile nesp (dropSpace s)
         resto   = dropWhile nesp (dropSpace s)

palavras :: String -> [String]
palavras "" = []
palavras s | dropSpace s == "" = []
           | otherwise = palavra1 : outraspalavras
         where
           (palavra1,resto) = takeWord s
           outraspalavras   = palavras (dropSpace resto)

{-
palavras :: String -> [String]
palavras "" = []
palavras (x:xs) = primeira : palavras resto
              where
                aux x = x /= ' '
                primeira = takeWhile aux (dropSpace (x:xs))
                resto   = dropWhile aux (dropSpace (x:xs))
                -}
