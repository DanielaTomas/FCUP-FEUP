-- condicionais
safetail :: [a] -> [a]
safetail x = if(length x == 0) then [] else tail x

-- guardas
safetail1 :: [a] -> [a]
safetail1 x | length x == 0 = []
            | otherwise = tail x

-- padrões
safetail2 :: [a] -> [a]
safetail2 [] = []
safetail2 (x:xs) = xs
